/*
 * CTECArray.h
 *
 *  Created on: Feb 2, 2016
 *      Author: eort3611
 */

#ifndef NODECONTROLLER_CTECARRAY_H_
#define NODECONTROLLER_CTECARRAY_H_
#include "../NodeModel/ArrayNode.h"
template <class Type>
class CTECArray {
private:
	int size;
	ArrayNode<Type> * head;
public:
	CTECArray(int size);
	virtual ~CTECArray();
	int getSize();
	void set(int position, const Type& value);
	Type get(int position);

};

#endif /* NODECONTROLLER_CTECARRAY_H_ */
