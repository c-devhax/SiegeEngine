#include <OpenGLUtils.hpp>

#include <GL/glew.h>
#include <stdio.h>

void Siege::GLClearError() {
    while (glGetError() != GL_NO_ERROR);
}

bool Siege::GLLogCall(const char* function, const char* file, int line) {
    bool found_err = false;
    GLenum error = glGetError();
    while (error != GL_NO_ERROR) {
        fprintf(stderr, "[Siege::Renderer] [OpenGL Error] (%d): %s %s:%d\n", error, function, file, line);
        error = glGetError();
    }
    return !found_err;
}