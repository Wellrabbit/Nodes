/*
 * Node.h
 *
 *  Created on: Jan 27, 2016
 *      Author: eort3611
 */

#ifndef NODEMODEL_NODE_H_
#define NODEMODEL_NODE_H_

template <class Type>
class Node {
private:
	Type value;
	Node * pointers;
public:
	Node();
	Node(const Type& value);
	~Node();
	Type getValue();
	void setValue(const Type& value);
	Node * getPointers();


};

#endif /* NODEMODEL_NODE_H_ */
