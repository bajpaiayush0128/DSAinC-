//getHead() functions and search functions both iterative and recursive are of return type Node*

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(){
        data=0;
        next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class LL{
    Node* first, *second, *third;
    public:
    LL(){
        first=NULL;
        second=NULL;
        third=NULL;
    }
    
    // this create the LL using array
    void create(int arr[], int n){
        Node* t, *last;
        first=new Node();
        first->data= arr[0];
        first->next=NULL;
        last=first;
        
        for(int i=1;i<n;i++){
            t=new Node();
            t->data=arr[i];
            t->next=NULL;
            last->next=t;
            last=t;
        }
    }

    // this create another LL using array
    void create2(int arr[], int n){
        Node* t, *last;
        second=new Node();
        second->data= arr[0];
        second->next=NULL;
        last=second;
        
        for(int i=1;i<n;i++){
            t=new Node();
            t->data=arr[i];
            t->next=NULL;
            last->next=t;
            last=t;
        }
    }
    
    // this return first pointer
    Node* getHead(){
        return first;
    }
    // this return second pointer
    Node* getHead2(){
        return second;
    }
    // this return third pointer
    Node* getHead3(){
        return third;
    }
    
    //this is used to display the LL
    void display(Node* p){
        while(p){
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    
    //this is used to display the LL recursively
    void Rdisplay(Node* p){
        if(p){
            cout<<p->data<<" ";
            Rdisplay(p->next);
        }
    }

    // this the number of nodes in the LL
    int count(Node* p){
        int c=0;
        while(p){
            c++;
            p=p->next;
        }
        return c;
    }
    
    // this finds the sum of all elements of a liked list
    void sum(){
        Node* p=first;
        int sum=0;
        while(p){
            sum=sum+p->data;
            p=p->next;
        }
        cout<<"\nSum of all elements is "<<sum<<endl;
    }
    
    // this finds the maximum
    int max(){
        Node* p;
        int max=INT32_MIN;
        p=first;
        while(p){
            if(p->data>max){
                max=p->data;
            }
            p=p->next;
        }
        return max;
    }
    
    // this finds the maximum recursively
    int Rmax(Node* p){
        if(p==0){
            return INT32_MIN;
        }
        int x=0;
        x=Rmax(p->next);
        if(p->data>x)
        return p->data;
        else
        return x;
    }
    
    // this search for the element is present in the LL or not
    Node* search(int key){
        Node* p, *q;
        q=NULL;
        p=first;
        while(p){
            if(p->data==key){
                q->next=p->next;
                p->next=first;
                first=p;
                return p;
            }
            q=p;
            p=p->next;
        }
        return NULL;
    }
    
    // this search for the element is present in the LL or not recursively
    Node* Rsearch(Node* p, int key){
        if(p==NULL)
        return NULL;
        if(key==p->data)
        return p;
        return Rsearch(p->next, key);
        
    }

    // this insert element at a given index
    void Insert(int pos, int data ){
        Node* p=first, *t;
        if(pos<0 || pos > count(p))
        return;
        t=new Node();
        t->data=data;

        if(pos==0){
            t->next=first;
            first=t;
        }else{
            for(int i=0;i<pos-1;i++)
            p=p->next;
            t->next=p->next;
            p->next=t;
        }
    }
    
    // this inserts element at that postion so that linked list remain sorted
    void InsertSorted(int x){
        Node* p=first;
        Node* t, *q;
        t=new Node();
        t->data=x;
        t->next=NULL;
        q=NULL;
        if(first==NULL){
            first=t;
        }
        while(p->data<x && p){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;
        }else{
            t->next=q->next;
            q->next=t;
        }
    }
    // this deletes the node at a given index
    int Delete(int pos){
        Node* p=first, *q=NULL;
        int x=-1;

        if(pos<1||pos>count(p))
        return -1;
        if(pos==1){
            first=first->next;
            x=p->data;
            delete(p);
            return x;
        }else{
            for(int i=0;i<pos-1;i++){
                q=p;
                p=p->next;
            }
            q->next=p->next;
            x=p->data;
            delete(p);
            return x;
        }
    }

    // this checks whether LL is sorted or not
    bool isSorted(){
        Node* p=first;
        int x=INT32_MIN;

            while(p){
                if(p->data<x)
                return false;
                x=p->data;
                p=p->next;
            }
            return true;
    }

    // this removes duplicate element from the linked list
    void removeDuplicate(){
        Node*p=first->next, *q=first;
        while(p){
            if(p->data==q->data){
                q->next=p->next;
                delete(p);
                p=q->next;
            }else{
                q=p;
                p=p->next;
            }
        }
    }
    //reversing the LL using sliding pointer
    void reverseUsingSP(){
        Node* p=first, *q=NULL, *r=NULL;

        while(p){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        first=q;
    }
    //reversing LL using recursion
    void Rreverse(Node* q, Node* p){
        if(p){
            Rreverse(p,p->next);
            p->next=q;
        }else{
            first=q;
        }
    }

    //concatenating two linked list
    void concatLL(){
        Node* p=first;
        while(p->next){
            p=p->next;
        } 
        p->next=second;
        second=NULL;
    }

    // Merging two sorted LL into one sorted linked list
    void merge(){
        Node* p=first, *q=second, *last=NULL;
        first=second=NULL;
        if(p->data<q->data){
            third=last=p;
            p=p->next;
            third->next=NULL;
        }else{
            third=last=q;
            q=q->next;
            third->next=NULL;
        }

        while(p && q){
            if(p->data < q->data){
                last->next=p;
                last=p;
                p=p->next;
                last->next=NULL;
            }else{
                last->next=q;
                last=q;
                q=q->next;
                last->next=NULL;
            }
        }
        //if element in p(first LL) is remaining
        if(p)
        last->next=p;
        //if element in q(second LL) is remaining
        if(q)
        last->next=q;
    }

    // Checks whether LL is having loop or not
    bool isLoop(){
        Node* p, *q;
        p=q=first;
        // Iterate until either p or q is null or p is not equal to q
        do{
            p=p->next;
            q=q->next;
            q!=NULL?q=q->next:NULL;
        }while((p&&q) && (p!=q));

        // If p and q meets again then there is loop otherwise not
        if(p==q)
        return true;
        return false;
    }

};

int main()
{
    LL l,l2;
    Node* temp, *Rtemp;
    int arr[]={1,2,3,4,5,6,7};
    int arr2[]={2,5,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    l.create(arr,n);
    l.create2(arr2,n2);
    l.Rdisplay(l.getHead());
    l.sum();
    cout<<"Maximum element of linked list is: "<<l.max()<<endl;
    cout<<"Maximum element of linked list by recursion is: "<<l.Rmax(l.getHead())<<endl;
    temp=l.search(7);
    cout<<"Searched element "<<temp->data<<" is found\n";
    Rtemp=l.Rsearch(l.getHead(),7);
    cout<<"Searched element "<<Rtemp->data<<" is found by recursion\n";
    l.display(l.getHead());

    l.Insert(7,8);
    l.Insert(0,1);
    l.display(l.getHead());

    cout<<l.Delete(1)<<" is deleted"<<endl;
    cout<<l.Delete(4)<<" is deleted"<<endl;
    cout<<l.Delete(1)<<" is deleted"<<endl;
    l.display(l.getHead());

    if(l.isSorted()){
        cout<<"LL is sorted"<<endl;
    }else{
        cout<<"LL is not sorted"<<endl;
    }
    l.Insert(2,2);
    l.Insert(6,8);
    l.display(l.getHead());
    l.removeDuplicate();
    cout<<"Displaying element after removing duplicate"<<endl;
    l.display(l.getHead());
    l.reverseUsingSP();
    cout<<"Displaying LL after reversing it using sliding pointers"<<endl;
    l.display(l.getHead());
    l.Rreverse(NULL,l.getHead());
    cout<<"Displaying LL after reversing it using recursion"<<endl;
    l.display(l.getHead());

    cout<<"Displaying second LL"<<endl;
    l.display(l.getHead2());

    // Uncomment below code to perform concatenation of two linked list
    // l.concatLL();
    // cout<<"Displaying Linked list after concatination"<<endl;
    // l.display(l.getHead());

    // Uncomment below code to perform merging of two sorted linked list
    // l.merge();
    // cout<<"Displaying Linked list after merging two sorted Linked List "<<endl;
    // l.display(l.getHead3());

    if(l.isLoop()){
        cout<<"LL is having loop"<<endl;
    }else{
        cout<<"LL is not having loop"<<endl;
    }
    
    return 0;
}