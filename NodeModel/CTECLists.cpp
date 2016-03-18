/*
 * CTECLists.cpp
 *
 *  Created on: Feb 29, 2016
 *      Author: eort3611
 */

#include "CTECLists.h"
#include <assert.h>
#include <iostream>

template<class Type>
CTECLists<Type>::CTECLists()
{
	this->size = 0;
	this->head = nullptr;
	this->end = nullptr;

}
template<class Type>
CTECLists<Type>::~CTECLists()
{

}
template<class Type>
void CTECLists<Type>::addAtIndex(int index, const Type& value)
{
	assert(size >= 0);
	assert(index >= 0);
	assert(index < size);

	ArrayNode<Type> * currentSpot = head;
	ArrayNode<Type> * nextSpot;
	ArrayNode<Type> * newNext;
	ArrayNode<Type> * newNode = new ArrayNode<Type>(value);

	for (int spot = 0; spot < index + 1; index++)
	{

		if (spot == index - 1)
		{
			newNext = newNode;
			currentSpot->setNext(newNext);
			newNext->setNext(nextSpot);

		}

		if (spot == index + 1)
		{
			nextSpot = currentSpot->getNext();
		}

		currentSpot = currentSpot->getNext();
	}

}
template<class Type>
void CTECLists<Type>::addToEnd(const Type& value)
{
	assert(size >= 0);

	ArrayNode<Type> * newEnd = new ArrayNode<Type>(value);
	ArrayNode<Type> * currentSpot = end;
	ArrayNode<Type> * newNext = newEnd;

	currentSpot->setNext(newNext);
	newNext->setNext(nullptr);

}
template<class Type>
void CTECLists<Type>::addToFront(const Type& value)
{

	ArrayNode<Type> * current = head;
	ArrayNode<Type> * newFirst = new ArrayNode<Type>(value);

	newFirst->setNext(current);
	head = newFirst;

}
template<class Type>
Type CTECLists<Type>::removeFromFront()
{

	assert(this->size > 0);

	Type thingToRemove;
	ArrayNode<Type> * newHead = new ArrayNode<Type>();
	newHead = head->getNext();
	thingToRemove = this->head->getValue();
	delete this->head;

	this->head = newHead;

	return thingToRemove;

}
template<class Type>
Type CTECLists<Type>::removeFromIndex(int index)
{
	assert(index >= 0);
	assert(index < size);
	assert(this->size > 0);
	Type storedValue;
	ArrayNode<Type> * current = head;
	ArrayNode<Type> * previousSpot;
	ArrayNode<Type> * newNext;

	for (int spot = 0; spot < index + 1; spot++)
	{
		if (spot == index - 1)
		{
			previousSpot = current;
		}
		if (spot == index)
		{
			storedValue = current->getValue();
			newNext = current->getNext();
			delete current;
		}

		current = current->getNext();
	}

	previousSpot->setNext(newNext);

	return storedValue;
}
template<class Type>
Type CTECLists<Type>::removeFromEnd()
{
	assert(size > 0);

	Type returnValue;

	if (size == 1)
	{
		ArrayNode<Type> * toRemove = end;
		returnValue = removeFromFront();
		end = nullptr;
		delete toRemove;
	}
	else
	{
		ArrayNode<Type> * current = head;

		for (int spot = 0; spot < size - 1; spot++)
		{
			current = current->getNext();
		}

		returnValue = end->getValue();
		delete end;
		current = end;
		current->setNext(nullptr);
	}
}
template<class Type>
Type CTECLists<Type>::getEnd()
{
	return end->getValue();

}
template<class Type>
Type CTECLists<Type>::getFront()
{
	return head->getValue();
}
template<class Type>
Type CTECLists<Type>::set(int pos, const Type& value)
{

	assert(pos < size && pos >= 0);
	ArrayNode<Type> * current = head;
	Type returnValue;

	for (int spot = 0; spot <= pos; spot++)
	{
		if (spot != pos)
		{
			current = current->getNext();
		}
		else
		{
			returnValue = current->getValue();
			current->setValue(value);
		}

	}

	return returnValue;

}

template<class Type>
Type CTECLists<Type>::getFromIndex(int index)
{
	ArrayNode<Type> * current = head;
	Type valueHolder;

	assert(index >= 0);
	assert(index < size);
	assert(this->size > 0);

	for (int spot = 0; spot <= index; spot++)
	{
		if (spot != index)
		{
			current->getNext();
		}
		else
		{
			valueHolder = current->getValue();
		}
	}

	return valueHolder;

}

template<class Type>
void CTECLists<Type>::claculateSize()
{
	assert(size >= 0);
	int count = 0;
	if (head == nullptr)
	{
		size = count;
	}
	else
	{
		count++;
		ArrayNode<Type> * current = head;
		while(current->getNext() != nullptr)
		{
			current = current->getNext();
		}
	}
	size = count;
}



template<class Type>
int CTECLists<Type>::getSize()
{
	return size;
}




