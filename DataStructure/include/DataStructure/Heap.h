#ifndef HEAP_H
#define HEAP_H

#include "Utility/Macros.h"
#include <cstring>

#define MIN_HEAP_SIZE 8

namespace DataStructureT
{
	template<typename T>
	class Heap
	{
	public:

		Heap(T* array, int l)
			: length(l)
			, heapSize(l)
		{
			if (length < MIN_HEAP_SIZE)
			{
				length = MIN_HEAP_SIZE;
			}
			heap = new T[length];
			::memcpy(heap, array, heapSize * sizeof(T));
		}

		Heap(int l)
			: length(l)
		{
			if (length < MIN_HEAP_SIZE)
			{
				length = MIN_HEAP_SIZE;
			}
			heap = new T[length];
		}

		~Heap()
		{
			SAFE_DELETE_ARRAY(heap);
		}

		int Parent(int i) { return (i - 1) / 2; }
		int Left(int i) { return 2 * i + 1; }
		int Right(int i) { return 2 * i + 2; }
		T Root() { return heap[0]; }

		virtual void Insert(const T& element) = 0;
		virtual T Extract() = 0;
		virtual void Heapify(int i) = 0;


	protected:
		
		T* heap = nullptr;
		int length = 0;
		int heapSize = 0;

		void IncreaseSize()
		{
			T* newHeap = new T[length << 1];
			::memcpy(newHeap, heap, length * sizeof(T));
			length = length << 1;
			SAFE_DELETE_ARRAY(heap);
			heap = newHeap;
		}

	private:

	};

	template<typename T>
	class MaxHeap : public Heap<T>
	{
	public:
		MaxHeap() : Heap<T>(MIN_HEAP_SIZE)
		{

		}

		MaxHeap(int reserve) : Heap<T>(reserve)
		{
			
		}

		MaxHeap(T* array, int length) : Heap<T>(array, length)
		{
			for (int i = length / 2; i >= 0; i--)
			{
				Heapify(i);
			}
		}

		virtual void Insert(const T& element) override
		{
			if (heapSize == length)
			{
				IncreaseSize();
			}
			heap[heapSize] = element;
			int i = heapSize++;
			T temp;
			while (i > 0 && heap[Parent(i)] < heap[i])
			{
				temp = heap[i];
				heap[i] = heap[Parent(i)];
				heap[Parent(i)] = temp;
				i = Parent(i);
			}
		}

		virtual T Extract() override
		{
			T root = heap[0];
			heap[0] = heap[--heapSize];
			Heapify(0);
			return root;
		}

		virtual void Heapify(int i) override
		{
			T temp;
			int l = Left(i);
			int r = Right(i);
			int largest = (l < heapSize& heap[l] > heap[i]) ? l : i;
			if (r < heapSize & heap[r] > heap[largest])
			{
				largest = r;
			}
			if (largest != i)
			{
				SWAP(heap[i], heap[largest], temp);
				Heapify(largest);
			}
		}

	protected:

	private:

	};
}

#endif