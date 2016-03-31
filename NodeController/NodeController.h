/*
 * NodeController.h
 *
 *  Created on: Jan 27, 2016
 *      Author: eort3611
 */

#ifndef NODECONTROLLER_NODECONTROLLER_H_
#define NODECONTROLLER_NODECONTROLLER_H_
#include <string>

#include "../NodeModel/ArrayNode.cpp"
#include "../NodeModel/ArrayNode.h"
#include "../NodeModel/Node.cpp"
#include "../NodeModel/Node.h"
#include "../NodeModel/Timer.h"
#include "CTECArray.h"
#include "CTECArray.cpp"
#include "../NodeModel/CTECLists.h"
#include "../NodeModel/CTECLists.cpp"
using namespace std;

class NodeController {
private:
	//Node<string> stringNode;
	//Node<int> intNode;
	//ArrayNode<string> stringArrayNode;
	//ArrayNode<string> otherArrayNode;
	CTECArray<int> * notHipsterEnough;
	Timer arrayTimer;
	CTECLists<int> * numbers;
  //  void sortData;
    
    int * mergeData;
    void doMergesort();
    void mergesort(int data[], int size);
    void merge(int data[], int sizeOne, int sizeTwo);
public:
	NodeController();
	virtual ~NodeController();
	void start();
	void testLists();
};

#endif /* NODECONTROLLER_NODECONTROLLER_H_ */
