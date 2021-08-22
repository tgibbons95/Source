#include "DisplayManager.h"

#include <fstream>
#include <iostream>
#include <GLFW/glfw3.h>

namespace ThDisplay
{
	DisplayManager::DisplayManager()
	{

	}

	DisplayManager::~DisplayManager()
	{

	}

	void DisplayManager::RenderDisplay()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void DisplayManager::SetOrtho()
	{
		glOrtho(0.0, 1.0, 0.0, 1.0, 0.0, 1.0);
	}

	const char* DisplayManager::GetTitle()
	{
		return "Visualization";
	}
}