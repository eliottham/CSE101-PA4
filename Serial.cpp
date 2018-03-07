// CSE 101 Winter 2018, PA 4
//
// Name: Eliott Ham
// PID: A13186685
// Sources of Help: Piazza
// Due: March 10th, 2018 at 11:59 PM

#ifndef __SERIAL_CPP__
#define __SERIAL_CPP__

#include "Serial.hpp"
using namespace std;

int serial(std::vector<int> nums) {
  int half = nums.size() / 2;

  int start = nums[0];
  int mid = start + half;

  if(nums.size() == 1) {
  	return nums[0];
  }

  if(nums[half] < mid) {
  	vector<int> first_half(nums.begin(), nums.begin() + half);
  	return serial(first_half);
  }
  else {
  	vector<int> second_half(nums.begin() + half, nums.end());
  	return serial(second_half);
  }
}
#endif