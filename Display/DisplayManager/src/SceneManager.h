#include "DisplayScene/DisplaySceneBase.h"
#include <vector>

namespace ThDisplay
{
	class SceneManager
	{
	public:
		SceneManager();
		~SceneManager();

		int GetNumberOfScenes();
		DisplaySceneBase* GetScene(int scene);

	protected:

	private:

		std::vector<DisplaySceneBase*> displayScenes;
	};

	inline int SceneManager::GetNumberOfScenes()
	{
		return static_cast<int>(displayScenes.size());
	}

	inline DisplaySceneBase* SceneManager::GetScene(int scene)
	{
		return (scene < displayScenes.size() && scene >= 0) ? displayScenes[scene] : nullptr;
	}
}