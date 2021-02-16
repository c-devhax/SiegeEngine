#pragma once

#include <signal.h>

#define GLCall(x) \
    GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))
#define ASSERT(x) if (!(x)) raise(SIGTRAP); 

namespace Siege {
    void GLClearError();
    bool GLLogCall(const char* function, const char* file, int line);
}