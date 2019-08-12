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

	void midPrint() {
		internalMidPrint(myRoot);
	}

	void beforePrint() {
		internalBeforePrint(myRoot);
	}

	void afterPrint() {
		internalAfterPrint(myRoot);
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

	/*
		插入 
		root 当前根节点
		t 要插入的元素
	*/
	bool internalInsert(TreeNode * & root , const T & t)
	{
		if (root == NULL) //如果节点为空表明找到合适的位置
		{
			root = new TreeNode(t, NULL, NULL);
			
		}
		if(myComparator(t,root->element) > 0) //表明在当前节点的右子树
		{
			internalInsert(root->right, t);
		} 
		else if (myComparator(t, root->element) < 0) //表明在当前节点的左子树
		{
			internalInsert(root->left, t);
		}
		else
		{
			//重复元素不处理
		}
		return true;

	}

	/*
	
		root 当前根节点
		t 要删除的元素
		p 当前节点的父亲节点
		isLeft 是不是在左子树删除
	*/
	bool internalDelete(TreeNode * & root, const T & t,TreeNode * & p,bool isLeft)
	{
		if (root == NULL) //如果为空表示没有该节点
		{
			return false;
		}
		else
		{
			if (myComparator(t, root->element) == 0) //找到该节点 
			{
				if (root->left == NULL && root->right == NULL) //表明当前节点是叶子节点 直接删除
				{
					delete root;
					root = NULL;
					return true;
				}
				if (root->left != NULL && root->right == NULL) //表明要删除节点的左子树不为空
				{
					if (p != NULL)
					{

						if (isLeft) // 若当前节点为父亲节点的左子树的根节点 
						{
							TreeNode* tmp = root->left; //记录当前节点的左子树的根节点
							delete p->left; // 释放当前节点
							p->left = tmp;  // 将父亲节点的左孩子指向 tmp 
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
				if (root->left != NULL && root->right != NULL) //当前节点存在左右子树
				{
					if (p != NULL) //从右子树中找最小节点放在当前节点即可
					{
						TreeNode* min = root->right;
						TreeNode* pre = root;
						while (min != NULL) //在右子树中找出最小节点
						{
							pre = min;
							min = min->left;
						}
						root->element = pre->element; //将最小节点的值赋值给当前节点
						internalDelete(root->right, pre->element, root, false);	 //在当前节点的右子树中删除刚刚找到的最小节点
						return true;
					}
				}
				
			}
			else if(myComparator(t, root->element) < 0) //要删除的节点在左子树
			{
				internalDelete(root->left, t,root,true);
			}
			else
			{
				internalDelete(root->right, t,root,false); //要删除的节点在右子树
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

	void internalMidPrint(TreeNode * root)
	{
		if (root == NULL)
		{
			return;
		}
		internalMidPrint(root->left);
		cout << root->element << endl;
		internalMidPrint(root->right);

	}

	void internalBeforePrint(TreeNode * root)
	{
		if (root == NULL)
		{
			return;
		}
		cout << root->element << endl;
		internalBeforePrint(root->left);		
		internalBeforePrint(root->right);

	}

	void internalAfterPrint(TreeNode * root)
	{
		if (root == NULL)
		{
			return;
		}
		internalAfterPrint(root->left);		
		internalAfterPrint(root->right);
		cout << root->element << endl;
	}
};


#endif // !BINARY_SEARCH_TREE_H_
