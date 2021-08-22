#ifndef DISPLAY_SCENE_BASE_H
#define DISPLAY_SCENE_BASE_H

#include <GLFW/glfw3.h>
#include <string>

namespace ThDisplay
{
	class DisplaySceneBase
	{
	public:
		DisplaySceneBase(const std::string& name);
		~DisplaySceneBase() = default;

		virtual void Draw() = 0;
		virtual const std::string& GetName() const;

	protected:


	private:

		std::string name_;
	};

	inline const std::string& DisplaySceneBase::GetName() const
	{
		return name_;
	}
}

#endif