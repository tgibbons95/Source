#ifndef GEAR_WIDGET_H
#define GEAR_WIDGET_H


#include "Widgets/Widget.h"

#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <vector>

namespace ThomasUx
{
    /**

      Input:  inner_radius - radius of hole at center
              outer_radius - radius at center of teeth
              width - width of gear teeth - number of teeth
              tooth_depth - depth of tooth

     **/
    class GearWidget : public ThomasUx::Widget
    {
    public:
        GearWidget(GLfloat inner_radius, 
            GLfloat outer_radius, 
            GLfloat width,
            GLint teeth, 
            GLfloat tooth_depth,
            GLfloat* color);
        ~GearWidget();

        virtual void SetTranslate(GLfloat x, GLfloat y, GLfloat z);
        virtual void SetAngle(GLfloat multiplier, GLfloat offset);
        virtual void SubmitWidget() override;
    protected:

    private:

        std::vector<GLint> m_widgets;
        GLfloat m_angle = 0.0f;
        GLfloat m_angleMultiplier = 1.0f;
        GLfloat m_angleOffset = 0.0f;
        GLfloat m_translateX = 0.0f;
        GLfloat m_translateY = 0.0f;
        GLfloat m_translateZ = 0.0f;
    };

    inline void GearWidget::SetTranslate(GLfloat x, GLfloat y, GLfloat z)
    {
        m_translateX = x;
        m_translateY = y;
        m_translateZ = z;
    }

    inline void GearWidget::SetAngle(GLfloat multiplier, GLfloat offset)
    {
        m_angleMultiplier = multiplier;
        m_angleOffset = offset;
    }
}

#endif