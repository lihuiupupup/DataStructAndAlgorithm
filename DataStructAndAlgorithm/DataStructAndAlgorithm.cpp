// DataStructAndAlgorithm.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include <iostream>
#include "MaxSubSequenceSum.h"
using namespace std;

int main()
{
	//��������кͲ���
	MaxSubSequenceSum maxSubSequenceSum;
	vector<int> arr = {-2,29,-7,-2,7,4};
	cout << "max sum with solution1:" << maxSubSequenceSum.solution1(arr) << endl;
	cout << "max sum with solution2:" << maxSubSequenceSum.solution2(arr) << endl;
	cout << "max sum with solution3:" << maxSubSequenceSum.solution3(arr) << endl;
	cout << "max sum with solution4:" << maxSubSequenceSum.solution4(arr) << endl;
	cin.get();
    return 0;
}

