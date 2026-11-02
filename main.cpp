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
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Provided: Insert a node at the end.
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};

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
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Waiting customers: ";
    for (Node* current = front; current != nullptr; current = current->next)
        cout << current->data << " ";
    cout << endl;
}

int main(){
    Node* head = nullptr;
    insertEnd(head, 5);
    display(head);
}