#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void traverse(Node *head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout << temp->data<<" ";
        temp=temp->next;
    }
    cout << endl;
}

Node *deleteAtPosition(Node *head, int pos)
{
    if(pos==0) return head;
    else if(pos==1)
    {
        Node *temp = head->next;
        delete head;
        return temp;
    }
    else{
        Node *temp = head;
        for(int i=0;temp!=NULL&&i<pos-2;i++) temp = temp->next;
        Node *temp1 = temp->next;
        temp->next=temp->next->next;
        delete (temp1);
        return head;
    }
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    traverse(head);
    head = deleteAtPosition(head,2);
    traverse(head);
return 0;
}