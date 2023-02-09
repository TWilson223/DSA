#include <iostream>
#include <climits>

using namespace std;

class Node
{
	public:
		Node * next;
		int value;
		
		Node(int value)
		{
			this->value = value;
			this->next = nullptr;
		}	
};

class Stack
{
	private:
		Node * top;
		int length;

	public:
		Stack(int value)
		{
			top = new Node(value);

			top->next = nullptr;
			length = 1;
		}
		
		~Stack()
		{
			Node * temp = top;

			for(int i = 0; i<length; i++)
			{
				top = top->next;
				delete temp;
				temp = top;
			}
		}

		void printStack()
		{
			Node * temp = top;

			cout << "\nStack items: " << endl;

			for(int i = 0; i<length; i++)
			{
				cout << temp->value << "\n";
				temp = temp->next;
			}

			cout << endl;
		}

		void push(int value)
		{
			Node * newNode = new Node(value);

			newNode->next = top;
			top = newNode;

			length++;
		}

		int pop()
		{
			Node * temp = top;
			int poppedValue = INT_MIN; //INT_MIN used as it is unlikely to ever have this value in our stack

			if(length != 0)
			{
				temp = top;
				poppedValue = top->value;
				top = top->next;
				delete temp;
				length--;
			}

			return poppedValue;
		}

		int getLength()
		{
			return length;
		}

		Node * getTop()
		{
			return top;
		}
};


int main()
{
	Stack * myStack = new Stack(0);

	myStack->push(1);
	myStack->push(2);
	myStack->push(3);

	myStack->printStack();

	while(myStack->getTop())
	{
		cout << "Pop from stack: " << myStack->pop() << endl;

		if(myStack->getTop())
			cout << "New Top: " << myStack->getTop()->value << endl;
		else
			cout << "Stack Empty" << endl;
	}
}
