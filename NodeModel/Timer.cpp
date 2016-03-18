/*
 * Timer.cpp
 *
 *  Created on: Feb 16, 2016
 *      Author: eort3611
 */

#include "Timer.h"
#include <time.h>
#include <iostream>
using namespace std;
#include <iomanip>

Timer::Timer()
{
	executionTime = 0;

}
void Timer::displayTimerInfo()
{
cout << fixed;
cout << setprecision(8);
cout << executionTime <<"us (microseconds) for the code" << endl;
cout << "it is" << float(executionTime)/CLOCKS_PER_SEC << "seconds" << endl;
}
void Timer::startTimer()
{
	executionTime = clock();
}
void Timer::stopTimer()
{
	executionTime = clock() - executionTime;
}
void Timer::resetTimer()
{
	executionTime = 0;
}
long Timer::getExecutionTimeInMicroSec()
{
	  return executionTime;
}
Timer::~Timer()
{
	// TODO Auto-generated destructor stub
}

