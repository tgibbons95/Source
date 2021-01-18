#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "Widgets/Widget.h"

#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <vector>

namespace ThomasUx
{
    class MainWindow
    {
    public:
        MainWindow();
        ~MainWindow();

        void Run();
        void AddWidget(ThomasUx::Widget* widget);
    protected:

    private:
        void Draw();
        void Animate();
        static void Key(GLFWwindow* window, int k, int s, int action, int mods);
        static void Reshape(GLFWwindow* window, int width, int height);

        GLFWwindow* m_window;
        static GLfloat view_rotx;
        static GLfloat view_roty;
        static GLfloat view_rotz;
        GLint gear1, gear2, gear3;
        GLfloat angle = 0.f;

        std::vector<ThomasUx::Widget*> m_widgets;
    };

    inline void MainWindow::AddWidget(ThomasUx::Widget* widget)
    {
        m_widgets.push_back(widget);
    }
}

#endif