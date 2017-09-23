#include <iostream>
using namespace std;

struct Node {
public:
	int data;
	Node *next;

	friend class List;
};

class List {
public:
	Node *head;
	List() { head = 0; }
	void insert(int);
	void deleteNode(int);
	void searchList(int num);

	bool isEmpty();
	void display();
};

bool List::isEmpty()
{
	if (head == 0)
		return true;
	else
		return false;
}

void List::insert(int data)
{
	Node *temp = new Node();
	Node *p = new Node();
	Node *q = new Node();
	temp->data = data;

	if (head == 0)
		head = temp;
	else if (temp->data < head->data)
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		p = head;
		while ((p != 0) && (p->data < temp->data)) {
			q = p;
			p = p->next;
		}
		if (p != 0) {
			temp->next = p;
			q->next = temp;
		}
		else
			q->next = temp;
	}
	//cout << temp->data << endl;
}

void List::deleteNode(int num)
{
	Node *p, *q;

	if (head->data == num)
	{
		p = head;
		head = head->next;
		delete p;
	}
	else
	{
		p = head;
		while (p != 0 && p->data != num)
		{
			q = p;
			p = p->next;
		}
		if (p != 0)
		{
			q->next = p->next;
			delete p;
		}
		else
			cout << num << "is not in the List\n";
	}
}

void List::display()
{
	Node *p = NULL;

	if (!isEmpty()) {
		p = head;
		while (p) {
			cout << p->data << "->";
			p = p->next;
		
		}
		cout << endl;
	}
	else
		cout << "List is empty\n";
}

void List::searchList(int num)
{
	Node *p ;
	if (head != 0)
	{
		p = head;
		while (p != 0 && p->data != num)
			p = p->next;
		if (p)
			cout << p->data << " is found" << endl;
		else
			cout << num << " is not in the list" << endl;
	}
	else
		cout << "List is empty\n";
}

int main()
{
	List ll;
	ll.insert(40);
	ll.insert(30);
	ll.display();
	ll.insert(20);

	ll.display();
	ll.insert(50);
	ll.display();

	ll.searchList(40);
	ll.deleteNode(40);
	ll.display();

	return 0;
}