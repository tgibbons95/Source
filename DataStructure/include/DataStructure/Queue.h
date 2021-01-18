#ifndef QUEUE_H
#define QUEUE_H

#include "Utility/Macros.h"
#include <cstring>
#include <cassert>

#define MIN_QUEUE_SIZE 8

namespace DataStructureT
{
	template<typename T>
	class Queue
	{
	public:

		Queue()
			: length(MIN_QUEUE_SIZE)
		{
			queue = new T[length];
		}

		Queue(int l)
			: length(l)
		{
			if (length < MIN_QUEUE_SIZE)
			{
				length = MIN_QUEUE_SIZE;
			}
			queue = new T[length];
		}

		~Queue()
		{
			SAFE_DELETE_ARRAY(queue);
		}

		bool QueueEmpty()
		{
			return queueSize == 0;
		}

		// Introduction to Algorithms 3e: 10.1 Enqueue pg 235 
		void Enqueue(const T& element)
		{
			if (tailIndex == headIndex && queueSize > 0)
			{
				IncreaseSize();
			}
			queue[tailIndex] = element;
			tailIndex = (tailIndex == length - 1) ? 0 : tailIndex + 1;
			queueSize++;
		}

		// Introduction to Algorithms 3e: 10.1 Dequeue pg 235 
		T Dequeue()
		{
			assert(!QueueEmpty());
			int nodeIndex = headIndex;
			headIndex = (headIndex == length - 1) ? 0 : headIndex + 1;
			return queue[nodeIndex];
		}

	protected:
		
		T* queue = nullptr;
		int length = 0;
		int queueSize = 0;
		int headIndex = 0;
		int tailIndex = 0;

		void IncreaseSize()
		{
			T* newQueue = new T[length << 1];
			if (headIndex < tailIndex)
			{
				::memcpy(newQueue, queue, length * sizeof(T));
			}
			else
			{
				::memcpy(newQueue, queue, tailIndex * sizeof(T));
				::memcpy(newQueue + length + headIndex, queue + headIndex, (length - headIndex) * sizeof(T));
				headIndex += length;
			}
			length = length << 1;
			SAFE_DELETE_ARRAY(queue);
			queue = newQueue;
		}

	private:

	};
}

#endif