#ifndef LIST_H
#define LIST_H

#include "Utility/Macros.h"
#include <cstring>
#include <cassert>

#define MIN_STACK_SIZE 8

namespace DataStructureT
{
	template<typename T>
	struct ListNode
	{
		T key;
		ListNode<T>* next;
		ListNode<T>* prev;
		ListNode<T>& operator++() { return *next; }
		ListNode<T>& operator++(int) { return *next; };
		ListNode<T>& operator--() { return *prev; }
		ListNode<T>& operator--(int) { return *prev; };
	};

	template<typename T>
	class List
	{
	public:

		List()
		{
			CreateNilNode();
		}


		~List()
		{
			ListNode<T>* currentNode = nil->next;
			ListNode<T>* nextNode = nil->next;
			while (currentNode != nil)
			{
				nextNode = currentNode->next;
				SAFE_DELETE(currentNode);
				currentNode = nextNode;
			}
			SAFE_DELETE(nil);
		}

		bool ListEmpty()
		{
			return head;
		}

		// Introduction to Algorithms 3e: 10.2 List Search pg 239
		ListNode<T>* Search(const T& k)
		{
			ListNode<T>* x = nil->next;
			while (x != nil && x->key != k)
			{
				x = x->next;
			}
			return (x != nil) ? x : nullptr;
		}

		void Insert(const T& element)
		{
			ListNode<T>* newNode = new ListNode<T>();
			::memcpy(newNode, &element, sizeof(T));
			Insert(newNode);
		}

		// Introduction to Algorithms 3e: 10.2 Delete pg 238
		void Delete(ListNode<T>* node)
		{
			assert(node);
			node->prev->next = node->next;
			node->next->prev = node->prev;
			SAFE_DELETE(node);
		}

	protected:
		
		// Introduction to Algorithms 3e: 10.2 List Insert pg 240
		void Insert(ListNode<T>* node)
		{
			assert(node);
			node->next = nil->next;
			nil->next->prev = node;
			nil->next = node;
			node->prev = nil;
		}

		ListNode<T>* nil = nullptr;
		int listSize = 0;

	private:

		void CreateNilNode()
		{
			nil = new ListNode<T>();
			nil->next = nil;
			nil->prev = nil;
		}
	};
}

#endif