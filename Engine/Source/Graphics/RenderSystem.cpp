#include "RenderSystem.hpp"

bool RenderSystem::Initialize(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT, const Uint32& flags)
{
    printf("Initializing renderer...\n\n");
    screenSurface = NULL;
    window = NULL;
    bool success = true;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL video could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }

    else
    {
        //Set OpenGL attributes for perfomance and compatibility
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

        //Create window
        window = SDL_CreateWindow( "Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, flags);
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }

        else
        {
            glContext = SDL_GL_CreateContext(window);
        }

        glewExperimental = GL_TRUE;
        glewInit();

    }
	
	if (renderComponents.size() > 0)
	{
		for (int i = 0; i < renderComponents.size(); i++)
		{
			std::cout << "Building VAO for component: " << renderComponents[i]->id << std::endl;
			buildVAO(renderComponents[i]);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
		}
	}
	
	else
	{
		printf("No renderComponents to prepare.\n\n");
	}
	
	Shader triangleShader( "triangleVertexShader.vs", "triangleFragmentShader.fs" );
	addShader(triangleShader);
	
    printf("Renderer initialized!\n\n");
	
    return success;
}

void RenderSystem::Shutdown()
{
    printf("\nShutting down renderer...\n");
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_GL_DeleteContext(glContext);
    SDL_Quit();
    printf("Renderer has shut down.\n\n");
}

void RenderSystem::addRenderComponent(RenderComponent *renderComponent)
{
	renderComponents.push_back(renderComponent);
}

void RenderSystem::removeRenderComponent(RenderComponent *renderComponent)
{
	renderComponents.erase(remove(renderComponents.begin(), renderComponents.end(), renderComponent));
}

void RenderSystem::Render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	if (VAOs.size() > 0 && shaders.size() > 0)
	{
		for (int i = 0; i < VAOs.size(); i++)
		{
			Draw(VAOs[i], shaders[i]);
		}
		SDL_GL_SwapWindow(window);
	}
	
	else
	{
		return;
	}
}

void RenderSystem::Draw(GLuint VAO, Shader shader)
{
	shader.use();
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}

void RenderSystem::buildVAO(RenderComponent * renderComponent)
{
	GLulong arrLength = renderComponent->vertices.size();
	GLfloat vertices[arrLength];
	
	for (int i = 0; i < arrLength; i++)
	{
		vertices[i] = renderComponent->vertices[i];
	}
	
	GLuint vertexArrayObject = renderComponent->id;
	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	
	VAOs.push_back(vertexArrayObject);
	
	glBindVertexArray(0);
}

void RenderSystem::addShader(Shader shader)
{
	shaders.push_back(shader);
}

void RenderSystem::handleTexture()
{
	int width, height, nrChannels;
	unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
	
	unsigned int texture;
	glGenTextures(1, &texture);
	
	glBindTexture(GL_TEXTURE_2D, texture);
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	
	stbi_image_free(data);
}
