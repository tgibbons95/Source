
#include "GL\glew.h"
#include <GLFW/glfw3.h>
#include "DisplayScene/DisplaySceneBase.h"
#include "SceneManager.h"

namespace ThDisplay
{
	struct viewportScene
	{
		int left;
		int bottom;
		int width;
		int height;
		DisplaySceneBase* scenePtr;
	};

	class DisplayManagerBase
	{
	public:
		DisplayManagerBase();
		~DisplayManagerBase();

		virtual int Run();
	
	protected:
		virtual void RenderDisplay();
		virtual void SetOrtho();
		virtual const char* GetTitle();
		virtual void FramebufferSizeCallback(GLFWwindow* window, int width, int height);

		GLFWwindow* GetWindow();

	private:

		void UpdateScenes();
		void RenderScenes();

		GLFWwindow* window = nullptr;

		viewportScene viewports[4];

		SceneManager* sceneManager = nullptr;

		int width_ = 0;
		int height_ = 0;
	};

	inline GLFWwindow* DisplayManagerBase::GetWindow()
	{
		return window;
	}
}