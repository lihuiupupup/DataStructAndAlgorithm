#pragma once
#ifndef STACK_ALGORITHM_H_
#define STACK_ALGORITHM_H_
#include <string>
#include "MyStack.h"
#include <iostream>
#include <map>
using namespace std;

class StackAlgorithm
{
public:
	StackAlgorithm();
	~StackAlgorithm();
	bool checkBrackets(string str);
	string infixExp2PostExp(string & str);
	bool isNum(char ch);
	int postExpforResult(string & str);
	int valueOfExp(string & str);
private:

};



#endif // !STACK_ALGORITHM_H_

