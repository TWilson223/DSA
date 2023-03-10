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
                cout << "\nHead: nullptr" << endl;
            } else {
                cout << "\nHead: " << head->value << endl;
                //cout << "Head Address: " << head << endl;
                cout << "Head next: " << head->next << endl;
            }
        }

        void getTail() {
            if (tail == nullptr) {
                cout << "Tail: nullptr" << endl;
            } else { 
                cout << "Tail: " << tail->value << endl;
                //cout << "Tail Address: " << tail << endl;
                cout << "Tail next: " << tail->next << endl;
            }  
        }

        int getLength()
        {
            return length;        
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

        void deleteFirst()
        {
            if(length == 0)
                cout << "\nLinked list is empty." << endl;
            else
            {
                Node * temp = head;

                //Check for 1 node left
                if(head == tail)
                    head = tail = nullptr;
                else //More than 1 node left
                    head = head->next;

                cout << "\nDeleting First" << endl;
                
                if(head)
                    cout << "New head is: " << head->value << endl;

                cout << "Deleting Node: " << temp->value << endl;
                length--;
                delete temp;
            }
        }

        void deleteLast()
        {
        	Node * temp = head;

        	if(length == 0)
        		cout << "\nLinked list is empty." << endl;
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
                cout << "\nDeleting Last" << endl;
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

        Node * get(int index)
        {
            if(index >= 0 && index < length)
            {
                Node * temp = head;
                
                for(int i = 0; i < index; i++)
                    temp = temp->next;
                
                return temp;
            }
            else
            {
                cout << "Index out of bounds of LL" << endl;

                return nullptr;
            }
                
        }

        bool set(int index, int value)
        {
            Node * temp = get(index);
            
            if(temp)
            {
                temp->value = value;

                cout << "Node at index " << index << " now has value: " << temp->value << endl;
                
                return true;
            }                
            else
                return false;
        }

        bool insert(int index, int value)
        {
            Node * temp;

            cout << "\nAttempting insert of: " << value << " at index " << index << endl;                

            if(index == 0)
                prepend(value);
            else if(index == length)
                append(value);
            else if(temp = get(index - 1))
            {                
                Node * newNode = new Node(value);

                newNode->next = temp->next;

                temp->next = newNode;

                length++;
            }
            else
                return false;

            return true;
        }

        void deleteNode(int index)
        {
            if(index == 0)
                return deleteFirst();
            else if(index == length)
                return deleteLast();
            else if(index >= 0 && index < length)
            {                
                Node * temp = get(index - 1);
                Node * nodeToDelete = temp->next;

                cout << "\nDeleting node at index " << index << ": " << nodeToDelete->value << endl;

                temp->next = nodeToDelete->next;

                delete nodeToDelete;
                length--;
            }
            else
            {
                cout << "LL is empty or index does not exist in LL" << endl;

                return;
            }
        }

        void reverse()
        {
            Node * temp = head;
            Node * helperNode;
            Node * prev;

            head = tail;
            tail = temp;

            helperNode = temp->next;
            prev = nullptr;

            while(helperNode != nullptr)
            {
                helperNode = temp->next;
                temp->next = prev;
                prev = temp;
                temp = helperNode;
            }
        }
};

int main() {
        
    LinkedList* myLinkedList = new LinkedList(4);

    myLinkedList->prepend(10);
    myLinkedList->append(15);
    myLinkedList->append(3);

    cout << "\nLinked List Before Reversing:\n";
    myLinkedList->printList();
    myLinkedList->reverse();
    cout << "\nLinked List After Reversing:\n";
    myLinkedList->printList();

    cout << "\nLinked List Before:\n";
    myLinkedList->printList();
    myLinkedList->getHead();
    myLinkedList->getTail();
    cout << "Length: " << myLinkedList->getLength() << endl;

    cout << "\nGet value at index 1: " << myLinkedList->get(1)->value << endl;
    cout << "Get value at index "  << myLinkedList->getLength()-1 << ": " << myLinkedList->get((myLinkedList->getLength()-1))->value << endl;
    cout << "Get value at index " << myLinkedList->getLength()  << ": " << myLinkedList->get(myLinkedList->getLength()) << endl;

    myLinkedList->set(2, 44);
    myLinkedList->set(10, 11);

    myLinkedList->deleteNode(0);
    myLinkedList->deleteNode(myLinkedList->getLength());

    cout << "\nLinked List After:\n";
    myLinkedList->printList(); 

    myLinkedList->insert(0, 7);
    cout << "Length: " << myLinkedList->getLength() << endl;
    myLinkedList->insert(myLinkedList->getLength(), 20);
    cout << "Length: " << myLinkedList->getLength() << endl;
    myLinkedList->insert(2, 16);

    myLinkedList->deleteNode(3);
    myLinkedList->deleteNode(7);
        
    cout << "\nLinked List After:\n";
    myLinkedList->printList();

    cout << "\nTesting edge cases for deleting:" << endl;
    myLinkedList->deleteLast();

    cout << "\nLinked List After:\n";
    myLinkedList->printList(); 

    myLinkedList->deleteFirst();
    myLinkedList->deleteLast();
    myLinkedList->deleteFirst();

    myLinkedList->getHead();
    myLinkedList->getTail();
    cout << "Length: " << myLinkedList->getLength() << endl;
}