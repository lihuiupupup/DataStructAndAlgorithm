#pragma once
#ifndef MAX_SUB_SEQUENCE_SUM_H_
#define MAX_SUB_SEQUENCE_SUM_H_
#include <vector>

using namespace std;

//最大子序列和
class MaxSubSequenceSum
{
	public:
		MaxSubSequenceSum();
		~MaxSubSequenceSum();
		int solution1(const vector<int>  & arr);
		int solution2(const vector<int>  & arr);
		int solution3(const vector<int>  & arr);
		int solution4(const vector<int>  & arr);
	private:
		int getMaxSubSequenceSum(const vector<int> & arr, int  left, int  right);
		int getMaxInThree(int one, int two, int three);
};




#endif // !MAX_SUB_SEQUENCE_SUM_H_

