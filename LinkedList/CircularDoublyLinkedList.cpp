#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

void traverse(Node *head)
{
    if(head==NULL) return;
    Node *temp = head->next;
    cout << head->data<<" ";
    while(temp!=head)
    {
        cout << temp->data<<" ";
        temp=temp->next;
    }
    cout << endl;
}

Node *insertBegin(Node *head, int x)
{
    Node *temp = new Node(x);
    if(head==NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }
    else
    {
        temp->prev = head->prev;
        temp->next = head;
        head->prev->next = temp;
        head->prev = temp;
        return temp;   // return head in place of temp and it will be insert at end
    }
}

Node *deleteHead(Node *head)
{
    if(head==NULL) return NULL;
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    else
    {
        Node *temp = head;
        head->next->prev = head->prev;
        head->prev->next = head->next;
        head = head->next;
        delete temp;
        return head;
    }
}

Node *deleteEnd(Node *head)
{
    if(head==NULL) return NULL;
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    else
    {
        Node *temp = head->prev;
        head->prev->prev->next = head;
        head->prev = head->prev->prev;
        delete temp;
        return head;
    }
}

int main()
{
    Node *head = new Node(10);
    Node *temp = new Node(20);
    Node *temp1 = new Node(30);
    head->next = temp;
    temp->prev = head;
    temp->next = temp1;
    temp1->prev = temp;
    temp1->next = head;
    head->prev = temp1;
    traverse(head);
    head = insertBegin(head, 25);
    head = insertBegin(head, 255);
    traverse(head);
    head = deleteHead(head);
    traverse(head);
    head = deleteEnd(head);
    traverse(head);
}