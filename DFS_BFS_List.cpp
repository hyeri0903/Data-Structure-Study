//Linked List DFS & BFS
#include <iostream>
#define MAX 50
using namespace std;

int arr[8][8] =
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

typedef struct Q
{
	int data[MAX];
	int front, rear;
}Q;

typedef struct node
{
	node *next;
	int vertext;
}node;

void enqueue(Q *, int);
int dequeue(Q *);
int empty(Q *);
void BFS(int v);
void DFS(int v);
void initGraph();
void insert(int num1, int num2);
int visited[MAX];

node *graph[MAX];         //head of linked list
int n;

void BFS(int v)
{
	int  i, visited[MAX];
	Q q;

	node *p;
	q.rear = q.front = -1;

	for (int i = 0; i < MAX; i++)
		visited[i] = 0;          //false·Î ÃÊ±âÈ­
	enqueue(&q, v);
	cout << v << " ";
	visited[v] = 1;        //check true
	while (!empty(&q))
	{
		v = dequeue(&q);
		for (p = graph[v]; p != NULL; p = p->next)
		{
			if (visited[p->vertext] == 0)
			{
				enqueue(&q, p->vertext);
				visited[p->vertext] = 1;
				cout << p->vertext <<" ";
			}
		}
	}
}

int empty(Q *p)
{
	if (p->rear == -1)
		return 1;
	else return 0;
}

void enqueue(Q *p, int x)
{
	if (p->rear == -1)
	{
		p->front = p->rear = 0;
		p->data[p->rear] = x;
	}
	else
	{
		p->rear = p->rear + 1;
		p->data[p->rear] = x;
	}
}

int dequeue(Q *p)
{
	int x;
	x = p->data[p->front];
	if (p->rear == p->front)
	{
		p->rear = -1;
		p->front = -1;
	}
	else
		p->front = p->front + 1;
	return x;
}

void initGraph()
{
	int i, num1, num2;

	for (int i = 0; i < MAX; i++)
		graph[i] = NULL;
}

void insert(int num1, int num2)
{
	node *p, *q;
	q = new node();
	q->vertext = num2;
	q->next = NULL;

	if (graph[num1] == NULL)
		graph[num1] = q;
	else
	{
		p = graph[num1];
		while (p->next != NULL)
			p = p->next;
		p->next = q;
	}

}

void DFS(int v)
{
	node *p;
	cout << v << " ";
	p = graph[v];
	visited[v] = 1;
	while (p != NULL)
	{
		v = p->vertext;
		if (!visited[v])
			DFS(v);
		p = p->next;
	}
}

void main()
{
	cout << "Print Adjavent Matrix" << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j <8; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	initGraph();
	insert(0, 1);
	insert(0, 2);
	insert(1, 0);
	insert(1, 3);
	insert(1, 4);
	insert(2, 0);
	insert(2, 5);
	insert(2, 6);

	insert(3, 1);
	insert(3, 7);
	insert(4, 1);
	insert(4, 7);
	insert(5, 2);
	insert(5, 7);

	insert(6, 2);
	insert(6, 7);
	insert(7, 3);
	insert(7, 4);
	insert(7, 5);
	insert(7, 6);

	cout << "BFS : ";
	BFS(0);
	cout << endl;
	cout <<"DFS : ";
	DFS(0);
}
