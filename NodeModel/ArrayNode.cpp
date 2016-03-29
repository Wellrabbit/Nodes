/*
 * ArrayNode.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: eort3611
 */

#include "../NodeModel/ArrayNode.h"

#include <iostream>
template <class Type>
ArrayNode<Type>::ArrayNode() : Node<Type>()
{
	this->next = nullptr;

}
template <class Type>
ArrayNode<Type> :: ArrayNode(const Type& value) :Node<Type>(value)
{
	this->next = nullptr;
	this->value = value;
}

template <class Type>
ArrayNode<Type> :: ArrayNode(const Type& value, ArrayNode<Type> * next) : Node<Type>(value)
{
	this->value = value;
	this->next = next;
}
template <class Type>
ArrayNode<Type>::~ArrayNode() {
	// TODO Auto-generated destructor stub
}

template <class Type>
ArrayNode<Type> * ArrayNode<Type> :: getNext()
{
	return this->next;
}

template <class Type>
void ArrayNode<Type> :: setNext(ArrayNode<Type> * next)
{
	 this->next = next;
}

//template <class Type>
//void ArrayNode<Type> :: swap(int indexOne, int indexTwo)
//{
//    assert(indexOne < size && indexTwo < size);
//   Type temp = getFromIndex(indexOne);
//    set(indexOne, getFromIndex(indexTwo));
//    set(indexTwo, temp);
//}
