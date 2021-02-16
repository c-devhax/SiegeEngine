#define GLEW_STATIC
#include <GL/glew.h>
#include <Renderer.hpp>
#include <OpenGLUtils.hpp>

Siege::Renderer::Renderer(const Siege::Dimension_t& dimensions, const std::string& title, const Vec2<uint8_t>& glVersion)
    : m_ViewPortDimensions(dimensions), OpenGL_Info_Version(glVersion) {

    // initialize GLFW and window
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, glVersion.x);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, glVersion.y);
    
    if (!glfwInit()) {
        throw std::runtime_error("[Siege::Renderer] Could not initialize GLFW.");
    }
    window = glfwCreateWindow(m_ViewPortDimensions.x, m_ViewPortDimensions.y, title.c_str(), NULL, NULL);
    if (!window) {
        throw std::runtime_error("[Siege::Renderer] Could not create window.");
    }
    glfwMakeContextCurrent(window);
    // initialize GLEW
    if (glewInit() != GLEW_OK) {
        throw std::runtime_error("[Siege::Renderer] Could not initialize GLEW.");
    }
}

Siege::Renderer::~Renderer() {
    glfwTerminate();
}

void Siege::Renderer::Draw() const {
    GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

    glfwSwapBuffers(window);
}

bool Siege::Renderer::Closed() const {
    return glfwWindowShouldClose(window);
}