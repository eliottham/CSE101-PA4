// CSE 101 Winter 2018, PA 4
//
// Name: Eliott Ham
// PID: A13186685
// Sources of Help: Piazza
// Due: March 10th, 2018 at 11:59 PM

#ifndef __ICE_CPP__
#define __ICE_CPP__

#include "Ice.hpp"

int ice(TwoD_Array<int> rooms)
{
	pair<int, int> min_curr; // Pair to keep track of minimum ice to reach (i, j) and 
							 // current amount of ice at that point
	TwoD_Array<pair<int, int>> key(rooms.getNumRows(), rooms.getNumCols());

	if(rooms.at(0, 0) >= 0) {
		int min = rooms.at(0, 0) + 1;
		key.at(0, 0) = make_pair(min, 1);
	}
	else {
		int curr = abs(rooms.at(0, 0) - 1);
		key.at(0, 0) = make_pair(1, curr);
	}

	for(unsigned int i = 1; i < rooms.getNumRows(); i++) {
		int curr = key.at(i - 1, 0).second - rooms.at(i, 0);

		if(curr > 0) {
			key.at(i, 0) = make_pair(key.at(i - 1, 0).first, curr);
		}
		else {
			int min = key.at(i - 1, 0).first + (1 - curr);
			key.at(i, 0) = make_pair(min, 1);
		}
	}

	for(unsigned int j = 1; j < rooms.getNumCols(); j++) {
		int curr = key.at(0, j - 1).second - rooms.at(0, j);

		if(curr > 0) {
			key.at(0, j) = make_pair(key.at(0, j - 1).first, curr);
		}
		else {
			int min = key.at(0, j - 1).first + (1 - curr);
			key.at(0, j) = make_pair(min, 1);
		}
	}

	
	

	for(unsigned int i = 1; i < rooms.getNumRows(); i++) {
		for(unsigned int j = 1; j < rooms.getNumCols(); j++) {
			pair<int, int> top;
			int t_curr = key.at(i - 1, j).second - rooms.at(i, j);

			if(t_curr > 0) {
				top.first = key.at(i - 1, j).first;
				top.second = t_curr;
			}
			else {
				int t_min = key.at(i - 1, j).first + (1 - t_curr);
				top.first = t_min;
				top.second = 1;
			}

			pair<int, int> left;
			int l_curr = key.at(i, j - 1).second - rooms.at(i, j);

			if(l_curr > 0) {
				left.first = key.at(i, j - 1).first;
				left.second = l_curr;
			}
			else {
				int l_min = key.at(i, j - 1).first + (1 - l_curr);
				left.first = l_min;
				left.second = 1;
			}

			if(top.first < left.first) {
				key.at(i, j) = top;
			}
			else {
				key.at(i, j) = left;
			}
		}
	}

	return key.at(rooms.getNumRows() - 1, rooms.getNumCols() - 1).first;
}
#endif
