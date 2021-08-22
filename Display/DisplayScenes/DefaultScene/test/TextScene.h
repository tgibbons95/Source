#ifndef TEXT_SCENE_H
#define TEXT_SCENE_H

#include "GLFont.h"
#include "FTLabel.h"

#include "DisplayScene/DisplaySceneBase.h"

#include <memory>

#include <GLFW/glfw3.h>
#include <string>

namespace ThDisplay
{
	class TextScene : public DisplaySceneBase
	{
	public:
		TextScene(const std::string& name);
		~TextScene() = default;

		virtual void Draw() override;

	protected:


	private:

		std::shared_ptr<GLFont> glFont;
		std::unique_ptr<FTLabel> label;

	};
}

#endif