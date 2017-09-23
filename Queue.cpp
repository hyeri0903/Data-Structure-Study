#include <iostream>
using namespace std;

const int queueSize = 5;

class Queue {
public:
	int front;
	int rear;
	int queue[queueSize];

	Queue() {
		front = -1; rear = -1;
	}

	bool isFull()
	{
		if (rear == queueSize - 1)
			return 1;
		else
			return 0;
	}

	bool isEmpty()
	{
		if (front == rear)
			return 1;
		else return 0;
	}

	void enqueue(int item)
	{
		if (rear == queueSize - 1) {
			isFull();
			return;
		}
		queue[++rear] = item;
	}

	int dequeue() {
		if (front == rear)
			return isEmpty();
		return queue[++front];
	}
	void print();
};

void Queue::print()
{
	int i;

	if (isEmpty())
		cout << "Queue is Empty!\n";
	else
		i = front + 1;
	cout << "***Print Queue***\n";
	while (i <= rear)
	{
		cout << queue[i];
		i++;
	}

}

int main()
{
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);

	if (q.isFull())
		cout << "Queue is Full!!!\n";

	cout << "Dequeue : " << q.dequeue() << endl;
	cout << "Dequeue : " << q.dequeue() << endl;
	cout << "Dequeue : " << q.dequeue() << endl;
	cout << "Dequeue : " << q.dequeue() << endl;
	cout << "Dequeue : " << q.dequeue() << endl;

	if (q.isEmpty())
		cout << "Queue is Empty!!!\n";



}