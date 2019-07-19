#include "MaxSubSequenceSum.h"

MaxSubSequenceSum::MaxSubSequenceSum()
{
}

MaxSubSequenceSum::~MaxSubSequenceSum()
{
}

/*
穷举所有的子序列 找出最大的 i为子序列起始点 j为子序列终点 T(N) = O(N³)
*/
int MaxSubSequenceSum::solution1(const vector<int>& arr)
{
	int result = 0;
	int size = arr.size();
	for (int i = 0 ;i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			int tempSum = 0;
			for (int k = i; k <= j; k++)
			{
				tempSum += arr[k];
			}
			if (tempSum > result)
			{
				result = tempSum;
			}
		}

	}
	return result;
}

/*
方案1的优化 方案1存在重复子序列 
此方案去除终止标记 默认最后一个元素 保证穷举到了每一个子序列 并及时更新最大值
T(N) = O(N²)
*/
int MaxSubSequenceSum::solution2(const vector<int>& arr)
{
	int result = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		int tempSum = 0;
		for (int j = i ;j < arr.size(); j++) 
		{
			tempSum += arr[j];
			if (tempSum > result)
			{
				result = tempSum;
			}
		}
	}
	return result;
}

/*
通过递归和分治思想将时间复杂度降为 T(N) = O(NlogN)
分治思想时间复杂度和logN相关联
*/
int MaxSubSequenceSum::solution3(const vector<int>& arr)
{
	int result = getMaxSubSequenceSum(arr,0,arr.size() - 1);
	return result;
}

/*
分治为左右两部分 最大子序列和为  1左边最大子序列和  2右边最大子序列和  3包含中间边界的最大子序列和（该序列包含center）之一

*/
int MaxSubSequenceSum::getMaxSubSequenceSum(const vector<int> & arr,int  left,int  right)
{
	//基准情况 即集合只有一个元素时 返回自己
	if (left == right)
	{
		return arr[left];
	}

	int center = (left + right) / 2;

	//左边最大序列和
	int leftMaxSequenceSum = getMaxSubSequenceSum(arr,left,center);

	//左边最大序列和
	int rightMaxSequenceSum = getMaxSubSequenceSum(arr, center + 1, right);

	//左边界最大值
	int leftBoderMaxSum = 0;
	int leftBodertemp = 0;
	for (int i = center; i >= left; i-- )
	{
		leftBodertemp += arr[i];
		if (leftBodertemp > leftBoderMaxSum)
		{
			leftBoderMaxSum = leftBodertemp;
		}
	}

	//左边界最大值
	int rightBoderMaxSum = 0;
	int rightBodertemp = 0;
	for (int i = center + 1; i <= right; i++)
	{
		rightBodertemp += arr[i];
		if (rightBodertemp > rightBoderMaxSum)
		{
			rightBoderMaxSum = rightBodertemp;
		}
	}

	//边界最大子序列和
	int borderMaxSequenceSum = leftBoderMaxSum + rightBoderMaxSum;

	return getMaxInThree(leftMaxSequenceSum, rightMaxSequenceSum , borderMaxSequenceSum);

}

int MaxSubSequenceSum::getMaxInThree(int one, int two, int three)
{
	return one > two ? (one > three ? one : three) : (two > three ? two : three);
}

/*
线性时间复杂度 T(N) = O(N)
只需要扫描数据

*/
int MaxSubSequenceSum::solution4(const vector<int>& arr)
{
	int result = 0;
	int currentSum = 0;
	for (int i = 0;i < arr.size(); i++)
	{
		
		currentSum += arr[i];
		if (currentSum > result)
		{
			result = currentSum;
		} else if (currentSum < 0) 
		{
			currentSum = 0;
		}

	}
	return result;
}
