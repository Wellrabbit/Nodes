/*
 * Timer.h
 *
 *  Created on: Feb 16, 2016
 *      Author: eort3611
 */
#include <time.h>
#ifndef NODEMODEL_TIMER_H_
#define NODEMODEL_TIMER_H_

class Timer
{
private:
	clock_t executionTime;
public:
	Timer();
	void startTimer();
	virtual ~Timer();
	void stopTimer();
	void resetTimer();
	void displayTimerInfo();
	long getExecutionTimeInMicroSec();

};

#endif /* NODEMODEL_TIMER_H_ */
