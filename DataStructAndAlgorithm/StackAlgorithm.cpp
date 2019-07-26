
#include "StackAlgorithm.h"

StackAlgorithm::StackAlgorithm()
{

}

StackAlgorithm::~StackAlgorithm()
{
}
/*
�����ʽ�����Ƿ���ȷ
*/
bool StackAlgorithm::checkBrackets(string str)
{
	MyStack<char> stack;
	int count = 0;
	while (count < (int)str.size())
	{
		char ch = str[count++];
		
		//��������ջ
		if (ch == '(' || ch == '[' || ch == '{')
		{
			stack.push(ch);		
		}

		if (ch == ')')
		{
			if (stack.isEmpty()) //ջΪ�� ����
			{
				return false;
			}
			char temp = stack.pop();
			
			if (temp != '(') //��ջ�͵�ǰ��ƥ�� ����
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

	if (stack.isEmpty()) //�������� ջΪ����ȷ �������
	{
		return true;
	}
	return false;
}

/*
ǰ׺����׺���ʽ
*/
string  StackAlgorithm::infixExp2PostExp(string & str)
{
	string str2;
	int size = (int)str.size();
	int count = 0;
	map<char, int> myMap = { {'+',1},{'-',1},{'*',2},{'/',2} ,{'(',10},{')',10} }; //����һ��ӳ�� �ж����ȼ�

	MyStack<char> stack;
	while (count < size) //���������ַ�
	{
		char ch = str[count++]; //��ȡ�ַ� ������ƽ�
		
		if (isNum(ch)) //��������� ֱ������������
		{
			str2.push_back(ch);	
		}
		else 
		{
		
			
			if (stack.isEmpty()) //���ջΪ�� ֱ�ӽ��� ����ѭ��
			{
				stack.push(ch);
				continue;
			}
			int num1 = myMap[ch]; //��ȡջ��Ԫ�����ȼ�
			char ch2 = stack.top();
			int num2 = myMap[ch2]; //��ȡջ��Ԫ�����ȼ�
			if (ch == ')') //�����������ջ֪����
			{
				char temp2;
				while (( temp2 = stack.pop()) != '(') //�ر�ע�� = �� ��= �����ȼ� ��Ȼ����Ц��
				{
					str2.push_back(temp2);
				}
					
			}
			else if (ch == '(') //���������ֱ����ջ
			{
				stack.push(ch);
			}
			else
			{
				while (num1 <= num2) //�ų�������������� �Ϳ��԰����ȼ���ջ��ջ��
				{
					if (stack.top() == '(') //��ֹѭ�������� ��ջ������  ���ˣ� �����ܳ�ջ��
					{
						break;
					}
					char temp = stack.pop(); //ջ�����ȼ����ڵ��� ջ���Ҫ��ջ
						
					str2.push_back(temp); //�����ڽ����
						
					if (stack.isEmpty()) //��ֹѭ�������� ��ջ����ִ�� �����쳣
					{
						break;
					}
					char ch2 = stack.top(); //��ȡ�µ�ջ��Ԫ��
					int num2 = myMap[ch2];	//����ջ�����ȼ�				
						
				}
				if (ch != ')') //ѭ������ ջ��Ԫ�����ȼ�����ջ��  ���� ��ջ��� ��ջ��Ԫ����ջ
				{
					stack.push(ch);
					
				}
			}
				
			
				
			
		}
		
	}
	while (!stack.isEmpty()) //�������� ��ջ��Ԫ�����γ�ջ
	{
		str2.push_back(stack.pop());
	}
	return str2;
}

bool StackAlgorithm::isNum(char ch)
{
	return ch >= 48 && ch <= 57;
}

/*
������Ϊ0-9������ ���ʽ��ֵ 
��Ϊ��׺ת��׺ʱ û�зָ������ ��������׺ת��׺ʱ ������������ʱ�������#����Ϊ���������� ���������ַ�Ϊ�洢�����´���С���ȶ�������
*/
int StackAlgorithm::postExpforResult(string & str)
{
	MyStack<char> stack;
	int size = str.size();
	int count = 0;
	while (count < size)
	{
		char ch = str[count++];
		if (isNum(ch))
		{
			stack.push(ch);
		}
		else
		{
			int num2 = stack.pop() - 48;
			int num1 = stack.pop() - 48;
			int num3 = 0;
			if (ch == '+')
			{
				num3 = num1 + num2;
			}
			else if (ch == '-')
			{
				num3 = num1 - num2;
			}
			else if (ch == '*')
			{
				num3 = num1 * num2;
			}
			else if (ch == '/')
			{
				num3 = num1 / num2;
			}

			stack.push(num3 + 48);
		}
	}
	return stack.pop() - 48;
}

int StackAlgorithm::valueOfExp(string & str)
{
	string postExp = infixExp2PostExp(str);
	return postExpforResult(postExp);
}
