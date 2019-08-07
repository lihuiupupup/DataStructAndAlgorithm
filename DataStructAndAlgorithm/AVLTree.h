#pragma once
#ifndef AVLTREE_H_
#define AVLTREE_H_
#include <iostream>
using namespace std;

/*
该平衡二叉搜索树只实现了 插入和删除 和广度优先遍历打印
*/
template<typename T>
class AVLTree
{
public:
	typedef int(*comparator)(T, T);
	AVLTree(comparator c):mycomparator(c)
	{

	}
	~AVLTree() {
		traverseDelete()
	}

	void insert(T t)
	{
		internalInsert(myRoot, t);
	}

	void remove(T t)
	{
		internalDelete(myRoot, t, myRoot, false);
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
				cout << temp->element << "        "<< temp->height << endl;
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

	
	comparator mycomparator;
	struct TreeNode
	{
		int height = -1;
		T element;
		TreeNode * left;
		TreeNode * right;
		TreeNode(T  myelement, TreeNode * myleft, TreeNode * myright) :element(myelement), left(myleft), right(myright) {}
	};

	TreeNode * myRoot;

	void internalInsert(TreeNode * & root,const T & t)
	{
		if (root == NULL)
		{
			root = new TreeNode(t, NULL, NULL);
		}
		else if (mycomparator(t, root->element) < 0)
		{
			internalInsert(root->left, t);
			if (height(root->left) - height(root->right) == 2) //若在左子树插入元素导致当前节点失去平衡
			{
				if (mycomparator(t , root->left->element) < 0) //插入的值小于左子树根节点的值 表明只会插入在左子树的左边
				{
					llRotate(root); //左左旋转
				}
				else
				{
					lrRotate(root); //左右旋转
				}
			}
		}
		else if (mycomparator(t, root->element) > 0)
		{
			internalInsert(root->right, t);
			if (height(root->right) - height(root->left) == 2) 
			{
				if (mycomparator(t, root->right->element) > 0)
				{
					rrRotate(root);
				}
				else
				{
					rlRotate(root);
				}
			}
		}
		else
		{
			//do nothing
		}
		root->height = treeHeight(root->left, root->right); // 重新计算节点高度
	}

	bool internalDelete(TreeNode * & root, const T & t, TreeNode * & p, bool isLeft)
	{
		if (root == NULL) //如果为空表示没有该节点
		{
			return false;
		}
		else
		{
			if (mycomparator(t, root->element) == 0)
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
			else if (mycomparator(t, root->element) < 0)
			{
				internalDelete(root->left, t, root, true);
				if (height(root->right) - height(root->left) == 2)
				{
					TreeNode * r = root->right;
					if (height(r->left) < height(r->right)) //删除时不要用comparator 比较t和l,r的大小 t会是null
					{
						rrRotate(root);
					}
					else
					{
						rlRotate(root);
					}
				}
				
			}
			else
			{
				internalDelete(root->right, t, root, false);
				if (height(root->left) - height(root->right) == 2)
				{
					TreeNode * l = root->left;
					if (height(l->left) > height(l->right))
					{
						llRotate(root);
					}
					else
					{
						lrRotate(root);
					}
				}
			}

			return true;
		}

		root->height = treeHeight(root->left, root->right);
	}

	int height(TreeNode *  root)
	{
		return root == NULL ? -1 : root->height;
	}

	/*
			   root                      B

			B	      F      --->     C      root

	     C     D                    E      D       F
	   
	   E
	*/
	void llRotate(TreeNode * & root) //需要使用指针引用 无法和父亲节点关联
	{
		TreeNode * B = root->left; //记录当前节点的左孩子
		root->left = B->right; //当前节点的左孩子指向左孩子的右孩子
		B->right = root; //左孩子的右孩子指向当前节点
		root->height = treeHeight(root->left, root->right); 
		B->height = treeHeight(B->left, B->right);
		root = B; 
	}

	void rrRotate(TreeNode * & root)
	{
		TreeNode * B = root->right;
		root->right = B->left;
		B->left = root;
		root->height = treeHeight(root->left, root->right);
		B->height = treeHeight(B->left, B->right);
		root = B;
	}

	void rlRotate(TreeNode * & root)
	{
		llRotate(root->right);
		rrRotate(root);
	}

	void lrRotate(TreeNode * & root)
	{
		rrRotate(root->left);
		llRotate(root);
	}

	int treeHeight(TreeNode *  l,TreeNode *  r)
	{
		return height(l) > height(r) ? height(l) + 1 : height(r) + 1;
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
};




#endif // !AVLTREE_H_

