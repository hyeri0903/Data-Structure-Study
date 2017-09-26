#include <iostream>
#include <queue>
#define size 8

using namespace std;

int arr[size][size] =
{
	0,1,1,0,0,0,0,0,
	1,0,0,1,1,0,0,0,
	1,0,0,0,0,1,1,0,
	0,1,0,0,0,0,0,1,
	0,1,0,0,0,0,0,1,
	0,0,1,0,0,0,0,1,
	0,0,1,0,0,0,0,1,
	0,0,0,1,1,1,1,0
};

int visited[size] = { 0 };
int graph[size];
int front = -1;
int rear = -1;


bool isEmpty()
{
	if (rear == front)
		return true;
	else
		return false;
}
void enqueue(int data)
{
	rear++;
	graph[rear]=data;
}

int dequeue()
{
	if (isEmpty())
	{
		return -1;
	}
	else 
		return graph[front++];
}


void DFS(int v)
{
	cout << v << " ";
	visited[v] = 1;
	for (int i = 0; i < size; i++)
	{
		if (arr[v][i] == 1 && !visited[i])
			DFS(i);
	}
}
void BFS(int d)
{
	enqueue(d);
	if (visited[d] == 0)
	{
		cout << d << " ";
		visited[d] = 1; //visited vertex marking
	}
	while (!isEmpty())
	{
		int t = dequeue();
		for (int i = 0; i < size; i++)
		{
			if (arr[t][i] == 1 && visited[i] == 0)
			{
				enqueue(i);
				cout << i << " ";
				visited[i] = 1;
			}
		}
	}
}


void main()
{
	cout << "Print Adjavent Matrix" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	cout << "DFS : ";
	DFS(0);
	cout << endl;

	for (int i = 0; i < size; i++)
		visited[i] = 0;

	cout << "BFS : ";
	BFS(0);
}