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
    getline(cin, listpoint);
    insertEnd(head, listpoint);
}

int main(){
    Node* head = nullptr;
    string test; //This is just to make getline work
    cout << "How many items would you like to add?: ";
    int lop=0;
    cin >> lop; //This is the initial loop for the making of the list
    getline(cin, test); //This is just to make getline work
    for (int i=0; i<lop; i++){
        add(head);
    }
    cout << endl;
    display(head);

    bool looper=true;
    while (looper==true){ //Loops the program until the user is done.
        int choice=0;
        cout << "What would you like to do?" << endl;
        cout << "[1] Display the list" << endl;
        cout << "[2] Mark whether items are not started, started, or completed" << endl;
        cout << "[3] Add to the end of the list" << endl;
        cout << "[4] Quit" << endl;
        cout << "> ";
        cin >> choice;
        if (choice==1) display(head); //Displays the list if they want
        else if (choice == 2) cout << "Not yet" << endl; //Need the vector to do this
        else if (choice == 3){
            int lopt;
            cout << "How many items would you like to add?: ";
            cin >> lopt;
            getline(cin, test); //This is just to make getline work
            for (int i=0; i<lop; i++) add(head);
        }
        else if (choice == 4) break;
        cout << endl;
        if (choice!=1){
            display(head);
            cout << endl;
        }
    }
}