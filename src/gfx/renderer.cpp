#include "renderer.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <cmath>

std::string read_shader_file(const std::string file_path)
{
    const auto fsize = std::filesystem::file_size(file_path);
    std::ifstream in(file_path, std::ios::binary);
    // TODO: take a look at this abomination later
    std::string contents;
    contents.resize(fsize);
    in.read(&contents[0], contents.size());
    in.close();
    return contents;
}

Renderer::Renderer()
{
    const auto vs_path = "res/shaders/default.vs";
    this->shaders_source_code.defaultVertexShader = read_shader_file(vs_path);
    const char* vertexSource = this->shaders_source_code.defaultVertexShader.c_str();
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, nullptr);
    glCompileShader(vertexShader);

    const auto fs_path = "res/shaders/default.fs";
    this->shaders_source_code.defaultFragmentShader = read_shader_file(fs_path);
    const char* fragmentSource = this->shaders_source_code.defaultFragmentShader.c_str();
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

	shader_program = glCreateProgram();
	glAttachShader(shader_program, vertexShader);
	glAttachShader(shader_program, fragmentShader);
	// Wrap-up/Link all the shaders together into the Shader Program
	glLinkProgram(shader_program);

	// Delete the now useless Vertex and Fragment Shader objects
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

    GLfloat vertices[] = {
        -0.5f, -0.5f * float(std::sqrt(3)) / 3, 0.0f,
        0.5f, -0.5f * float(std::sqrt(3)) / 3, 0.0f,
        0.0f, 0.5f * float(std::sqrt(3)) * 2 / 3, 0.0f,
    };

}

void Renderer::update()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}