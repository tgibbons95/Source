#include <iostream>
#define d_int int __declspec(dllexport) __stdcall

#ifdef __cplusplus
extern "C" {  // only need to export C interface if
			  // used by C++ source code
#endif

// DLL
d_int PrintHelloWorld()
{
	std::cout << "Hello World" << std::endl;
	return 0;
}

#ifdef __cplusplus
}
#endif