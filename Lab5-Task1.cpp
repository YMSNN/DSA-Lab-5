#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLL {
private:
    Node* head;

public:
    DoublyLL() {
        head = NULL;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, NULL, head};
        if (head != NULL) head->prev = newNode;
        head = newNode;
    }

    void insertAfterValue(int value, int newValue) {
        Node* temp = head;
        while (temp != NULL && temp->data!=value) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout<<"Value "<<value<<" not found.\n";
            return;
        }
        Node* newNode = new Node{newValue, temp, temp->next};
        if (temp->next != NULL) temp->next->prev = newNode;
        temp->next = newNode;
    }

    void Display() {
        Node* temp = head;
        while (temp != NULL) {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main() {
    DoublyLL list;
    int n, value;

    cout<<"Enter number of marks: ";
    cin>>n;
    cout<<"Enter the marks: ";
    for (int i = 0; i < n; i++) {
        cin>>value;
        list.insertAtBeginning(value);
    }
    cout<<"After initialization: ";
    list.Display();

    cout<<"Enter mark to insert at beginning: ";
    cin>>value;
    list.insertAtBeginning(value);
    cout<<"Updated list: ";
    list.Display();

    int positionValue, newValue;
    cout<<"Enter value after which to insert: ";
    cin>>positionValue;
    cout<<"Enter new value to insert: ";
    cin>>newValue;
    list.insertAfterValue(positionValue, newValue);
    cout<<"Final list: ";
    list.Display();

    return 0;
}
