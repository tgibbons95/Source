#include "DefaultScene/DefaultScene.h"

#include <iostream>


namespace ThDisplay
{
	DefaultScene::DefaultScene(const std::string& name)
		: DisplaySceneBase(name)
	{
		
	}

	void DefaultScene::Draw()
	{
		glOrtho(0.0, 1.0, 0.0, 1.0, 0.0, 1.0);

		glClearColor(0.765625f, 0.1171875f, 0.2265625f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glPointSize(5);
		glLineWidth(2.5);

		// Horizontal Axis Ticks
		glBegin(GL_LINES);
		for (int i = 0; i <= 10; i++)
		{
			glColor3f(0.5, 0.5, 0.5);
			glVertex3f(i / 10.0f, 1.0, 0.0);
			glVertex3f(i / 10.0f, 0.0, 0.0);

			glColor3f(0.0, 0.0, 0.0);
			glVertex3f(i / 10.0f, 0.11, 0.0);
			glVertex3f(i / 10.0f, 0.09, 0.0);

		}
		glEnd();

		// Vertical Axis Ticks
		glBegin(GL_LINES);
		for (int i = 0; i <= 10; i++)
		{
			glColor3f(0.5, 0.5, 0.5);
			glVertex3f(1.0, i / 10.0, 0.0);
			glVertex3f(0.0, i / 10.0, 0.0);

			glColor3f(0.0, 0.0, 0.0);
			glVertex3f(0.11, i / 10.0, 0.0);
			glVertex3f(0.09, i / 10.0, 0.0);

		}
		glEnd();

		// Grid
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex3f(1.0, 0.1, 0.0);
		glVertex3f(0.0, 0.1, 0.0);
		glVertex3f(0.1, 0.0, 0.0);
		glVertex3f(0.1, 1.0, 0.0);
		glEnd();
	}
}