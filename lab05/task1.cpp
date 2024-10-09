#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head = nullptr;
// Function to insert a node at the end of the circular linked list
void insertAtEnd(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    if (head == nullptr) {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
}
// Function to traverse and print the elements of the circular linked list
void printList() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}
// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    if (head == nullptr) {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    newNode->next = head;
    Node* current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = newNode;
    head = newNode;
}
// Function to delete a node from the circular linked list by value
void deleteNode(int data) {
    if (head == nullptr) {
        return;
    }
    if (head->data == data) {
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = head->next;
        delete head;
        head = current->next;
        return;
    }
    Node* current = head;
    Node* prev = nullptr;
    do {
        if (current->data == data) {
            prev->next = current->next;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    } while (current != head);
}
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    cout<<" BEFORE ADDING AT BEGINNING ";
    printList();
    cout<<" AFTER ADDING 5 AT BEGINNING ";
    insertAtBeginning(5);
    printList();
    cout<<" NOW DELETING 20 FROM THE LIST ";
    deleteNode(20);
    printList();
    system("pause");
    return 0;
}