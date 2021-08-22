#include "TextScene.h"

#ifdef __cplusplus
extern "C" {
#endif


__declspec(dllexport) ThDisplay::DisplaySceneBase* __stdcall CreateScene()
{
	return new ThDisplay::TextScene("Text");
}

#ifdef __cplusplus
}
#endif