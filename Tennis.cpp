// CSE 101 Winter 2018, PA 4
//
// Name: Eliott Ham
// PID: A13186685
// Sources of Help: Piazza
// Due: March 10th, 2018 at 11:59 PM

#ifndef __TENNIS_CPP__
#define __TENNIS_CPP__

#include "Tennis.hpp"
#include <iostream>
using namespace std;

bool compare(Interval lhs, Interval rhs)
{
	return lhs.start < rhs.start;
}


int tennis(std::vector<Interval> lessons) {
	sort(lessons.begin(), lessons.end(), compare);

	vector<Interval> courts; // If a lesson does not fit within the optimal time of
							   // a previous lesson, we add it to a new court

	courts.push_back(lessons[0]);

	for(int i = 1; i < lessons.size(); i++) {
		for(int j = 0; j < courts.size(); j++) {
			if(lessons[i].start >= courts[j].end) {
				courts[j] = lessons[i];
				break;
			}

			if(j == courts.size() - 1) {
				courts.push_back(lessons[i]);
				break;
			}
		}
	}

	return courts.size();
}
#endif
