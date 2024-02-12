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

void Rtraverse(Node *head)
{
    if(head==NULL) return;
    cout << head->data << " ";
    Rtraverse(head->next);
}

int search(Node *head, int x)
{
    int pos=1;
    Node *curr = head;
    while(curr!=NULL)
    {
        if(curr->data==x) return pos;
        else
        {
            pos++;
            curr=curr->next;
        }
    }
    return -1;
}

int Rsearch(Node *head, int x)
{
    if(head==NULL) return -1;
    if(head->data==x) return 1;
    else
    {
        int res = search(head->next, x);
        if(res==-1) return -1;
        else return (res+1);
    }
}

Node *insertAtStart(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

Node *insertAtEnd(Node *head, int x)
{
    Node *temp = new Node(x);
    if(head==NULL) return temp;
    Node *curr = head;
    while(curr->next!=NULL) curr = curr->next;
    curr->next = temp;
    return head;
}

Node *insertAtPosition(Node *head, int pos, int x)
{
    Node *temp = new Node(x);
    if(pos==1)
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    for(int i=0;i<=pos-2&&curr!=NULL;i++) curr=curr->next;
    if(curr==NULL) return head;
    temp->next=curr->next;
    curr->next=temp;
    return head;
}

Node *insertSorted(Node *head, int x)
{
    Node *temp = new Node(x);
    if(head==NULL) return temp;
    if(x<head->data)
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    while(curr->next!=NULL&&curr->next->data<x) curr=curr->next;
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

Node *deleteFirstNode(Node *head)
{
    if(head==NULL) return NULL;
    else
    {
        Node *temp = head->next;
        delete head;
        return temp;
    }
}

Node *deleteLastNode(Node *head)
{
    if(head==NULL) return NULL;
    else if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    else{
        Node *temp = head;
        while(temp->next->next!=NULL) temp = temp->next;
        if(temp==NULL) return head;
        delete temp->next;
        return head;
    }
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

void middleElement(Node *head)
{
    if(head==NULL) return;
    Node *slow=head, *fast=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data << " ";
}

void nthElementFromEnd(Node *head, int n)
{
    int len=0;
    for(Node *curr=head;curr!=NULL;curr=curr->next) len++;
    if(len<n) return;
    Node *curr=head;
    for(int i=1;i<len-n+1;i++) curr=curr->next;
    cout << curr->data << " ";
}

void nthElementFromEnd2(Node *head, int n)
{
    if(head==NULL) return;
    Node *first = head, *second = head;
    for(int i=0;i<n;i++)
    {
        if(first==NULL) return;
        first = first->next;
    }
    while(first!=NULL)
    {
        first = first->next;
        second = second->next;
    }
    cout << second->data << " ";
}

Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    while(curr!=NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *Rreverse(Node *head)
{
    if(head==NULL) return NULL;
    if(head->next==NULL) return head;
    Node *rest_head = Rreverse(head->next);
    Node *rest_tail = head->next;
    rest_tail->next = head;
    head->next = NULL;
    return rest_head;
}

Node *Rreverse2(Node *curr, Node *prev)
{
    if(curr==NULL) return prev;
    Node *next = curr->next;
    curr->next = prev;
    return Rreverse2(next, curr);
}

void removeDuplicateFromSorted(Node *head)
{
    Node *curr = head;
    while(curr!=NULL&&curr->next!=NULL)
    {
        if(curr->data==curr->next->data)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete(temp);
        }
        else curr = curr->next;
    }
}


// compare two linked lists
// bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
// SinglyLinkedListNode* temp1 = head1;
// SinglyLinkedListNode* temp2 = head2;
// while(temp1!=NULL&&temp2!=NULL)
// {
//     if(temp1->data!=temp2->data) return false;
//     temp1 = temp1->next;
//     temp2 = temp2->next;
// }
// return (temp1==NULL&&temp2==NULL);
// }

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    traverse(head);
    cout << Rsearch(head, 20) <<endl;
    head = insertAtStart(head, 40);
    traverse(head);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 80);
    traverse(head);
    head = deleteFirstNode(head);
    traverse(head);
    head = insertAtPosition(head, 3, 70);
    traverse(head);
    head = deleteAtPosition(head,4);
    traverse(head);
    head = insertSorted(head,45);
    head = insertSorted(head,5);
    head = insertSorted(head,85);
    traverse(head);
    middleElement(head);
    nthElementFromEnd(head, 3);
    nthElementFromEnd2(head, 3);
    cout << endl;
    head = Rreverse2(head, NULL);
    traverse(head);
return 0;
}