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
    Node *temp = head;
    while(temp!=NULL)
    {
        cout << temp->data<<" ";
        temp=temp->next;
    }
    cout << endl;
}

void reverseTraverse(Node *head)
{
    if(head==NULL) return;
    Node *temp = head;
    while(temp!=NULL)
    {
        cout << temp->data<<" ";
        temp=temp->prev;
    }
    cout << endl;
}

Node *insertBegin(Node *head, int x)
{
    Node *temp = new Node(x);
    if(head==NULL) return temp;
    else
    {
        temp->next = head;
        head->prev = temp;
        return temp;
    }
}

Node *insertEnd(Node *head, int x)
{
    Node *temp = new Node(x);
    if(head==NULL) return temp;
    else
    {
        Node *curr = head;
        while(curr->next!=NULL) curr = curr->next;
        curr->next = temp;
        temp->prev = curr;
        return head;
    }
}

Node *reverse(Node *head)
{
    if(head==NULL||head->next==NULL) return head;
    Node *prev = NULL, *curr=head;
    while(curr!=NULL)
    {
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }
    return prev->prev;
}

Node *deleteHead(Node *head)
{
    if(head==NULL) return NULL;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return head;
    }
}

Node *deleteEnd(Node *head)
{
    if(head==NULL) return NULL;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    else
    {
        Node *curr = head;
        while(curr->next!=NULL) curr = curr->next;
        curr->prev->next = NULL;
        delete curr;
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
    traverse(head);
    reverseTraverse(temp1);
    head = insertBegin(head, 12);
    traverse(head);
    head = insertEnd(head, 192);
    traverse(head);
    head = reverse(head);
    traverse(head);
    head = deleteHead(head);
    traverse(head);
    head = deleteEnd(head);
    traverse(head);

return 0;
}