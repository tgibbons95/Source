#include "TextScene.h"

#include <iostream>


namespace ThDisplay
{
	TextScene::TextScene(const std::string& name)
		: DisplaySceneBase(name)
	{
		//GLint GlewInitResult = glewInit();
		//if (GLEW_OK != GlewInitResult)
		//{
		//	printf("ERROR: %s", glewGetErrorString(GlewInitResult));
		//}

		//glFont = std::shared_ptr<GLFont>(new GLFont("C:/Windows/Fonts/Arial.ttf"));

		//// Some values we will use to create our labels
		//int startX = 100;
		//int startY = 100;
		//int windowWidth = 800;
		//int windowHeight = 600;

		//label = std::unique_ptr<FTLabel>(new FTLabel(
		//	glFont,         // Font face handle
		//	"Hello world!", // Text to render
		//	startX,
		//	startY,
		//	windowWidth,
		//	windowHeight
		//));

		//label->setPosition(0, 0);
		//label->setSize(100, 100);

		//label->setPixelSize(24);
		//label->setIndentation(50);
		//label->setAlignment(FTLabel::FontFlags::LeftAligned);
		//label->setColor(0.89, 0.26, 0.3, 0.9);

		//label->rotate(90, 0, 1, 0);

	}

	void TextScene::Draw()
	{
		glOrtho(0.0, 1.0, 0.0, 1.0, 0.0, 1.0);

		glClearColor(1.0, 1.0, 1.0, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//label->render();
	}
}