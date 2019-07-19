// DataStructAndAlgorithm.cpp : 定义控制台应用程序的入口点。
//


#include <iostream>
#include "MaxSubSequenceSum.h"
using namespace std;

int main()
{
	//最大子序列和测试
	MaxSubSequenceSum maxSubSequenceSum;
	vector<int> arr = {-2,29,-7,-2,7,4};
	cout << "max sum with solution1:" << maxSubSequenceSum.solution1(arr) << endl;
	cout << "max sum with solution2:" << maxSubSequenceSum.solution2(arr) << endl;
	cout << "max sum with solution3:" << maxSubSequenceSum.solution3(arr) << endl;
	cout << "max sum with solution4:" << maxSubSequenceSum.solution4(arr) << endl;
	cin.get();
    return 0;
}

