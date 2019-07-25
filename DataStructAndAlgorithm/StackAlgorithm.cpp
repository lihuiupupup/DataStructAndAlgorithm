
#include "StackAlgorithm.h"

StackAlgorithm::StackAlgorithm()
{

}

StackAlgorithm::~StackAlgorithm()
{
}
/*
检测表达式括号是否正确
*/
bool StackAlgorithm::checkBrackets(string str)
{
	MyStack<char> stack;
	int count = 0;
	while (count < (int)str.size())
	{
		char ch = str[count++];
		
		//左括号入栈
		if (ch == '(' || ch == '[' || ch == '{')
		{
			stack.push(ch);		
		}

		if (ch == ')')
		{
			if (stack.isEmpty()) //栈为空 错误
			{
				return false;
			}
			char temp = stack.pop();
			
			if (temp != '(') //出栈和当前不匹配 错误
			{
				return false;
			}
		}
		if (ch == ']')
		{
			if (stack.isEmpty())
			{
				return false;
			}
			char temp = stack.pop();
			
			if (temp != '[')
			{
				return false;
			}
		}
		if (ch == '}')
		{
			if (stack.isEmpty())
			{
				return false;
			}
			char temp = stack.pop();
			
			if (temp != '{')
			{
				return false;
			}
		}

		
	}

	if (stack.isEmpty()) //遍历结束 栈为空正确 否则错误
	{
		return true;
	}
	return false;
}

/*
前缀编中缀表达式
*/
string  StackAlgorithm::infixExp2PostExp(string & str)
{
	string str2;
	int size = (int)str.size();
	int count = 0;
	map<char, int> myMap = { {'+',1},{'-',1},{'*',2},{'/',2} ,{'(',10},{')',10} }; //定义一个映射 判断优先级

	MyStack<char> stack;
	while (count < size) //遍历所有字符
	{
		char ch = str[count++]; //获取字符 并向后推进
		
		if (isNum(ch)) //如果是数字 直接输出到结果集
		{
			str2.push_back(ch);	
		}
		else 
		{
		
			
			if (stack.isEmpty()) //如果栈为空 直接进入 继续循环
			{
				stack.push(ch);
				continue;
			}
			int num1 = myMap[ch]; //获取栈外元素优先级
			char ch2 = stack.top();
			int num2 = myMap[ch2]; //获取栈顶元素优先级
			if (ch == ')') //如果遇到）出栈知道（
			{
				char temp2;
				while (( temp2 = stack.pop()) != '(') //特别注意 = 和 ！= 的优先级 不然出现笑脸
				{
					str2.push_back(temp2);
				}
					
			}
			else if (ch == '(') //如果遇到（直接入栈
			{
				stack.push(ch);
			}
			else
			{
				while (num1 <= num2) //排除（）特殊情况后 就可以按优先级入栈出栈了
				{
					if (stack.top() == '(') //防止循环过程中 出栈遇到（  除了） 都不能出栈（
					{
						break;
					}
					char temp = stack.pop(); //栈顶优先级大于等于 栈外就要出栈
						
					str2.push_back(temp); //保存在结果集
						
					if (stack.isEmpty()) //防止循环过程中 空栈继续执行 导致异常
					{
						break;
					}
					char ch2 = stack.top(); //获取新的栈顶元素
					int num2 = myMap[ch2];	//更新栈顶优先级				
						
				}
				if (ch != ')') //循环结束 栈外元素优先级高于栈顶  或者 空栈情况 将栈外元素入栈
				{
					stack.push(ch);
					
				}
			}
				
			
				
			
		}
		
	}
	while (!stack.isEmpty()) //遍历结束 将栈中元素依次出栈
	{
		str2.push_back(stack.pop());
	}
	return str2;
}

bool StackAlgorithm::isNum(char ch)
{
	return ch >= 48 && ch <= 57;
}
