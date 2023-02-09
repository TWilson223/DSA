#include <iostream>
#include <vector>

using namespace std;

class Stack
{
	private:
		vector<int> vect;

	public:
		Stack(int value)
		{
			vect.push_back(value);
		}

		~Stack()
		{
			vect.clear();
			delete &vect;
		}

		void printStack()
		{
			cout << "\nStack items: " << endl;

			for(int i = vect.size()-1; i >= 0; i--)
				cout << vect.at(i) << "\n";
		}

		void push(int value)
		{
			vect.push_back(value);
		}

		int * pop()
		{
			if(vect.size() != 0)
			{
				int * temp = &(vect.back());
				vect.pop_back();

				return temp;
			}

			cout << "\nStack Empty" << endl;

			return nullptr;
		}
};

int main()
{
	Stack * myStack = new Stack(0);

	myStack->push(1);
	myStack->push(2);
	myStack->push(3);

	myStack->printStack();

	cout << "\nPopping from stack: " << *(myStack->pop()) << endl;
	cout << "\nPopping from stack: " << *(myStack->pop()) << endl;
	myStack->printStack();
	cout << "\nPopping from stack: " << *(myStack->pop()) << endl;
	cout << "\nPopping from stack: " << *(myStack->pop()) << endl;

	myStack->pop();

	myStack->printStack();
}
