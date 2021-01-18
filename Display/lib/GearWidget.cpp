#include "Widgets/GearWidget.h"

#if defined(_MSC_VER)
// Make MS math.h define M_PI
#define _USE_MATH_DEFINES
#endif

#include <math.h>

namespace ThomasUx
{
    GearWidget::GearWidget(GLfloat inner_radius, 
        GLfloat outer_radius, 
        GLfloat width,
        GLint teeth, 
        GLfloat tooth_depth,
        GLfloat* color)
    {

        m_List = glGenLists(1);
        glNewList(m_List, GL_COMPILE);
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);

        GLint i;
        GLfloat r0, r1, r2;
        GLfloat angle, da;
        GLfloat u, v, len;

        r0 = inner_radius;
        r1 = outer_radius - tooth_depth / 2.f;
        r2 = outer_radius + tooth_depth / 2.f;

        da = 2.f * (float)M_PI / teeth / 4.f;

        glShadeModel(GL_FLAT);

        glNormal3f(0.f, 0.f, 1.f);

        /* draw front face */
        glBegin(GL_QUAD_STRIP);
        for (i = 0; i <= teeth; i++) {
            angle = i * 2.f * (float)M_PI / teeth;
            glVertex3f(r0 * (float)cos(angle), r0 * (float)sin(angle), width * 0.5f);
            glVertex3f(r1 * (float)cos(angle), r1 * (float)sin(angle), width * 0.5f);
            if (i < teeth) {
                glVertex3f(r0 * (float)cos(angle), r0 * (float)sin(angle), width * 0.5f);
                glVertex3f(r1 * (float)cos(angle + 3 * da), r1 * (float)sin(angle + 3 * da), width * 0.5f);
            }
        }
        glEnd();

        /* draw front sides of teeth */
        glBegin(GL_QUADS);
        da = 2.f * (float)M_PI / teeth / 4.f;
        for (i = 0; i < teeth; i++) {
            angle = i * 2.f * (float)M_PI / teeth;

            glVertex3f(r1 * (float)cos(angle), r1 * (float)sin(angle), width * 0.5f);
            glVertex3f(r2 * (float)cos(angle + da), r2 * (float)sin(angle + da), width * 0.5f);
            glVertex3f(r2 * (float)cos(angle + 2 * da), r2 * (float)sin(angle + 2 * da), width * 0.5f);
            glVertex3f(r1 * (float)cos(angle + 3 * da), r1 * (float)sin(angle + 3 * da), width * 0.5f);
        }
        glEnd();

        glNormal3f(0.0, 0.0, -1.0);

        /* draw back face */
        glBegin(GL_QUAD_STRIP);
        for (i = 0; i <= teeth; i++) {
            angle = i * 2.f * (float)M_PI / teeth;
            glVertex3f(r1 * (float)cos(angle), r1 * (float)sin(angle), -width * 0.5f);
            glVertex3f(r0 * (float)cos(angle), r0 * (float)sin(angle), -width * 0.5f);
            if (i < teeth) {
                glVertex3f(r1 * (float)cos(angle + 3 * da), r1 * (float)sin(angle + 3 * da), -width * 0.5f);
                glVertex3f(r0 * (float)cos(angle), r0 * (float)sin(angle), -width * 0.5f);
            }
        }
        glEnd();

        /* draw back sides of teeth */
        glBegin(GL_QUADS);
        da = 2.f * (float)M_PI / teeth / 4.f;
        for (i = 0; i < teeth; i++) {
            angle = i * 2.f * (float)M_PI / teeth;

            glVertex3f(r1 * (float)cos(angle + 3 * da), r1 * (float)sin(angle + 3 * da), -width * 0.5f);
            glVertex3f(r2 * (float)cos(angle + 2 * da), r2 * (float)sin(angle + 2 * da), -width * 0.5f);
            glVertex3f(r2 * (float)cos(angle + da), r2 * (float)sin(angle + da), -width * 0.5f);
            glVertex3f(r1 * (float)cos(angle), r1 * (float)sin(angle), -width * 0.5f);
        }
        glEnd();

        /* draw outward faces of teeth */
        glBegin(GL_QUAD_STRIP);
        for (i = 0; i < teeth; i++) {
            angle = i * 2.f * (float)M_PI / teeth;

            glVertex3f(r1 * (float)cos(angle), r1 * (float)sin(angle), width * 0.5f);
            glVertex3f(r1 * (float)cos(angle), r1 * (float)sin(angle), -width * 0.5f);
            u = r2 * (float)cos(angle + da) - r1 * (float)cos(angle);
            v = r2 * (float)sin(angle + da) - r1 * (float)sin(angle);
            len = (float)sqrt(u * u + v * v);
            u /= len;
            v /= len;
            glNormal3f(v, -u, 0.0);
            glVertex3f(r2 * (float)cos(angle + da), r2 * (float)sin(angle + da), width * 0.5f);
            glVertex3f(r2 * (float)cos(angle + da), r2 * (float)sin(angle + da), -width * 0.5f);
            glNormal3f((float)cos(angle), (float)sin(angle), 0.f);
            glVertex3f(r2 * (float)cos(angle + 2 * da), r2 * (float)sin(angle + 2 * da), width * 0.5f);
            glVertex3f(r2 * (float)cos(angle + 2 * da), r2 * (float)sin(angle + 2 * da), -width * 0.5f);
            u = r1 * (float)cos(angle + 3 * da) - r2 * (float)cos(angle + 2 * da);
            v = r1 * (float)sin(angle + 3 * da) - r2 * (float)sin(angle + 2 * da);
            glNormal3f(v, -u, 0.f);
            glVertex3f(r1 * (float)cos(angle + 3 * da), r1 * (float)sin(angle + 3 * da), width * 0.5f);
            glVertex3f(r1 * (float)cos(angle + 3 * da), r1 * (float)sin(angle + 3 * da), -width * 0.5f);
            glNormal3f((float)cos(angle), (float)sin(angle), 0.f);
        }

        glVertex3f(r1 * (float)cos(0), r1 * (float)sin(0), width * 0.5f);
        glVertex3f(r1 * (float)cos(0), r1 * (float)sin(0), -width * 0.5f);

        glEnd();

        glShadeModel(GL_SMOOTH);

        /* draw inside radius cylinder */
        glBegin(GL_QUAD_STRIP);
        for (i = 0; i <= teeth; i++) {
            angle = i * 2.f * (float)M_PI / teeth;
            glNormal3f(-(float)cos(angle), -(float)sin(angle), 0.f);
            glVertex3f(r0 * (float)cos(angle), r0 * (float)sin(angle), -width * 0.5f);
            glVertex3f(r0 * (float)cos(angle), r0 * (float)sin(angle), width * 0.5f);
        }
        glEnd();

        glEndList();
    }

    GearWidget::~GearWidget()
    {

    }

    void GearWidget::SubmitWidget()
    {
        m_angle = 100.f * m_currentTime;
        glPushMatrix();
            glTranslatef(m_translateX, m_translateY, m_translateZ);
            glRotatef(m_angle * m_angleMultiplier + m_angleOffset, 0.0, 0.0, 1.0);
            glCallList(m_List);
        glPopMatrix();
    }

}