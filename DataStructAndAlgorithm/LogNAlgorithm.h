#pragma once
#ifndef LOGN_ALGORITHM_H_
#define LOGN_ALGORITHM_H_
#include <vector>
using namespace std;
/*
时间复杂度为对数的算法
*/
class LogNAlgorithm
{
public:
	LogNAlgorithm();
	~LogNAlgorithm();
	int binarySearch(const vector<int> & arr,const int x);
	int gcd(int x,int y);
	int pow(int x,int n);
private:
	
};



#endif // !LOGN_ALGORITHM_H_
