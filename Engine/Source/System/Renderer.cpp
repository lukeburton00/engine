#include "Renderer.hpp"

bool Renderer::Initialize(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT, const Uint32& flags)
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
    printf("Renderer initialized!\n\n");
    return success;
}

void Renderer::Shutdown()
{
    printf("\nShutting down renderer...\n");
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_GL_DeleteContext(glContext);
    SDL_Quit();
    printf("Renderer has shut down.\n\n");
}

void Renderer::Render()
{
    glDrawArrays(GL_TRIANGLES, 0, 3);
    SDL_GL_SwapWindow(window);
}

void Renderer::LoadTriangle()
{
    GLuint vertexArrayObject;
    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);

    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);

    GLfloat vertices[] =
    {
        0.0f, 0.5f, 0.0f, // vertex 1
        0.5f, -0.5f, 0.0f, // vertex 2
        -0.5f, -0.5f, 0.0f// vertex 3
    };

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    const GLchar * vertexSource = R"glsl(
    #version 330 core
    in vec2 position;
    void main()
    {
        gl_Position = vec4(position, 0.0, 1.0);
    })glsl";

    const GLchar * fragmentSource = R"glsl(
    #version 330 core
    out vec4 outColor;
    void main()
    {
        outColor = vec4(1.0, 1.0, 1.0, 1.0);
    })glsl";

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
    glUseProgram(shaderProgram);
	
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0);

}
