/*
 * CTECArray.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: eort3611
 */

#include "CTECArray.h"

#include <iostream>
#include <assert.h>
using namespace std;

template<class Type>
CTECArray<Type>::CTECArray(int size)
{
	this->size = size;
	this->head = nullptr;

	assert(size > 0);
	for (int index = 0; index <= size; index++)
	{
		if (head != nullptr)
		{
			ArrayNode<Type> * nextNode = new ArrayNode<Type>();
			nextNode->setNext(head);
			this->head = nextNode;
		}
		else
		{
			ArrayNode<Type> * firstNode = new ArrayNode<Type>();
			this->head = firstNode;
		}
	}
}
template<class Type>
CTECArray<Type>::~CTECArray()
{
	ArrayNode<Type> * deleteMeh = head;
	for(int index = 0; index < size; index++)
	{
		if(deleteMeh->getNext() != nullptr)
		{
			head = deleteMeh->getNext();
			deleteMeh->setNext(nullptr);
			delete deleteMeh;
			deleteMeh = head;
		}
		else
		{
			delete deleteMeh;
			deleteMeh = head;
		}
	}
}

template<class Type>
int CTECArray<Type>::getSize()
{
	return size;
}




template<class Type>
void CTECArray<Type>::set(int position, const Type& value)
{
	assert(position < size && position >= 0);
		ArrayNode<Type> * current = head;
		for (int spot = 0; spot <= position; spot++)
		{
			if (spot != position)
			{
				current = current->getNext();
			}
			else
			{
				return current->setValue(value);
			}
		}

}

template<class Type>
Type CTECArray<Type>::get(int position)
{
	assert(position < size && position > -1);
		ArrayNode<Type> * current = head;
		for(int spot = 0; spot <= position; spot++)
		{
			if(spot != position)
			{
				current = current->getNext();
			}
			else
			{
				return current->getValue();
			}
		}

}
