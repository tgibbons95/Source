#include "Widgets/MainWindow.h"

#if defined(_MSC_VER)
// Make MS math.h define M_PI
#define _USE_MATH_DEFINES
#endif

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

namespace ThomasUx
{
    GLfloat MainWindow::view_rotx = 20.f;
    GLfloat MainWindow::view_roty = 30.f;
    GLfloat MainWindow::view_rotz = 0.f;

    MainWindow::MainWindow()
    {
        int width, height;

        if (!glfwInit())
        {
            fprintf(stderr, "Failed to initialize GLFW\n");
            exit(EXIT_FAILURE);
        }

        glfwWindowHint(GLFW_DEPTH_BITS, 16);
        glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

        m_window = glfwCreateWindow(300, 300, "Gears", NULL, NULL);
        if (!m_window)
        {
            fprintf(stderr, "Failed to open GLFW window\n");
            exit(EXIT_FAILURE);
        }

        // Set callback functions
        glfwSetFramebufferSizeCallback(m_window, MainWindow::Reshape);
        glfwSetKeyCallback(m_window, MainWindow::Key);

        glfwMakeContextCurrent(m_window);
        gladLoadGL(glfwGetProcAddress);
        glfwSwapInterval(1);

        glfwGetFramebufferSize(m_window, &width, &height);
        MainWindow::Reshape(m_window, width, height);

        static GLfloat pos[4] = { 0.f, 0.f, 0.f, 0.f };
        glLightfv(GL_LIGHT0, GL_POSITION, pos);
        glEnable(GL_CULL_FACE);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_DEPTH_TEST);
    }

    MainWindow::~MainWindow()
    {
        // Terminate GLFW
        glfwTerminate();
    }

    void MainWindow::Run()
    {
        glEnable(GL_NORMALIZE);

        // Main loop
        while (!glfwWindowShouldClose(m_window))
        {
            // Draw gears
            Draw();

            // Update animation
            Animate();

            // Swap buffers
            glfwSwapBuffers(m_window);
            glfwPollEvents();
        }
    }

    /* OpenGL draw function & timing */
    void MainWindow::Draw()
    {
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glPushMatrix();
        glRotatef(view_rotx, 1.0, 0.0, 0.0);
        glRotatef(view_roty, 0.0, 1.0, 0.0);
        glRotatef(view_rotz, 0.0, 0.0, 1.0);

        for (auto& widget : m_widgets)
        {
            widget->Draw();
        }

        glPopMatrix();
    }


    /* update animation parameters */
    void MainWindow::Animate()
    {
        for (auto& widget : m_widgets)
        {
            widget->SetTime((float)glfwGetTime());
        }
    }

    /* change view angle, exit upon ESC */
    void MainWindow::Key(GLFWwindow* window, int k, int s, int action, int mods)
    {
        if (action != GLFW_PRESS) return;

        switch (k) {
        case GLFW_KEY_Z:
            if (mods & GLFW_MOD_SHIFT)
                view_rotz -= 5.0;
            else
                view_rotz += 5.0;
            break;
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(window, GLFW_TRUE);
            break;
        case GLFW_KEY_UP:
            view_rotx += 5.0;
            break;
        case GLFW_KEY_DOWN:
            view_rotx -= 5.0;
            break;
        case GLFW_KEY_LEFT:
            view_roty += 5.0;
            break;
        case GLFW_KEY_RIGHT:
            view_roty -= 5.0;
            break;
        default:
            return;
        }
    }

    /* new window size */
    void MainWindow::Reshape(GLFWwindow* window, int width, int height)
    {
        GLfloat h = (GLfloat)height / (GLfloat)width;
        GLfloat xmax, znear, zfar;

        znear = 5.0f;
        zfar = 30.0f;
        xmax = znear * 0.5f;

        glViewport(0, 0, (GLint)width, (GLint)height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glFrustum(-xmax, xmax, -xmax * h, xmax * h, znear, zfar);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0, 0.0, -20.0);
    }
}