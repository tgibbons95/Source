#include "DisplayManagerBase.h"

namespace ThDisplay
{
	DisplayManagerBase::DisplayManagerBase()
	{
	}

	DisplayManagerBase::~DisplayManagerBase()
	{
		delete sceneManager;
	}

	void DisplayManagerBase::FramebufferSizeCallback(GLFWwindow* window, int width, int height)
	{
		width_ = width;
		height_ = height;

		UpdateScenes();
		RenderScenes();

		glfwSwapBuffers(window);
	}

	void DisplayManagerBase::RenderDisplay()
	{
		glClearColor(0.33f, 0.33f, 0.33f, 0.9f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void DisplayManagerBase::SetOrtho()
	{
		glOrtho(0.0, 1.0, 0.0, 1.0, 0.0, 1.0);
	}

	const char* DisplayManagerBase::GetTitle()
	{
		return "Display";
	}

	int DisplayManagerBase::Run()
	{
		width_ = 800;
		height_ = 576;

		/* Initialize the library */
		if (!glfwInit())
			return -1;

		glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

		/* Create a windowed mode window and its OpenGL context */
		window = glfwCreateWindow(width_, height_, GetTitle(), NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			return -1;
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(window);

		// Initialize glew
		glewExperimental = true;
		if (glewInit() != GLEW_OK) {
			throw std::exception("Failed to initialize GLEW");
		}

		glfwSetWindowUserPointer(window, this);

		auto func = [](GLFWwindow* window, int width, int height)
		{
			static_cast<DisplayManagerBase*>(glfwGetWindowUserPointer(window))->FramebufferSizeCallback(window, width, height);
		};
		glfwSetFramebufferSizeCallback(window, func);
		glfwSwapInterval(1);

		// set up view
		glEnable(GL_SCISSOR_TEST);

		//// see https://www.opengl.org/sdk/docs/man2/xhtml/glOrtho.xml
		SetOrtho();

		sceneManager = new SceneManager();

		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			/* Render here */
			UpdateScenes();
			RenderScenes();

			glfwSwapBuffers(window);
			glfwPollEvents();

			//glViewport(0, 0, width, height); //restore default


			/* Swap front and back buffers */

			/* Poll for and process events */
		}

		glfwTerminate();
		return 0;
	}

	void DisplayManagerBase::RenderScenes()
	{
		for (int i = 0; i < 4; i++)
		{
			glViewport(viewports[i].left, viewports[i].bottom, viewports[i].width, viewports[i].height);
			glScissor(viewports[i].left, viewports[i].bottom, viewports[i].width, viewports[i].height);

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();

			auto scenePtr = sceneManager->GetScene(i);
			if (scenePtr)
			{
				scenePtr->Draw();
			}
		}
	}

	void DisplayManagerBase::UpdateScenes()
	{
		for (int i = 0; i < 4; i++)
		{
			viewports[i].left = (i % 2 == 0) ? 0 : width_ * 0.5 + 0.5;
			viewports[i].bottom = (i / 2 == 0) ? 0 : height_ * 0.5 + 0.5;
			viewports[i].width = width_ * 0.5 + 0.5;
			viewports[i].height = height_ * 0.5 + 0.5;
		}
	}
}