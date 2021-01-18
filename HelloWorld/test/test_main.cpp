#include "gtest/gtest.h"
#include "HelloWorld/HelloWorld.h"

#define EXPECTED_HELLO_WORLD_LENGTH 11

TEST(HelloWorldTest, Length) 
{ 
   EXPECT_EQ (EXPECTED_HELLO_WORLD_LENGTH, HelloWorld::GetHelloWorldLength());
}

TEST (HelloWorldTest, Contents) 
{
	const char* expectedString = "Hello World";
	const char* actualString = HelloWorld::GetHelloWorld();
	for(int i = 0; i < EXPECTED_HELLO_WORLD_LENGTH; i++)
	{
      ASSERT_EQ (expectedString[i], actualString[i]);
	}
}

int main(int argc, char** argv) 
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}