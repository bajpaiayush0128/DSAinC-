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
        temp = temp->next;
        return temp;
    }
    else
    {
        Node *curr = head;
        while(curr->next!=head) curr = curr->next;
        curr->next = temp;
        temp->next = head;
        return temp;   // return head insted of temp and it will insert at end of linked list
    }
}

Node *insertBegin2(Node *head, int x)
{
    Node *temp = new Node(x);
    if(head==NULL)
    {
        temp = temp->next;
        return temp;
    }
    else
    {
        temp->next = head->next;
        head->next = temp;
        int t = head->data;
        head->data = temp->data;
        temp->data = t;
        return head;    // return temp insted of head and it will insert at end of linked list
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
        Node *curr = head;
        while(curr->next!=head) curr = curr->next;
        curr->next = head->next;
        delete head;
        return curr->next;
    }
}

Node *deleteHead2(Node *head)
{
    if(head==NULL) return NULL;
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    else
    {
        head->data = head->next->data;
        Node *temp = head->next;
        head->next = head->next->next;
        delete temp;
        return head;
    }
}

Node *deletekth(Node *head, int k)
{
    if(head==NULL) return NULL;
    if(k==1) return deleteHead2(head);
    int len=1;
    for(Node *curr=head;curr->next!=head;curr=curr->next) len++;
    if(len<k) return head;
    else
    {
        Node *curr = head;
        for(int i=0;i<k-2;i++) curr = curr->next;
        Node *temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        return head;
    }
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;
    traverse(head);
    head = insertBegin2(head, 5);
    traverse(head);
    head = deleteHead2(head);
    traverse(head);
    head = deletekth(head, 2);
    traverse(head);
return 0;
}