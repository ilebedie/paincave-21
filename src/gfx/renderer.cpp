#include "renderer.h"
#include <iostream>
#include <filesystem>
#include <fstream>

std::string read_shader_file(const std::string file_path)
{
    const auto fsize = std::filesystem::file_size(file_path);
    std::ifstream in(file_path, std::ios::binary);
	std::string contents('0',fsize);
	in.read(&contents[0], contents.size());
	in.close();
	return contents;
}

void load_shaders()
{
    const auto vs_path = "res/shaders/default.vs";
    auto vs_code = read_shader_file(vs_path);
    std::cout<<"vs code: "<<vs_code<<std::endl;
    // const auto fs_path = "res/shaders/default.fs";
}

Renderer::Renderer()
{
    load_shaders();

}

void Renderer::update()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}