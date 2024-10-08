#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
};
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
    deleteFromEnd(&head);
    printForward(head);
    system("pause");
}
