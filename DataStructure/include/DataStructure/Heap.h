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
		T Root() { return this->heap[0]; }

		virtual void Insert(const T& element) = 0;
		virtual T Extract() = 0;
		virtual void Heapify(int i) = 0;


	protected:
		
		T* heap = nullptr;
		int length = 0;
		int heapSize = 0;

		void IncreaseSize()
		{
			T* newHeap = new T[this->length << 1];
			::memcpy(newHeap, this->heap, length * sizeof(T));
			this->length = this->length << 1;
			SAFE_DELETE_ARRAY(this->heap);
			this->heap = newHeap;
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
				this->Heapify(i);
			}
		}

		virtual void Insert(const T& element) override
		{
			if (this->heapSize == this->length)
			{
				this->IncreaseSize();
			}
			this->heap[this->heapSize] = element;
			int i = this->heapSize++;
			T temp;
			while (i > 0 && this->heap[this->Parent(i)] < this->heap[i])
			{
				temp = this->heap[i];
				this->heap[i] = this->heap[this->Parent(i)];
				this->heap[this->Parent(i)] = temp;
				i = this->Parent(i);
			}
		}

		virtual T Extract() override
		{
			T root = this->heap[0];
			this->heap[0] = this->heap[--this->heapSize];
			this->Heapify(0);
			return root;
		}

		virtual void Heapify(int i) override
		{
			T temp;
			int l = this->Left(i);
			int r = this->Right(i);
			int largest = (l < this->heapSize& this->heap[l] > this->heap[i]) ? l : i;
			if (r < this->heapSize & this->heap[r] > this->heap[largest])
			{
				largest = r;
			}
			if (largest != i)
			{
				SWAP(this->heap[i], this->heap[largest], temp);
				this->Heapify(largest);
			}
		}

	protected:

	private:

	};
}

#endif