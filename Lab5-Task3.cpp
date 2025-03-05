/*
Task 3; the golf recording system
*/

#include <iostream>
#include <string>
using namespace std;

struct Player {
    string name;
    int score;
    Player* prev;
    Player* next;
};

class GolfLL { // Again, LL refers to Link List
private:
    Player* head;

public:
    GolfLL() {
        head = NULL;
    }

    void addPlayer(string name, int score) {
        Player* newNode = new Player{name, score, NULL, NULL};
        if (head == NULL || score < head->score) {
            newNode->next = head;
            if (head != NULL) head->prev = newNode;
            head = newNode;
            return;
        }
        Player* temp = head;
        while (temp->next != NULL && temp->next->score < score) temp = temp->next;
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) temp->next->prev = newNode;
        temp->next = newNode;
    }

    void Display() {
        Player* temp = head;
        while (temp != NULL) {
            cout<<temp->name<<" - "<<temp->score<<" -> ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void displayLowestScore() {
        if (head != NULL) cout<<"Lowest Score: "<<head->name<<" - "<<head->score<<endl;
    }

    void displaySameScore(int score) {
        Player* temp = head;
        bool found = false;
        while (temp != NULL) {
            if (temp->score == score) {
                cout<<temp->name<<" ";
                found = true;
            }
            temp = temp->next;
        }
        if (!found) cout<<"No player with this score.";
        cout<<endl;
    }

    void displayBackward(string playerName) {
        Player* temp = head;
        while (temp != NULL && temp->name != playerName) temp = temp->next;
        if (temp == NULL) {
            cout<<"Player not found.\n";
            return;
        }
        while (temp != NULL) {
            cout<<temp->name<<" - "<<temp->score<<" -> ";
            temp = temp->prev;
        }
        cout<<endl;
    }
};

int main() {
    GolfLL tournament;
    int choice, score;
    string name;

    while (true) {
        cout<<"\n1. Add Player\n2. Display All Players\n3. Display Lowest Score\n4. Display Players with Same Score\n5. Display Players Backward from Given Player\n6. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"Enter player name: ";
                cin>>name;
                cout<<"Enter player score: ";
                cin>>score;
                tournament.addPlayer(name, score);
                break;
            case 2:
                tournament.Display();
                break;
            case 3:
                tournament.displayLowestScore();
                break;
            case 4:
                cout<<"Enter score to find players: ";
                cin>>score;
                tournament.displaySameScore(score);
                break;
            case 5:
                cout<<"Enter player name: ";
                cin>>name;
                tournament.displayBackward(name);
                break;
            case 6:
                return 0;
        }
    }
}
