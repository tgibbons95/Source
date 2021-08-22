#include <windows.h>
#include <iostream>
#include <filesystem>
#include <string>

typedef int(__stdcall* f_printHelloWorld)();

namespace fs = std::filesystem;

int main(void)
{
	std::string path = "C:/SourceDevelop/DynamicLoadDll/out/install/x64-Debug (default)/bin";
	for (const auto& entry : fs::directory_iterator(path))
	{
		if (entry.path().extension().compare(".dll") == 0)
		{
			std::cout << entry.path() << std::endl;

			HINSTANCE hGetProcIDDLL = LoadLibrary(entry.path().u8string().c_str());

			if (!hGetProcIDDLL) {
				std::cout << "could not load the dynamic library" << std::endl;
				return EXIT_FAILURE;
			}

			// resolve function address here
			f_printHelloWorld printHelloWorld = (f_printHelloWorld)GetProcAddress(hGetProcIDDLL, "PrintHelloWorld");
			if (!printHelloWorld) {
				std::cout << "could not locate the function in " << entry.path().filename() << std::endl;
			}
			else
			{
				std::cout << "printHelloWorld() returned " << printHelloWorld() << std::endl;
			}
		}
	}

	return EXIT_SUCCESS;
}