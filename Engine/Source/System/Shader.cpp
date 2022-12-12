#include "Render/Shader.hpp"

Shader::Shader(const char * vertexPath, const char * fragmentPath)
{
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vertexShaderFile;
	std::ifstream fragmentShaderFile;
	
	vertexShaderFile.open(vertexPath);
	fragmentShaderFile.open(fragmentPath);
	
	std::stringstream vertexShaderStream, fragmentShaderStream;
	
	vertexShaderStream << vertexShaderFile.rdbuf();
	fragmentShaderStream << fragmentShaderFile.rdbuf();
	
	vertexShaderFile.close();
	fragmentShaderFile.close();
		
	vertexCode = vertexShaderStream.str();
	fragmentCode = fragmentShaderStream.str();
	
	const char * vertexSource = vertexCode.c_str();
	const char * fragmentSource = fragmentCode.c_str();
	
	int success;
	char infoLog[512];
	
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	};
	
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	};
	
	// shader Program
	id = glCreateProgram();
	glAttachShader(id, vertexShader);
	glAttachShader(id, fragmentShader);
	glLinkProgram(id);
	// print linking errors if any
	glGetProgramiv(id, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(id, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	  
	// delete the shaders as they're linked into our program now and no longer necessary
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::use()
{
	glUseProgram(id);
}

void Shader::setBool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const
{
	glUniform1f(glGetUniformLocation(id, name.c_str()), value);
}
