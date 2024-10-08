#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

void insertAtBeginning(Node **head, int newData)
{
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = (*head);

    if(*head != NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void printForward(Node * head)
{

    cout<<"Forward Print: ";
    while (head != NULL)
    {
        cout<<head->data<<"<->";
        head = head->next;
    }
    cout<<"NULL";
}


void ReverseDisplay(Node *head)
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->prev;
    }
    cout<<"NULL"<<endl;
}

int main()

{

    Node * head = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    printForward(head);
    cout<<endl<<"Reversed List:";
    ReverseDisplay(head);
    system("pause");
}