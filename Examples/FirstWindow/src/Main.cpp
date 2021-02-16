#include <Renderer.hpp>
#include <GLFW/glfw3.h>

using namespace Siege;

int main() {
    Renderer renderer({720, 568}, "Title goes here", {1, 2});
    while (!renderer.Closed()) {
        renderer.Draw();
        glfwPollEvents();
    }
}
