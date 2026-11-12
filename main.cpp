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

void display(Node* front, vector<int> v) {
    if (front == nullptr) {
        cout << "There is nothing in this list." << endl;
        return;
    }
    int i=0;
    for (Node* current = front; current != nullptr; current = current->next){
        cout << current->data << " ";
        if (v[i] == 0) {
            cout << "(Not Started)";
        } else if (v[i] == 1) {
            cout << "(In Progress)";
        } else if (v[i] == 2) {
            cout << "(Completed)";
        }
        i++;
        
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

void change(Node*& front, vector<int>& v){
    int i=0;
    int status_change;
    cout << endl;
    for (Node* current = front; current != nullptr; current = current->next){
        cout << current->data << endl;
        cout << "What is the status of this item? ";
        cout << "[0] Not Started, [1] In Progress, or [2] Completed: ";
        cin >> status_change;
        v[i]=status_change;
        i++;
    }
}

int main(){
    Node* head = nullptr;
    string test;
    cout << "How many items would you like to add?: ";
    int loop1=0;

    //prevents an invalid input, clears the input, and resets the input error
    while (!(cin >> loop1)){
        cout << "Pick a whole number: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    getline(cin, test); //This is just to make getline work

    vector<int> status;
    for (int i=0; i<loop1; i++){
        add(head);
        status.push_back(0);
    }

    cout << endl;
    display(head, status);
    cout << endl;

    bool looper=true;
    while (looper==true){ //Loops the program until the user is done.
        int choice=0;
        cin.clear();
        cout << "What would you like to do?\n";
        cout << "[1] Display the list\n";
        cout << "[2] Mark whether items are not started, in progress, or completed\n";
        cout << "[3] Add to the end of the list\n";
        cout << "[4] Quit\n";
        cout << "> ";

        //prevents an invalid input, clears the input, and resets the input error
        while (!(cin >>choice)){ 
            cout << "Invalid input\n> ";
            cin.clear(); 
            cin.ignore(10000, '\n'); 
        }

        switch(choice){
            case 1:
                //Displays the list if they want
                display(head, status);
                break;

            case 2:
                //Change the status
                change(head, status);
                break;

            case 3:
                int loop2;
                cout << "How many items would you like to add?: ";

                while (!(cin >> loop2)){
                    cout << "Invalid input:  ";
                    cin.clear(); 
                    cin.ignore(10000, '\n'); 
                }
                for (int i=0; i < loop2; i++){
                    add(head);
                    status.push_back(0);
                } 
                break;

            case 4:
                looper = false;
                break;

            default:
                cout << "Invalid Input\n";
                break;
        }
    cout << endl;
    }
    return 0;
}