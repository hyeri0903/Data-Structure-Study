//#include <iostream>
//Stack array
//using namespace std;
//
//const int stackSize = 4;
//
//class Stack {
//public:
//	int stack[stackSize];
//	int top;
//
//	Stack() { top = -1; }
//	void push(int val) { stack[++top] = val; }
//	int pop() {
//		return stack[top--]; 
//	}
//	int isEmpty() { return top == -1; }
//	int isFull() { return top == stackSize-1; }
//	void displayStack();
//};
//
//void Stack::displayStack() {
//	int i = top;
//	while (i != -1) 
//	{
//		cout << stack[i--] << endl;
//	}
//}
//
//int main()
//{
//	Stack s;
//	s.push(10);
//	s.push(20);
//	s.push(30);
//	s.push(40);
//	s.displayStack();
//
//	if (s.isFull())
//		cout << "Stack is Full!!!" << endl;
//
//	cout << "Pop: " << s.pop() << endl;
//	cout << "Pop: " << s.pop() << endl;
//	cout << "Pop: " << s.pop() << endl;
//	cout << "Pop: " << s.pop() << endl;
//
//	if (s.isEmpty())
//		cout << "Stack is Empty!!!" << endl;
//
//}
