#include "LogNAlgorithm.h"

LogNAlgorithm::LogNAlgorithm()
{
}

LogNAlgorithm::~LogNAlgorithm()
{
}

/*
二分查找 时间复杂度 T(N) = O(logN)
arr为升序数组 返回x在集合中的下标
*/
int LogNAlgorithm::binarySearch(const vector<int>& arr, const int x)
{
	int left = 0;
	int right = arr.size() - 1;
	int mid;
	//当左边界小于等于右边界
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
欧几里得算法 最大公约数 T(N) = O(logN) 
greatest common divider
*/
int LogNAlgorithm::gcd(int x,int y)
{
	//不能整除继续向下走 除数变被除数 余数变除数 
	while (x % y != 0)
	{
		int z = x % y;
		x = y;
		y = z;
	}
	return y;
}
/*
幂运算 递归降指数
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
