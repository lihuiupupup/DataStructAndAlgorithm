#include "LogNAlgorithm.h"

LogNAlgorithm::LogNAlgorithm()
{
}

LogNAlgorithm::~LogNAlgorithm()
{
}

/*
���ֲ��� ʱ�临�Ӷ� T(N) = O(logN)
arrΪ�������� ����x�ڼ����е��±�
*/
int LogNAlgorithm::binarySearch(const vector<int>& arr, const int x)
{
	int left = 0;
	int right = arr.size() - 1;
	int mid;
	//����߽�С�ڵ����ұ߽�
	while (left <= right)
	{
		mid = (right + left) / 2;
		if (x == arr[mid])
		{
			return mid;
		}
		else if (x > arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}
/*
ŷ������㷨 ���Լ�� T(N) = O(logN) 
greatest common divider
*/
int LogNAlgorithm::gcd(int x,int y)
{
	//������������������ �����䱻���� ��������� 
	while (x % y != 0)
	{
		int z = x % y;
		x = y;
		y = z;
	}
	return y;
}
/*
������ �ݹ齵ָ��
*/
int LogNAlgorithm::pow(int x, int n)
{
	if (n == 0)
	{
		return 1;
	}

	
	
	if (n % 2 == 0)
	{
		return pow(x * x, n / 2);
	}
	else
	{
		return pow(x * x, n / 2) * x;
	}
	
}
