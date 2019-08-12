// DataStructAndAlgorithm.cpp : 定义控制台应用程序的入口点。
//


#include <iostream>
#include "MaxSubSequenceSum.h"
#include "LogNAlgorithm.h"
#include "MyVector.h"
#include "MyStack.h"
#include "StackAlgorithm.h"
#include "MyQueue.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"
using namespace std;
int compareTo(int num1, int num2);
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

	//简单向量
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

	//简单数组栈
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

	//栈的简单应用
	/*StackAlgorithm stackAlgorithm;

	cout << stackAlgorithm.checkBrackets("()[]") << endl;
	cout << stackAlgorithm.checkBrackets("(1+3)-[4*4]}") << endl;

	string str = "(1+4)*2";

	cout << "the post exp:" << stackAlgorithm.infixExp2PostExp(str) << endl;
	cout << "the value is:"<<stackAlgorithm.valueOfExp(str) << endl;*/


	//队列
	/*MyQueue<int> myQueue;
	myQueue.push(9);
	myQueue.push(9);
	myQueue.pop();
	for (int i =0 ;i < 3;i++)
	{
		cout << "capacity:"<<myQueue.getCapacity()<<"size:"<<myQueue.getSize() << endl;
		myQueue.push(i);
	}
	MyQueue<int> my;
	my = myQueue;
	myQueue.pop();
	for (int i = 0; i < 3; i++)
	{
		cout << "capacity:" << my.getCapacity() << "size:" << my.getSize() << endl;
		cout << my.pop() << endl;;
	}

	for (int i = 0; i < 3; i++)
	{
		cout << "capacity:" << myQueue.getCapacity() << "size:" << myQueue.getSize() << endl;
		cout << myQueue.pop() << endl;;
	}*/

	//二叉搜索树
	BinarySearchTree<int> * tree = new BinarySearchTree<int>(compareTo);
	for (int i = 0; i < 10; i++)
	{
		tree->insert(i);
	}
	
	tree->insert(-2);
	tree->insert(-1);
	tree->insert(-3);
	tree->insert(49);
	tree->remove(-1);
	tree->print();
	cout << "lihui" << tree->findMax() << endl;
	cout << "lihui" << tree->findMin() << endl;
	tree->empty();
	cout << "lihui" << endl;
	tree->insert(-3);
	cout << "lihui" << tree->contains(-2) << endl;
	cout << "lihui" << tree->contains(-3) << endl;
	

	//AVL树
	/*AVLTree<int> * tree = new AVLTree<int>(compareTo);
	for(int i = 1;i <=90 ;i++)
	tree->insert(i);
	tree->remove(6);
	tree->print();*/

	
	cin.get();
	return 0;
}

int compareTo(int num1, int num2)
{
	return num1 - num2;
}

