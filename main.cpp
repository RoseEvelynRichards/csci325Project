/**
 * @file main.cpp
 * @authors 
 * @brief 
 * @version 0.1
 * @date 2026-10-26
 * 
 * @copyright Copyright (c) 2026
 * 
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Node {
    string data;
    Node* next;
};

//Insert a node at the end.
void insertEnd(Node*& head, string point) {
    Node* newNode = new Node{point, nullptr};

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr)
        curr = curr->next;

    curr->next = newNode;
}

void display(Node* front) {
    if (front == nullptr) {
        cout << "There is nothing in this list." << endl;
        return;
    }
    for (Node* current = front; current != nullptr; current = current->next){
        cout << current->data;
        if (current->next != nullptr) cout << ",";
        cout << " ";
    }
    cout << endl;
}

void add(Node*& head){
    string listpoint; //The actual items of the list
    cout << "Add an item to the list: ";
    getline(cin >> ws, listpoint); //std::ws extracts whitespace in buffer
    insertEnd(head, listpoint);
}

int main(){
    Node* head = nullptr;
    cout << "How many items would you like to add?: ";
    int loop1=0;
    cin >> loop1; //This is the initial loop for the making of the list
    getline(cin, test); //This is just to make getline work
    for (int i=0; i<loop1; i++){
        add(head);
    }

    cout << endl;
    display(head);

    bool looper=true;
    while (looper==true){ //Loops the program until the user is done.
        int choice=0;
        cin.clear();
        cout << "What would you like to do?\n";
        cout << "[1] Display the list\n";
        cout << "[2] Mark whether items are not started, started, or completed\n";
        cout << "[3] Add to the end of the list\n";
        cout << "[4] Quit\n";
        cout << "> ";
        cin >> choice;
        if (choice==1) display(head); //Displays the list if they want
        else if (choice == 2) cout << "Not yet" << endl; //Need the vector to do this
        else if (choice == 3){
            int loop2;
            cout << "How many items would you like to add?: ";
            cin >> loop2;
            getline(cin, test); //This is just to make getline work
            for (int i=0; i<loop2; i++) add(head);
        }
        else if (choice == 4) break;
        cout << endl;
        if (choice!=1){
            display(head);
            cout << endl;
        }*/
    cout << endl;
    }
    return 0;
}