#include "HelloWorld/HelloWorld.h"

#include <iostream>

namespace HelloWorld
{
	void PrintHelloWorld()
	{
		std::cout << GetHelloWorld() << std::endl;
	}
	
	const char* GetHelloWorld()
	{
		return "Hello World";
	}
	
	int GetHelloWorldLength()
	{
		const char* helloWorld = GetHelloWorld();
		int length = 0;
		while(helloWorld[length++] != '\0');
		return length - 1;
	}
}