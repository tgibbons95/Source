#include "SceneManager.h"

#include <fstream>
#include <iostream>
#include <GLFW/glfw3.h>

#include <windows.h>
#include <iostream>
#include <filesystem>
#include <string>

namespace ThDisplay
{
	typedef DisplaySceneBase*(__stdcall* f_createScene)();

	SceneManager::SceneManager()
	{
		std::string path = "C:/SourceDevelop/out/install/x64-Debug (default)/bin/Scenes";//::getenv("TH_SCENES_ROOT");
		for (const auto& entry : std::filesystem::directory_iterator(path))
		{
			if (entry.path().extension().compare(".dll") == 0)
			{
				std::cout << entry.path() << std::endl;

				HINSTANCE hGetProcIDDLL = LoadLibrary(entry.path().u8string().c_str());
				if (hGetProcIDDLL)
				{
					// resolve function address here
					f_createScene createScene = (f_createScene)GetProcAddress(hGetProcIDDLL, "CreateScene");
					if (!createScene) {
						std::cout << "could not locate the function in " << entry.path().filename() << std::endl;
					}
					else
					{
						displayScenes.push_back(createScene());
						std::cout << "createScene() returned " << displayScenes.back()->GetName() << std::endl;
					}
				}
				else
				{
					std::cout << "Error: " << GetLastError() << std::endl;
				}
			}
		}
	}

	SceneManager::~SceneManager()
	{
		for (auto& scene : displayScenes)
		{
			delete scene;
		}
	}
}