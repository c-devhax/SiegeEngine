#pragma once

#include <string>
#include <stdint.h>
#include <vector>
#include <memory>
#include <map>
#include <GLFW/glfw3.h>

namespace Siege {
    template<typename T = uint32_t>
    struct Vec2 {
        T x, y;
    };
    using Dimension_t = Vec2<uint16_t>;

    class Renderer {
    public:
        Renderer(const Dimension_t& dimensions, const std::string& title, const Vec2<uint8_t>& glVersion);
        virtual ~Renderer();

        void Draw() const;
        bool Closed() const;
    private:
        Dimension_t m_ViewPortDimensions;
        GLFWwindow* window;
        const Vec2<uint8_t> OpenGL_Info_Version;
    };
}
