/*
Task 2; the rainfall system
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class RainfallLL { // I have used LL to refer to LinkLists 
private:
    Node* head;

public:
    RainfallLL() {
        head = NULL;
    }

    void insertAtEnd(int value) {
        if (value < 0) {
            cout<<"Invalid input. Rainfall cannot be negative.\n";
            return;
        }
        Node* newNode = new Node{value, NULL, NULL};
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void Display() {
        Node* temp = head;
        while (temp != NULL) {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<endl;
    }

    void calculateRainfall() {
        int total = 0, count = 0, MostRainFall = -1, LeastRainFall = 1e9;
        Node* temp = head;
        while (temp != NULL) {
            total += temp->data;
            if (temp->data > MostRainFall) MostRainFall = temp->data;
            if (temp->data < LeastRainFall) LeastRainFall = temp->data;
            count++;
            temp = temp->next;
        }
        cout<<"Total rainfall for the week: "<<total<<endl;
        cout<<"Average rainfall during the week: "<<(total/count)<<endl;
        cout<<"The day with the most rainfall is: "<<MostRainFall<<endl;
        cout<<"The day with the least rainfall is: "<<LeastRainFall<<endl;
    }
};

int main() {
    RainfallLL list;
    int value;

    cout<<"Enter rainfall for 7 days: ";
    for (int i = 0; i < 7; i++) {
        cin>>value;
        list.insertAtEnd(value);
    }

    cout<<"Rainfall Display: ";
    list.Display();
    list.calculateRainfall();

    return 0;
}
