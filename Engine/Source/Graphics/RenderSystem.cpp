#include "RenderSystem.hpp"

bool RenderSystem::Initialize(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT, const Uint32& flags)
{
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
		prepareQuad();
    }
	
    return success;
}

void RenderSystem::Shutdown()
{
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_GL_DeleteContext(glContext);
    SDL_Quit();
}

void RenderSystem::Render()
{
	glm::vec3 color = glm::vec3(0.0f, 0.0f, 0.0f);
	glClearColor(color.x, color.y, color.z, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glUseProgram(quadShader);
	glBindVertexArray(vertexArrayObject);
	
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindBuffer(GL_VERTEX_ARRAY, 0);
	
	SDL_GL_SwapWindow(window);
}

void RenderSystem::prepareQuad()
{
	GLfloat vertices[] =
	{
		0.5f,  0.5f, 0.0f, // top right
		0.5f, -0.5f, 0.0f, // bottom right
		-0.5f, -0.5f, 0.0f, // bottom left
		-0.5f,  0.5f, 0.0f // top left
	};
	
	GLuint indices[] =
	{
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};
	
	Shader shader("triangleVertexShader.vs", "triangleFragmentShader.fs");
	quadShader = shader.id;
	
	VAO VAO1;
	VAO1.Bind();
	
	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));
	
	VAO1.LinkVBO(VBO1, 0);
	vertexArrayObject = VAO1.mId;
	
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();
}

void RenderSystem::toggleWireFrame()
{
	if (wireFrameEnabled)
	{
		wireFrameEnabled = false;
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	
	else
	{
		wireFrameEnabled = true;
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
}
