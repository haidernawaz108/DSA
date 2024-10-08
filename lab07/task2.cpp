#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

void insertAtEnd(Node **head, int newData) {
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}
void printList(Node *head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << " NULL "<<endl;
}
int main()

{

    Node * head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printList(head);
    system("pause");
}