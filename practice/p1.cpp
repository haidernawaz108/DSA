#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* prev;
    node* next;

    node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val) {
    node* n = new node(val);
    if (head != NULL) {
        n->next = head;
        head->prev = n;
    }
    head = n;
}

void insertAtTail(node* &head, int val) {
    node* n = new node(val);
    if (head == NULL) {
        insertAtHead(head, val);
        return;
    }
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void deleteAthead(node* &head) {
    if (head == NULL) {
        cout << "EMPTY LIST" << endl;
        return;
    }

    node* d = head;
    
    if (head->next != NULL) {
        head = head->next;
        head->prev = NULL;
    } else {
        head = NULL;
    }

    delete d;
}
void deleteAtTail(node* &head){
    if(head==NULL){
        cout<<"EMPTY LIST"<<endl;
    }
    node* temp = head;
    if(head->next !=NULL){
        while(temp->next->next != NULL){
        temp = temp -> next;
    }
    temp->prev->next = temp ->next;
    temp->next->prev = temp ->prev;
    }else{
        
    }
    delete temp->next;
}

void display(node* &head) {
    if (head == NULL) {
        cout << "NULL" << endl;
        return;
    }
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << " NULL " << endl;
}

int main() {
    node* head = NULL;
    display(head);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    display(head);
    deleteAthead(head);
    deleteAthead(head);
    display(head);
    system("pause");
}
