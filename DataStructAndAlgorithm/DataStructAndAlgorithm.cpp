// DataStructAndAlgorithm.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include <iostream>
#include "MaxSubSequenceSum.h"
#include "LogNAlgorithm.h"
#include "MyVector.h"
#include "MyStack.h"
#include "StackAlgorithm.h"
using namespace std;

int main()
{
	//��������кͲ���
	/*MaxSubSequenceSum maxSubSequenceSum;
	vector<int> arr = {-2,29,-7,-2,7,4};
	cout << "max sum with solution1:" << maxSubSequenceSum.solution1(arr) << endl;
	cout << "max sum with solution2:" << maxSubSequenceSum.solution2(arr) << endl;
	cout << "max sum with solution3:" << maxSubSequenceSum.solution3(arr) << endl;
	cout << "max sum with solution4:" << maxSubSequenceSum.solution4(arr) << endl;*/

	//ʱ�临�Ӷ�Ϊ�����ĳ����㷨
	/*LogNAlgorithm logNAlgorithm;
	vector<int> arr1 = { 1,2,3,4,5,6 };
	int index = logNAlgorithm.binarySearch(arr1, 8);
	cout << "the index is:" << index << endl;
	int gcd = logNAlgorithm.gcd(34, 85);
	cout << "the gcd:" << gcd << endl;
	int pow = logNAlgorithm.pow(11, 3);
	cout << "the pow:" << pow << endl;*/

	//������
	//MyVector<int> myVector;
	//try
	//{
	//	myVector.back();
	//}
	//catch (const std::exception& e)
	//{
	//	cout <<  "err"<< e.what()  << endl;
	//}
	//
	//for (int i = 0; i < 9; i++)
	//{
	//	myVector.push_back(i);
	//	cout << "capatity:" << myVector.getCapacity() << "size:" << myVector.getSize() << endl;
	//}
	//cout << "back:" << myVector.back() << endl;
	//myVector.pop_back();
	//cout << "back:" << myVector.back() << endl;

	//cout << myVector[0];

	//������ջ
	/*MyStack<int> myStack;
	myStack.push(10);
	myStack.push(140);
	myStack.push(1320);
	myStack.push(130);
	cout << myStack.size() << endl;
	cout << myStack.pop() << endl;
    cout << myStack.pop() << endl;
	cout << myStack.pop() << endl;
	cout << myStack.pop() << endl;
	try
	{
		cout << myStack.pop() << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}*/

	//ջ�ļ�Ӧ��
	StackAlgorithm stackAlgorithm;

	cout << stackAlgorithm.checkBrackets("()[]") << endl;
	cout << stackAlgorithm.checkBrackets("(1+3)-[4*4]}") << endl;

	string str = "(1+4)*2";
	
	cout << "the post exp:" << stackAlgorithm.infixExp2PostExp(str) << endl;
	cout << "the value is:"<<stackAlgorithm.valueOfExp(str) << endl;
	
	
	cin.get();
    return 0;
}

