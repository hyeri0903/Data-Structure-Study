#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node()
	{
		left = 0;
		right = 0;
	}

	friend class Tree;
};

class Tree
{
public:
	Node* root;
	Tree() { root = 0; }
	Node* insertTree(Node* ptr, int data);
	void insertTree(int data);
	Node* deleteTree(Node* ptr, int data);
	void deleteTree(int data);
	Node* findMin(Node *p);
	Node* searchTree(Node* ptr, int key);

	void drawBSTree(Node* p, int level);
	void drawTree();
};

Node* Tree::searchTree(Node* ptr, int key)
{
	if (root != NULL) {
		if (ptr == NULL)
			return NULL;
		else {
			if (key == ptr->data)
				return ptr;
			else if (key < ptr->data)
				ptr = searchTree(ptr->left, key);
			else if (key > ptr->data)
				ptr = searchTree(ptr->right, key);
		}
		return ptr;
	}
}

Node* Tree::findMin(Node* p)   //right subtree에서 가장 작은것 선택
{
	if (p->left == NULL)
		return p;
	else
		findMin(p->left);
}


void Tree::insertTree(int data)
{
	root = insertTree(root, data);
}

Node* Tree::insertTree(Node *ptr, int key)
{
	if (ptr == NULL)
	{
		ptr = new Node();
		ptr->data = key;
		ptr->left = ptr->right = NULL;
	}
	else if (key < ptr->data)
		ptr->left = insertTree(ptr->left, key);
	else if (key > ptr->data)
		ptr->right = insertTree(ptr->right, key);
	return ptr;
}

void Tree::deleteTree(int data)
{
	root = deleteTree(root, data);
}


Node* Tree::deleteTree(Node *ptr, int key) {
	if (root != NULL) {
		if (ptr != NULL) {
			if (key < ptr->data) // 노드이동
				ptr->left = deleteTree(ptr->left, key);
			else if (key > ptr->data) //노드이동
				ptr->right = deleteTree(ptr->right, key); //지울 노드에 도착
			else if (ptr->left == NULL && ptr->right == NULL) //child 0일때, leaf node
				ptr = NULL;
			else if (ptr->left == NULL) { //rightchild만 있을때
				Node *p;
				p = ptr;
				ptr = ptr->right;
				delete(p);
			}
			else if (ptr->right == NULL) { //leftchild만 있을때
				Node *p;
				p = ptr;
				ptr = ptr->left;
				delete(p);
			}
			else { // child가 2개 다 있을때
				Node *temp = findMin(ptr->right);          
				ptr->data = temp->data;
				ptr->right = deleteTree(ptr->right, ptr->data);
			}
		}
		else
			cout << "Not found" << endl;
	}
	else
		cout << "Tree is empty" << endl;
	return ptr;
}


void Tree::drawTree()
{
	drawBSTree(root, 1);
}

void Tree::drawBSTree(Node *p, int level)
{
	if (root != NULL) {
		if (p != 0 && level <= 7)
		{
			drawBSTree(p->right, level + 1);
			for (int i = 1; i <= (level - 1); i++)
				cout << "    ";
			cout << p->data;
			if (p->left != 0 && p->right != 0) cout << " <" << endl;
			else if (p->right != 0)  cout << " /" << endl;
			else if (p->left != 0) cout << " \\" << endl;
			else  cout << endl;
			drawBSTree(p->left, level + 1);
		}
	}
	else
		cout << "Tree is Empty" << endl;
}

int main()
{
	int i;
	Tree *t = new Tree();
	while (1) {
		cout << "1.Insert   2.Delete   3.Search   4.Print" << endl;
		cout << "choose menu: ";
		cin >> i;

		switch (i)
		{
		case 1:
			cout << "Enter number to insert : ";
			int num;
			cin >> num;
			t->insertTree(num);
			break;
		case 2:
			cout << "Enter number to delete: ";
			int number;
			cin >> number;
			t->deleteTree(number);
			break;
		case 3:
			int searchnum;
			cout << "Enter number to search:";
			cin >> searchnum;
			t->searchTree(t->root, searchnum);
			break;
		case 4:
			t->drawTree();
			cout << "-------------------------------" << endl;
			break;
		default:
			break;

		}
	}
	return 0;
}
