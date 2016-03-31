/*
 * NodeController.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: eort3611
 */

#include "NodeController.h"
#include <iostream>
using namespace std;


NodeController::NodeController()
{

//stringNode.setValue("asdsads");
//intNode.setValue(999);
//stringArrayNode.setValue("Words");
//otherArrayNode.setValue("Link");
//stringArrayNode.setNext(&otherArrayNode);

	notHipsterEnough = new CTECArray<int>(5);
}

NodeController::~NodeController()
{
	// TODO Auto-generated destructor stub
}

void NodeController::start()
{
	arrayTimer.startTimer();
	for (int index = 0; index < notHipsterEnough->getSize(); index++)
	{
		notHipsterEnough->set(index, (index * 7));
	}

	for (int index = notHipsterEnough->getSize() - 1; index >= 0; index--)
	{
		cout << "The spot is" << index << "And the place is"
				<< notHipsterEnough->get(index) << endl;
	}
	//testLists();
	arrayTimer.stopTimer();
	arrayTimer.displayTimerInfo();

}

void NodeController::testLists()
{
	numbers->addToFront(3);

	numbers->addToEnd(8);

	numbers->addAtIndex(1, 10);



	cout << "End should be 8 and is: " << numbers->getEnd() << endl;

	cout << "Head should be 3 and is: " << numbers->getFront() << endl;

	cout << "Index of 1 should be 10 and is:" << numbers->getFromIndex(1) << endl;

	cout << "Current size of numbers should be 3 and is" << numbers->getSize() << endl;


}

void NodeController::doMergesort()
{
    mergeData = new int[500000];
    
    for(int spot = 0; spot < 500000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    for (int spot = 0; spot < 5000; spot++)
    {
        cout << mergeData[spot] << "," ;
    }
    
    Timer mergeTimer;
    mergeTimer.startTimer();
    mergesort(mergeData, 5000000);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInfo();
    
    for (int spot = 0; spot < 5000; spot++)
    {
        cout << mergeData[spot] << ",";
    }
    
    delete [] mergeData;
}

void NodeController::mergesort(int data[], int size)
{
    int sizeOne;
    int sizeTwo;
    
    if(size >1)
    {
        sizeOne = size/2;
        sizeTwo = size-sizeOne;
        
        mergesort(data, sizeOne);
        mergesort((data+sizeOne), sizeTwo);
        
        mergesort(data, sizeOne, sizeTwo);
    }
}
//void NodeController::sortData()
//{

//}