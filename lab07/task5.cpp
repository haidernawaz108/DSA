#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void insertAtEnd(Node** head, int newData){
    Node* newNode = new Node();
    newNode->data = newData;
    if(*head == NULL){
        *head = newNode;
        newNode->next = *head; 
    }
    else{
        Node* temp = *head;
        while(temp->next != *head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}
void insertAtBeginning(Node** head, int newData){
    Node* newNode = new Node();
    newNode->data = newData;
    if(*head == NULL){
        *head = newNode;
        newNode->next =*head;
    }
    else{
        Node* temp = *head;
        while(temp->next != *head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}