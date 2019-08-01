#pragma once
#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_
using namespace std;
#include "MyQueue.h"
#include <iostream>
/*
二分查找树
*/
template <typename T>
class BinarySearchTree
{
public:
	/*
	定义 函数指针 由外部实现比较器
	*/
	typedef int (*Comarator)(T, T);
	/*
	Comparator为比较器 参数为可比较的对象 返回正数数目参数1> 参数2
	*/
	BinarySearchTree(Comarator comparator) :myComparator(comparator)
	{

	}
	~BinarySearchTree() 
	{
		traverseDelete();
	}

	T  findMax()
	{
		return internalFindMax(myRoot);
	}

	T  findMin()
	{
		return internalFindMin(myRoot);
	}

	bool contains(const T & t)
	{
		return internalContains(myRoot,t);
	}

	void empty()
	{
		traverseDelete();
	}

	bool remove(const T& t)
	{
		return internalDelete(myRoot, t, myRoot,false);
	}

	bool insert(const T & t) 
	{
		if (myRoot == NULL)
		{
			myRoot = new TreeNode(t, NULL, NULL);
			return true;
		}
		else
		{
			return internalInsert(myRoot, t);
		}
		
	}

	void print()
	{
		MyQueue<TreeNode *> myQueue;
		if (myRoot != NULL)
		{
			myQueue.push(myRoot);
			while (!myQueue.isEmpey())
			{
				TreeNode* temp = myQueue.pop();
				cout << temp->element << endl;
				if (temp->left != NULL)
				{
					myQueue.push(temp->left);
				}
				if (temp->right != NULL)
				{
					myQueue.push(temp->right);
				}
			}
		}
	}

private:
	Comarator myComparator;

	struct TreeNode
	{
		T element;
		TreeNode*  left;
		TreeNode*  right;
		TreeNode(T ele, TreeNode* l, TreeNode* r) :element(ele), left(l), right(r) {}
	};

	TreeNode* myRoot;

	bool internalInsert(TreeNode * & root , const T & t)
	{
		if (root == NULL)
		{
			root = new TreeNode(t, NULL, NULL);
			return true;
		}
		if(myComparator(t,root->element) > 0)
		{
			internalInsert(root->right, t);
		} 
		else if (myComparator(t, root->element) < 0)
		{
			internalInsert(root->left, t);
		}
		else
		{
			//重复元素不处理
			return true;
		}
		

	}

	bool internalDelete(TreeNode * & root, const T & t,TreeNode * & p,bool isLeft)
	{
		if (root == NULL) //如果为空表示没有该节点
		{
			return false;
		}
		else
		{
			if (myComparator(t, root->element) == 0)
			{
				if (root->left == NULL && root->right == NULL)
				{
					delete root;
					root = NULL;
					return true;
				}
				if (root->left != NULL && root->right == NULL)
				{
					if (p != NULL)
					{

						if (isLeft)
						{
							TreeNode* tmp = root->left;
							delete p->left;
							p->left = tmp;
						}
						else
						{
							
							TreeNode* tmp = root->left;
							delete p->left;
							p->left = tmp;
						}
					}
					
					return true;
				}
				if (root->left == NULL && root->right != NULL)
				{
					if (p != NULL)
					{
						if (isLeft)
						{
							TreeNode* tmp = root->right;
							delete p->left;
							p->left = tmp;
						}
						else
						{
							TreeNode * tmp = root->right;
							delete p->right;
							p->right = tmp;							
						}
					}
					
					return true;
				}
				if (root->left != NULL && root->right != NULL)
				{
					if (p != NULL)
					{
						TreeNode* min = root->right;
						TreeNode* pre = root;
						while (min != NULL)
						{
							pre = min;
							min = min->left;
						}
						root->element = pre->element;
						internalDelete(root->right, pre->element, root, false);	
						return true;
					}
				}
				
			}
			else if(myComparator(t, root->element) < 0)
			{
				internalDelete(root->left, t,root,true);
			}
			else
			{
				internalDelete(root->right, t,root,false);
			}

			return true;
		}
	}

	void traverseDelete()
	{
		if (myRoot == NULL)
		{
			return;
		}
		MyQueue<TreeNode *> myQueue;
		myQueue.push(myRoot);
		while (!myQueue.isEmpey())
		{
			TreeNode * temp = myQueue.pop();
			if (temp->left != NULL)
			{
				myQueue.push(temp->left);
			}
			if (temp->right != NULL)
			{
				myQueue.push(temp->right);
			}
			delete temp;
		}
		myRoot = NULL;
	}

	bool internalContains(TreeNode * & root,const T & t)
	{
		if (root == NULL)
		{
			return false;
		}
		int result = myComparator(t, root->element);
		if (result == 0)
		{
			return true;
		}
		else if(result > 0 )
		{
			internalContains(root->right, t);
		}
		else
		{
			internalContains(root->left, t);
		}
	}

	T  internalFindMax(TreeNode * root)
	{
		if (root == NULL)
		{
			return NULL;
		}
		TreeNode * temp = root;
		while (root != NULL)
		{
			temp = root;
			root = root->right;
		}
		return temp->element;
	}

	T internalFindMin(TreeNode *  root)
	{
		if (root == NULL)
		{
			return NULL;
		}
		TreeNode * temp = root;
		while (root != NULL)
		{
			temp = root;
			root = root->left;
		}
		return temp->element;
	}
};


#endif // !BINARY_SEARCH_TREE_H_
