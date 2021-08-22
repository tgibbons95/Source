#include "DefaultScene/DefaultScene.h"

#ifdef __cplusplus
extern "C" {
#endif


__declspec(dllexport) ThDisplay::DisplaySceneBase* __stdcall CreateScene()
{
	return new ThDisplay::DefaultScene("Default");
}

#ifdef __cplusplus
}
#endif