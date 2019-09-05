#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

struct EdgeVertex
{
	int weight;
	string name;
	EdgeVertex * nextNode;
};

struct IndexVertex
{
	string name;
	EdgeVertex * firstNode;
};

class MyGraph
{
public:
	

	void createGraph(bool isDirectGraph)
	{
		this->isDirectGraph = isDirectGraph;
		cout << "请输入顶点数 和 边数 （如：2 1）：";
		cin >> vertexCount >> edgeCount;

		cout << "请输入顶点名称" << endl;
		for (int i = 0; i < vertexCount; i++)
		{
			string tempName;
			cin >> tempName;
			IndexVertex * index = new IndexVertex;
			index->name = tempName;
			index->firstNode = NULL;
			adjList.push_back(*index);
		}
		cout << "请输入边信息 （如 name1 name2 20）" << endl;

		for (int i = 0; i < edgeCount; i++)
		{
			string name1, name2;
			int weight;
			cin >> name1 >> name2 >> weight;

			IndexVertex & tempVertex = getIndexVertex(name1);
			EdgeVertex * tempEdgeVertex = new  EdgeVertex;
			tempEdgeVertex->nextNode = tempVertex.firstNode;
			tempEdgeVertex->weight = weight;
			tempEdgeVertex->name = name2;
			tempVertex.firstNode = tempEdgeVertex;

			if (!isDirectGraph)
			{
				IndexVertex & tempVertex2 = getIndexVertex(name2);
				EdgeVertex * tempEdgeVertex2 = new  EdgeVertex;
				tempEdgeVertex2->nextNode = tempVertex2.firstNode;
				tempEdgeVertex2->weight = weight;
				tempEdgeVertex2->name = name1;
				tempVertex2.firstNode = tempEdgeVertex2;
			}

		}
	}

	void printGraph()
	{
		for (int i = 0; i < adjList.size(); i++)
		{
			IndexVertex & tempIndexVertex = adjList[i];
			cout << endl << "vertex: " << tempIndexVertex.name << "  adj: ";
		
			if (tempIndexVertex.firstNode != NULL)
			{
				EdgeVertex * tempEdgeVertex = tempIndexVertex.firstNode;
				while (tempEdgeVertex != NULL)
				{
					cout << " " << tempEdgeVertex->name << "(" << tempEdgeVertex->weight << ")" ;
					tempEdgeVertex = tempEdgeVertex->nextNode;
				}
			}
			
		}
	}

	//单源最短路径
	void dijkstra()
	{
		string name;
		cout << endl << "请输入要查询的key : " << endl;
		cin >> name;
		map<string, int> dict; //名称和权值映射结合 抓取和非抓取都在该集合中 通过对应的isVisit集合区分
		map<string, string> path; //前驱和后置映射集合 要查询顶点的前驱名称为zqy 不可达顶点的前驱zqy2 
		map<string, bool> isVisit; //顶点元素到name最短路径是否确认映射关系 true表示该点到name顶点的最短路径已经确定
		//初始化个点到 name点的距离
		for (int i = 0; i < adjList.size(); i++)
		{
			string tempName = adjList[i].name;

			bool isAdjToKey = false;
			EdgeVertex * ptrEdgeVertex =  getIndexVertex(name).firstNode;
			while (ptrEdgeVertex != NULL)
			{
				if (ptrEdgeVertex->name == tempName)
				{
					isAdjToKey = true;
					break;
				}
				ptrEdgeVertex = ptrEdgeVertex->nextNode;
			}

			if (name == tempName) //本身距离为0
			{
				dict[tempName] = 0;
			}
			else if (isAdjToKey) //邻接name点 
			{
				dict[tempName] = ptrEdgeVertex->weight;
			}
			else //不邻接 初始化为最大值
			{
				dict[tempName] = INT_MAX;
			}
		}

		//根据初始化好的dict集合初始化 path集合
		map<string, int> ::iterator iterator4 = dict.begin();
		while (iterator4 != dict.end())
		{
			if (iterator4->second == 0)
			{
				path[iterator4->first] = "zqy";
			}
			else if (iterator4->second == INT_MAX)
			{
				path[iterator4->first] = "zqy2";
			}
			else
			{
				path[iterator4->first] = name;
			}
			iterator4++;
		}

		//根据初始化好的dict集合初始化 isVisit集合
		map<string, int> ::iterator iterator3 = dict.begin();
		while (iterator3 != dict.end())
		{
			isVisit[iterator3->first] = false;
			iterator3++;
		}

		for (;;) //死循环更新个个顶点到name点的的最短路径
		{
			//找出距离name点最小顶点
			int min = INT_MAX; //定义权值最小值 初始化为INT_MAX
			string minName = "Q^Q"; //定义最小值名称
			map<string, int> ::iterator iterator = dict.begin();
			while (iterator != dict.end())
			{
				if (!isVisit[iterator->first] && iterator->second < min) //从没有抓取的集合中抓出最小的
				{
					min = iterator->second; 
					minName = iterator->first;
				}
				iterator++;
			}
			//如果没有找到最小点 表示全部都已经抓取过了 退出循环 
			if (minName == "Q^Q")
			{
				break;
			}

			isVisit[minName] = true; //将抓取到的放入已归位的集合 

			//更新为抓取集合权值
			IndexVertex & change =  getIndexVertex(minName); //将刚刚已经确定最短路径顶点 从 图中找到
			EdgeVertex * changeListPtr =  change.firstNode; // 找到可能会影响的顶点的链表 邻接表 
			while (changeListPtr != NULL)
			{
				//如果当前链表上对应顶点到name点的权值 > 刚刚确定点到name的权值 + 刚刚确定最短路径点到当前链表点的权值 
				if (dict[changeListPtr->name] > dict[minName] + changeListPtr->weight) //从没有抓取的集合中抓出最小的
				{
					dict[changeListPtr->name] = dict[minName] + changeListPtr->weight;
					path[changeListPtr->name] = minName;
				}
				changeListPtr = changeListPtr->nextNode;
			}
			

		}
		cout << "最短路径：" << endl;
		map<string, int> ::iterator iterator2 = dict.begin();
		while (iterator2 != dict.end())
		{
			cout << iterator2->first << " " << iterator2->second << endl;
			iterator2++;
		}
		cout << "路劲关系：" << endl;
		map<string, string> ::iterator pathIterator = path.begin();
		while (pathIterator != path.end())
		{
			cout << pathIterator->first << " " << pathIterator->second << endl;
			pathIterator++;
		}
	}
private:
	vector<IndexVertex> adjList;
	int vertexCount = 0;
	int edgeCount = 0;
	bool isDirectGraph;
	IndexVertex & getIndexVertex(string name)
	{
		for (int i = 0; i < adjList.size(); i++)
		{
			if (name == adjList[i].name)
			{
				return adjList[i];
			}
		}
		
	}
};
