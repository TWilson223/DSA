#include <iostream>

using namespace std;


class Node
{
    public:
        int value;
        Node * next;
        Node * prev;

        Node(int value)
        {
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
};


class DoublyLinkedList {
    private:
        int length;
        Node * head;
        Node * tail;

    public:
		DoublyLinkedList(int value)
        {
            Node * newNode = new Node(value);
            head = tail = newNode;
            length = 1;
        }

        ~DoublyLinkedList() {
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
            }
        }

        void getTail() {
            if (tail == nullptr) {
                cout << "Tail: nullptr" << endl;
            } else { 
                cout << "Tail: " << tail->value << endl;
            }  
        }

        void getLength() {
            cout << "Length: " << length << endl;
        }

        void append(int value)
        {
            Node * newNode = new Node(value);

            if(length == 0)
                head = tail = newNode;
            else
            {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
                        
            length++;
        }

        bool deleteLast()
        {
            if(length == 0)
                return false;
            else if(length == 1)
            {
                Node * temp = head;
                head = tail = nullptr;
                
                delete temp;                
            }
            else
            {
                Node * temp = tail;                
                tail = tail->prev;
                tail->next = nullptr;

                delete temp;                
            }

            length--;
            return true;
        }

        void prepend(int value)
        {
            Node * newNode = new Node(value);

            if(length == 0)
                head = tail = newNode;
            else
            {
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
            }

            length++;
        }

        bool deleteFirst()
        {
            Node * temp = head;

            if(length == 0)
                return false;
            else if(length == 1)
            {                
                head = tail = nullptr;

                delete temp;
            }
            else
            {
                head = head->next;
                head->prev = nullptr;

                delete temp;
            }

            length--;
            return true;
        }

};

int main() {
        
    DoublyLinkedList* myDLL = new DoublyLinkedList(7);

    myDLL->getHead();
    myDLL->getTail();
    myDLL->getLength();

    cout << "\nDoubly Linked List Before:\n";
    myDLL->printList();
    
    //Append/Prepend
    myDLL->append(15);
    myDLL ->prepend(3);

    cout << "\nDoubly Linked List After:\n";
    myDLL->printList();

    //Delete First
    myDLL->deleteFirst();
    cout << "\nDelete First\n";
    myDLL->printList();

    //Delete Last
    cout << "\nDelete Last 1:\n";
    myDLL->deleteLast();
    myDLL->printList();
    cout << "\nDelete Last 2:\n";
    myDLL->deleteLast();
    myDLL->printList();
}

