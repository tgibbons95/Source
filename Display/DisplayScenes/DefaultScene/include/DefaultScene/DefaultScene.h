#ifndef DEFAULT_SCENE_H
#define DEFAULT_SCENE_H

#include "DisplayScene/DisplaySceneBase.h"

#include <GLFW/glfw3.h>
#include <string>

namespace ThDisplay
{
	class DefaultScene : public DisplaySceneBase
	{
	public:
		DefaultScene(const std::string& name);
		~DefaultScene() = default;

		virtual void Draw() override;

	protected:


	private:

	};
}

#endif