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
		cout << "�����붥���� �� ���� ���磺2 1����";
		cin >> vertexCount >> edgeCount;

		cout << "�����붥������" << endl;
		for (int i = 0; i < vertexCount; i++)
		{
			string tempName;
			cin >> tempName;
			IndexVertex * index = new IndexVertex;
			index->name = tempName;
			index->firstNode = NULL;
			adjList.push_back(*index);
		}
		cout << "���������Ϣ ���� name1 name2 20��" << endl;

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

	//��Դ���·��
	void dijkstra()
	{
		string name;
		cout << endl << "������Ҫ��ѯ��key : " << endl;
		cin >> name;
		map<string, int> dict; //���ƺ�Ȩֵӳ���� ץȡ�ͷ�ץȡ���ڸü����� ͨ����Ӧ��isVisit��������
		map<string, string> path; //ǰ���ͺ���ӳ�伯�� Ҫ��ѯ�����ǰ������Ϊzqy ���ɴﶥ���ǰ��zqy2 
		map<string, bool> isVisit; //����Ԫ�ص�name���·���Ƿ�ȷ��ӳ���ϵ true��ʾ�õ㵽name��������·���Ѿ�ȷ��
		//��ʼ�����㵽 name��ľ���
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

			if (name == tempName) //�������Ϊ0
			{
				dict[tempName] = 0;
			}
			else if (isAdjToKey) //�ڽ�name�� 
			{
				dict[tempName] = ptrEdgeVertex->weight;
			}
			else //���ڽ� ��ʼ��Ϊ���ֵ
			{
				dict[tempName] = INT_MAX;
			}
		}

		//���ݳ�ʼ���õ�dict���ϳ�ʼ�� path����
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

		//���ݳ�ʼ���õ�dict���ϳ�ʼ�� isVisit����
		map<string, int> ::iterator iterator3 = dict.begin();
		while (iterator3 != dict.end())
		{
			isVisit[iterator3->first] = false;
			iterator3++;
		}

		for (;;) //��ѭ�����¸������㵽name��ĵ����·��
		{
			//�ҳ�����name����С����
			int min = INT_MAX; //����Ȩֵ��Сֵ ��ʼ��ΪINT_MAX
			string minName = "Q^Q"; //������Сֵ����
			map<string, int> ::iterator iterator = dict.begin();
			while (iterator != dict.end())
			{
				if (!isVisit[iterator->first] && iterator->second < min) //��û��ץȡ�ļ�����ץ����С��
				{
					min = iterator->second; 
					minName = iterator->first;
				}
				iterator++;
			}
			//���û���ҵ���С�� ��ʾȫ�����Ѿ�ץȡ���� �˳�ѭ�� 
			if (minName == "Q^Q")
			{
				break;
			}

			isVisit[minName] = true; //��ץȡ���ķ����ѹ�λ�ļ��� 

			//����Ϊץȡ����Ȩֵ
			IndexVertex & change =  getIndexVertex(minName); //���ո��Ѿ�ȷ�����·������ �� ͼ���ҵ�
			EdgeVertex * changeListPtr =  change.firstNode; // �ҵ����ܻ�Ӱ��Ķ�������� �ڽӱ� 
			while (changeListPtr != NULL)
			{
				//�����ǰ�����϶�Ӧ���㵽name���Ȩֵ > �ո�ȷ���㵽name��Ȩֵ + �ո�ȷ�����·���㵽��ǰ������Ȩֵ 
				if (dict[changeListPtr->name] > dict[minName] + changeListPtr->weight) //��û��ץȡ�ļ�����ץ����С��
				{
					dict[changeListPtr->name] = dict[minName] + changeListPtr->weight;
					path[changeListPtr->name] = minName;
				}
				changeListPtr = changeListPtr->nextNode;
			}
			

		}
		cout << "���·����" << endl;
		map<string, int> ::iterator iterator2 = dict.begin();
		while (iterator2 != dict.end())
		{
			cout << iterator2->first << " " << iterator2->second << endl;
			iterator2++;
		}
		cout << "·����ϵ��" << endl;
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
