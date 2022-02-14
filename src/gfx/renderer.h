#ifndef RENDERER_H
#define RENDERER_H

#include "gfx.h"
#include <string>

struct ShadersSourceCode
{
    std::string defaultVertexShader;
    std::string defaultFragmentShader;
};


struct Renderer
{
    GLuint shader_program;
    ShadersSourceCode shaders_source_code;
    Renderer();
    ~Renderer();
    void update();
    void init_shaders();

    GLuint VAO, VBO;
};

#endif