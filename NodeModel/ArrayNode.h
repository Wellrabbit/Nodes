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
	ArrayNode * next;
public:
	ArrayNode();
	ArrayNode(const Type& value);
	ArrayNode(const Type& value, ArrayNode * next);
	virtual ~ArrayNode();
	ArrayNode * getNext();
	void setNext(ArrayNode * next);
	Type value;
};

#endif /* NODEMODEL_ARRAYNODE_H_ */
