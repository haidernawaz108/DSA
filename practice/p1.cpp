#include <iostream>
using namespace std;

class node {
public: 
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtBegining(node* &head, int val) {
    node* n = new node(val);
    if (head == NULL) {
        head = n;
        return;
    } else {
        n->next = head;
        head = n;
    }
}

void display(node* &head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    node* head = NULL;
    insertAtBegining(head, 10);
    display(head); 
    return 0;
}
