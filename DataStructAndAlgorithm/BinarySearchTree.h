#pragma once
#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_
using namespace std;
#include "MyQueue.h"
#include <iostream>
/*
���ֲ�����
*/
template <typename T>
class BinarySearchTree
{
public:
	/*
	���� ����ָ�� ���ⲿʵ�ֱȽ���
	*/
	typedef int (*Comarator)(T, T);
	/*
	ComparatorΪ�Ƚ��� ����Ϊ�ɱȽϵĶ��� ����������Ŀ����1> ����2
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
		���� 
		root ��ǰ���ڵ�
		t Ҫ�����Ԫ��
	*/
	bool internalInsert(TreeNode * & root , const T & t)
	{
		if (root == NULL) //����ڵ�Ϊ�ձ����ҵ����ʵ�λ��
		{
			root = new TreeNode(t, NULL, NULL);
			
		}
		if(myComparator(t,root->element) > 0) //�����ڵ�ǰ�ڵ��������
		{
			internalInsert(root->right, t);
		} 
		else if (myComparator(t, root->element) < 0) //�����ڵ�ǰ�ڵ��������
		{
			internalInsert(root->left, t);
		}
		else
		{
			//�ظ�Ԫ�ز�����
		}
		return true;

	}

	/*
	
		root ��ǰ���ڵ�
		t Ҫɾ����Ԫ��
		p ��ǰ�ڵ�ĸ��׽ڵ�
		isLeft �ǲ�����������ɾ��
	*/
	bool internalDelete(TreeNode * & root, const T & t,TreeNode * & p,bool isLeft)
	{
		if (root == NULL) //���Ϊ�ձ�ʾû�иýڵ�
		{
			return false;
		}
		else
		{
			if (myComparator(t, root->element) == 0) //�ҵ��ýڵ� 
			{
				if (root->left == NULL && root->right == NULL) //������ǰ�ڵ���Ҷ�ӽڵ� ֱ��ɾ��
				{
					delete root;
					root = NULL;
					return true;
				}
				if (root->left != NULL && root->right == NULL) //����Ҫɾ���ڵ����������Ϊ��
				{
					if (p != NULL)
					{

						if (isLeft) // ����ǰ�ڵ�Ϊ���׽ڵ���������ĸ��ڵ� 
						{
							TreeNode* tmp = root->left; //��¼��ǰ�ڵ���������ĸ��ڵ�
							delete p->left; // �ͷŵ�ǰ�ڵ�
							p->left = tmp;  // �����׽ڵ������ָ�� tmp 
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
				if (root->left != NULL && root->right != NULL) //��ǰ�ڵ������������
				{
					if (p != NULL) //��������������С�ڵ���ڵ�ǰ�ڵ㼴��
					{
						TreeNode* min = root->right;
						TreeNode* pre = root;
						while (min != NULL) //�����������ҳ���С�ڵ�
						{
							pre = min;
							min = min->left;
						}
						root->element = pre->element; //����С�ڵ��ֵ��ֵ����ǰ�ڵ�
						internalDelete(root->right, pre->element, root, false);	 //�ڵ�ǰ�ڵ����������ɾ���ո��ҵ�����С�ڵ�
						return true;
					}
				}
				
			}
			else if(myComparator(t, root->element) < 0) //Ҫɾ���Ľڵ���������
			{
				internalDelete(root->left, t,root,true);
			}
			else
			{
				internalDelete(root->right, t,root,false); //Ҫɾ���Ľڵ���������
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
