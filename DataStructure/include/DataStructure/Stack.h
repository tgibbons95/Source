#ifndef STACK_H
#define STACK_H

#include "Utility/Macros.h"
#include <cstring>
#include <cassert>

#define MIN_STACK_SIZE 8

namespace DataStructureT
{
	template<typename T>
	class Stack
	{
	public:

		Stack()
			: length(MIN_STACK_SIZE)
		{
			stack = new T[length];
		}

		Stack(int l)
			: length(l)
		{
			if (length < MIN_STACK_SIZE)
			{
				length = MIN_STACK_SIZE;
			}
			stack = new T[length];
		}

		~Stack()
		{
			SAFE_DELETE_ARRAY(stack);
		}

		// Introduction to Algorithms 3e: 10.1 Stack Empty pg 233 
		bool StackEmpty()
		{
			return stackSize == 0;
		}

		// Introduction to Algorithms 3e: 10.1 Push pg 233 
		void Push(const T& element)
		{
			if (stackSize == length)
			{
				IncreaseSize();
			}
			stack[stackSize++] = element;
		}

		// Introduction to Algorithms 3e: 10.1 Pop pg 233 
		T Pop()
		{
			assert(!StackEmpty());
			return stack[--stackSize];
		}

	protected:
		
		T* stack = nullptr;
		int length = 0;
		int stackSize = 0;

		void IncreaseSize()
		{
			T* newStack = new T[length << 1];
			::memcpy(newStack, stack, length * sizeof(T));
			length = length << 1;
			SAFE_DELETE_ARRAY(stack);
			stack = newStack;
		}

	private:

	};
}

#endif