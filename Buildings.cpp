// CSE 101 Winter 2018, PA 4
//
// Name: Eliott Ham
// PID: A13186685
// Sources of Help: Piazza
// Due: March 10th, 2018 at 11:59 PM

#ifndef __BUILDINGS_CPP__
#define __BUILDINGS_CPP__

#include "Buildings.hpp"

int buildings(TwoD_Array<int> survey)
{
	queue<pair<int, int>> q;
	int count = 0;

	for(unsigned int i = 0; i < survey.getNumRows(); i++) {
		for(unsigned int j = 0; j < survey.getNumCols(); j++) {
			if(survey.at(i, j) == 1) {
				count++;
				q.push(make_pair(i, j));

				while(!q.empty()) {
					int row = q.front().first;
					int col = q.front().second;
					survey.at(row, col) = 0;
					q.pop();

					if(row - 1 >= 0) {
						if(survey.at(row - 1, col) == 1) q.push(make_pair(row - 1, col));
					}
					if(col - 1 >= 0) {
						if(survey.at(row, col - 1) == 1) q.push(make_pair(row, col - 1));
					}
					if(row + 1 < survey.getNumRows()) {
						if(survey.at(row + 1, col) == 1) q.push(make_pair(row + 1, col));
					}
					if(col + 1 < survey.getNumCols()) {
						if(survey.at(row, col + 1) == 1) q.push(make_pair(row, col + 1));
					}
				}
			}
		}
	}

	return count;	
}
#endif
