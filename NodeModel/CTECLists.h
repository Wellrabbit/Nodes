/*
 * CTECLists.h
 *
 *  Created on: Feb 29, 2016
 *      Author: eort3611
 */

#ifndef NODEMODEL_CTECLISTS_H_
#define NODEMODEL_CTECLISTS_H_
#include "ArrayNode.h"
#include <iostream>
#include <assert.h>
using namespace std;
template <class Type>
class CTECLists
{
private:
int size;
ArrayNode<Type> * head;
ArrayNode<Type> * end;
void claculateSize();
public:
	CTECLists();
	virtual ~CTECLists();
	void addAtIndex(int index, const Type& value);
	void addToEnd(const Type& value);
	void addToFront(const Type& value);\
	Type removeFromFront();
	Type removeFromIndex(int index);
	Type removeFromEnd();
	Type getEnd();
	Type getFront();
	Type getFromIndex(int index);
	Type set(int index, const Type& Value);
	int getSize();
    void swap(int indexOne, int indexTwo);
    void selectionSort;


};

#endif /* NODEMODEL_CTECLISTS_H_ */
