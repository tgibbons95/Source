#ifndef WIDGET_H
#define WIDGET_H

#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <vector>

namespace ThomasUx
{
    class Widget
    {
    public:
        Widget();
        ~Widget();

        virtual void Draw();
        virtual void SetTime(float time);
        virtual void SubmitWidget() = 0;

    protected:

        GLint m_List = 0;
        float m_currentTime = 0.0f;

    private:

    };

    inline void Widget::SetTime(float time)
    {
        m_currentTime = time;
    }
}

#endif