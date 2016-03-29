/*
 * ArrayNode.h
 *
 *  Created on: Jan 29, 2016
 *      Author: eort3611
 */

#ifndef NODEMODEL_ARRAYNODE_H_
#define NODEMODEL_ARRAYNODE_H_

#include "../NodeModel/Node.h"
template <class Type>
class ArrayNode: public Node<Type>
{
private:
	ArrayNode<Type> * next;
public:
	ArrayNode<Type>();
	ArrayNode(const Type& value);
	ArrayNode(const Type& value, ArrayNode<Type> * next);
	virtual ~ArrayNode();
	ArrayNode<Type> * getNext();
	void setNext(ArrayNode<Type> * next);
	Type value;
    void swap(int indexOne, int indexTwo);
};

#endif /* NODEMODEL_ARRAYNODE_H_ */
