// DataStructAndAlgorithm.cpp : 定义控制台应用程序的入口点。
//


#include <iostream>
#include "MaxSubSequenceSum.h"
#include "LogNAlgorithm.h"
#include "MyVector.h"
using namespace std;

int main()
{
	//最大子序列和测试
	/*MaxSubSequenceSum maxSubSequenceSum;
	vector<int> arr = {-2,29,-7,-2,7,4};
	cout << "max sum with solution1:" << maxSubSequenceSum.solution1(arr) << endl;
	cout << "max sum with solution2:" << maxSubSequenceSum.solution2(arr) << endl;
	cout << "max sum with solution3:" << maxSubSequenceSum.solution3(arr) << endl;
	cout << "max sum with solution4:" << maxSubSequenceSum.solution4(arr) << endl;*/

	//时间复杂度为对数的常见算法
	/*LogNAlgorithm logNAlgorithm;
	vector<int> arr1 = { 1,2,3,4,5,6 };
	int index = logNAlgorithm.binarySearch(arr1, 8);
	cout << "the index is:" << index << endl;
	int gcd = logNAlgorithm.gcd(34, 85);
	cout << "the gcd:" << gcd << endl;
	int pow = logNAlgorithm.pow(11, 3);
	cout << "the pow:" << pow << endl;*/

	MyVector<int> myVector;
	try
	{
		myVector.back();
	}
	catch (const std::exception& e)
	{
		cout <<  "err"<< e.what()  << endl;
	}
	
	for (int i = 0; i < 9; i++)
	{
		myVector.push_back(i);
		cout << "capatity:" << myVector.getCapacity() << "size:" << myVector.getSize() << endl;
	}
	cout << "back:" << myVector.back() << endl;
	myVector.pop_back();
	cout << "back:" << myVector.back() << endl;

	cout << myVector[0];
	cin.get();
    return 0;
}

