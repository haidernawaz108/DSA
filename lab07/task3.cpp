#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
};
void insertAtEnd(Node** head, int newData){
    Node* newNode = new Node;
    Node* last = *head;
    newNode->data = newData;
    newNode->next = NULL;
    if(*head == NULL){
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}
void deleteFromEnd(Node** head){
    if(*head == NULL) return;
    Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    if(temp->prev != NULL){
        temp->prev->next = NULL;
    }
    else{
        *head = NULL;
    }
    delete temp;
}
void printForward(Node* node){
    cout<<"FORWARD TRAVERSAL: ";
    while(node != NULL){
        cout<< node->data << " -> ";
        node = node->next;
    }
    cout<<" NULL "<<endl;
}
int main()
{
    Node * head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printForward(head);
    deleteFromEnd(&head);
    printForward(head);
    system("pause");
}

