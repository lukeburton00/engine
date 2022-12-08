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
        window = SDL_CreateWindow( "Hello OpenGL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, flags);
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }

        else
        {
            printf("Creating OpenGL context...\n");
            glContext = SDL_GL_CreateContext(window);
            printf("OpenGL context created!\n\n");
        }

        printf("Initializing GLEW...\n");

        glewExperimental = GL_TRUE;
        glewInit();

        printf("GLEW initialized!\n\n");

    }
	
	if (renderComponents.size() > 0)
	{
		for (int i = 0; i < renderComponents.size(); i++)
		{
			cout << "Building VAO for component: " << renderComponents[i]->id << endl;
			buildVAO(renderComponents[i]);
			buildShaderProgram(renderComponents[i]);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
		}
	}
	
	else
	{
		printf("No renderComponents to prepare");
	}
	
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

void RenderSystem::Render()
{
	if (VAOs.size() > 0)
	{
		for (int i = 0; i < VAOs.size(); i++)
		{
			Draw(VAOs[i], shaderPrograms[i]);
		}
		SDL_GL_SwapWindow(window);
	}
	
	else
	{
		return;
	}
}

void RenderSystem::Draw(GLuint VAO, GLuint shaderProgram)
{
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	
	cout << "Shader program in use: " << shaderProgram << endl;
	cout << "VAO in use: " << VAO << endl;
	
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}

GLuint RenderSystem::buildVAO(RenderComponent * renderComponent)
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
	VAOs.push_back(vertexArrayObject);

	return vertexArrayObject;
}

GLuint RenderSystem::buildShaderProgram(RenderComponent * renderComponent)
{
	const GLchar * vertexSource = renderComponent->vertexSource;
	const GLchar * fragmentSource = renderComponent->fragmentSource;
	
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);
	
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, renderComponent->vertexDataSize, GL_FLOAT, GL_FALSE, 0, 0);
	
	shaderPrograms.push_back(shaderProgram);
	
	return shaderProgram;
}


