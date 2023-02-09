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

class Queue
{
	private:
		Node * first;
		Node * last;
		int length;

	public:
		Queue(int value)
		{
			last = new Node(value);
			first = last;

			length = 1;
		}
		
		~Queue()
		{
			Node * temp = first;

			for(int i = 0; i<length; i++)
			{
				first = first->next;
				delete temp;
				temp = first;
			}
		}

		void printQueue()
		{
			Node * temp = first;

			cout << "\nItems in Queue: " << endl;

			for(int i = 0; i<length; i++)
			{
				cout << temp->value << "\n";
				temp = temp->next;
			}

			cout << endl;
		}

		void enqueue(int value)
		{
			Node * temp = new Node(value);

			if(length == 0)
				first = last = temp;
			else
			{
				last->next = temp;
				last = temp;
			}

			length++;
		}

		int dequeue()
		{
			Node * temp = first;
			int leftQueue = INT_MIN;

			if(length == 0)
				return leftQueue;
			else if(length == 1)
				first = last = nullptr;
			else
				first = first->next;

			leftQueue = temp->value;
			delete temp;
			length--;

			return leftQueue;
		}

		int getLength()
		{
			return length;
		}

		Node * getFirst()
		{
			return first;
		}

		Node * getLast()
		{
			return last;
		}
};


int main()
{
	Queue * myQueue = new Queue(0);

	myQueue->enqueue(1);
	myQueue->enqueue(2);
	myQueue->enqueue(3);

	myQueue->printQueue();

	while(myQueue->getFirst())
	{
		cout << "Dequeue: " << myQueue->dequeue() << endl;

		if(myQueue->getFirst())
			cout << "First in Queue: " << myQueue->getFirst()->value << endl;
		else
			cout << "Queue Empty" << endl;
	}
}
