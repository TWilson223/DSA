#include <iostream>

using namespace std;


class Node { 
    public: 
        int value;
        Node* next;
        Node* prev;
    
        Node(int value) {
            this->value = value;
            this->next = nullptr;
            this->prev = nullptr;
        }
};


class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
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
        	cout << "\n" << endl;

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

        int getLength() {
            return length;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }

        void deleteLast() {
            if (length == 0) return;
            Node* temp = tail;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                tail = tail->prev;
                tail->next = nullptr;
            }
            delete temp;
            length--;
        }

        void prepend(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            length++;
        }

        void deleteFirst() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
                head->prev = nullptr;
            }
            delete temp;            
            length--;
        }

        Node * get(int index)
        {
        	Node * temp;

        	if(index < (length/2) && index >= 0)
        	{
        		temp = head;

        		for(int i = 0; i<index; i++)
        			temp = temp->next;
        	}
        	else if(index >= (length/2) && index < length)
        	{
        		temp = tail;

        		for(int i = length-1; i>index; i--)
        			temp = temp->prev;
        	}
        	else
        	{
        		cout << "\nIndex out of bounds or DLL empty" << endl;
        		temp = nullptr;
        	}

        	return temp;
        }

        bool set(int index, int value)
        {
        	Node * temp = get(index);

        	if(temp)
        	{
        		temp->value = value;

        		return true;
        	}
        	else
        		return false;
        }

        bool insert(int index, int value)
        {
        	Node * temp;

        	if(index == 0)
        		prepend(value);
        	else if(index == length)
        		append(value);
        	else if(temp = get(index-1))
        	{
        		Node * after = temp->next;
        		Node * newNode = new Node(value);

        		newNode->next = after;
        		newNode->prev = temp;
        		after->prev = newNode;
        		temp->next = newNode;

        		length++;
        	}
        	else
        		return false;

        	return true;
        }

        bool deleteNode(int index)
        {
        	Node * temp;

        	if(index == 0)
        		deleteFirst();
        	else if(index == length)
        		deleteLast();
        	else if(temp = get(index-1))
        	{
        		Node * nodeToDelete = temp->next;
        		Node * after = nodeToDelete->next;

        		temp->next = after;
        		after->prev = temp;

        		delete nodeToDelete;
        		length--;
        	}
        	else
        		return false;

        	return true;
        }
};



int main() {
        
    DoublyLinkedList* myDLL = new DoublyLinkedList(0);
    myDLL->append(1);
    myDLL->append(2);
    myDLL->append(3);

//    cout << "Get in first half of DLL:\n";
//    cout << myDLL->get(1)->value;
//
//    cout << "\n\nGet in second half of DLL:\n";
//    cout << myDLL->get(2)->value << endl;
//    cout << myDLL->set(3, 5) << endl;
//    myDLL->set(4, 6);
//    cout << "\n" << endl;
    myDLL->printList();

    myDLL->insert(myDLL->getLength(), 4);
    myDLL->insert(0, 10);
    myDLL->insert(1, 11);
    myDLL->insert(9, 11);

    myDLL->printList();

    //Deletes
    cout << "\nDeleting Nodes: ";
    myDLL->deleteNode(4);
    myDLL->deleteNode(0);
    myDLL->printList();
    myDLL->deleteNode(myDLL->getLength());
    myDLL->deleteNode(11);
    myDLL->printList();

     /*
        EXPECTED OUTPUT:
        ----------------
        Get in first half of DLL:
        1

        Get in second half of DLL:
        2
    
    */
        
}


