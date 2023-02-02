#include <iostream>

using namespace std;


	// CREATE NODE CLASS HERE //
class Node
{
	public:
		int value;
		Node * next;

		Node(int value)
		{
			this->value = value;
			this->next = nullptr;
		}
};

class LinkedList {
    private:
		Node * head;
		Node * tail;
		int length;

    public:
		LinkedList(int value)
		{
			Node * tempNode = new Node(value);
			head = tail = tempNode;
			length = 1;
		}

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getHead() {
            if (head == nullptr) {
                cout << "Head: nullptr" << endl;
            } else {
                cout << "Head: " << head->value << endl;
                cout << "Head Address: " << head << endl;
                cout << "Head next: " << head->next << endl;
            }
        }

        void getTail() {
            if (tail == nullptr) {
                cout << "Tail: nullptr" << endl;
            } else { 
                cout << "Tail: " << tail->value << endl;
                cout << "Tail Address: " << tail << endl;
                cout << "Tail next: " << tail->next << endl;
            }  
        }

        void getLength() {
            cout << "Length: " << length << endl;
        }

        void append(int value)
        {
        	Node * newNode = new Node(value);

        	if(head) //Nodes already exist in LL
        	{
        		tail->next = newNode;
        		tail = newNode;
        	}
        	else //No nodes exist in LL. Both head & tail point to nullptr
        		head = tail = newNode;

        	length++;
        }

        void deleteLast()
        {
        	Node * temp = head;

        	if(length == 0)
        		cout << "Linked list is empty." << endl;
        	else if(length < 2)
        	{
        		head = tail = nullptr;
        		delete temp;
        		length--;
        	}
        	else
        	{
        		//Find node previous to tail
        		while(temp->next != tail)
        			temp = temp->next;

        		//Set tail to this node
        		//Set temp to next node
        		//Delete temp
        		tail = temp;
        		cout << "New tail is: " << tail->value << endl;

        		temp = temp->next;
        		tail->next = nullptr;
        		cout << "Deleting node: " << temp->value << endl;
        		delete temp;

        		length--;
        	}
        }

        void prepend(int value)
        {
            Node * newNode = new Node(value);

            if(length == 0)
                head = tail = newNode;
            else
            {
                newNode->next = head;
                head = newNode;
            }

            length++;
        }
};

int main() {
        
    LinkedList* myLinkedList = new LinkedList(4);

    myLinkedList->prepend(10);
    myLinkedList->append(15);
    myLinkedList->append(3);

    myLinkedList->deleteLast();

    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    
    cout << "\nLinked List:\n";
    myLinkedList->printList();

    /*  
        EXPECTED OUTPUT:
    	----------------
        Head: 4
        Tail: 4
        Length: 1

        Linked List:
        4

    */       
}