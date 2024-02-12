#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* lchild;
    int data;
    Node* rchild;
    
    Node(){
        data=0;
        lchild=rchild=NULL;
    }
    Node(int data){
        this->data=data;
        lchild=rchild=NULL;
    }
};

class tree{
    Node* root;
    public:
    tree(){
        root=NULL;
    }

   void createTree(){
        Node* p,*t;
        int x;
        queue<Node*> q;

        cout<<"Enter root element of tree"<<endl;
        cin>>x;

        root=new Node(x);
        // root->data=x;
        root->lchild=root->rchild=NULL;
        // pushing address of root node
        q.push(root);

        // loop until the queue is not empty and root->data is not -1(means root is NULL)
        while(!q.empty() && root->data!=-1){
            // getting the front element of queue and popping it
            p=q.front();
            q.pop();
            cout<<"Enter the left child of "<<p->data<<endl;
            cin>>x;
            // if x==-1 then that node is null means there is no child of that node
            if(x!=-1){
                t=new Node(x);
                t->lchild=t->rchild=NULL;
                p->lchild=t;
                // pushing address of lchild node which is just created
                q.push(t);
            }
            cout<<"Enter the right child of "<<p->data<<endl;
            cin>>x;
            // if x==-1 then that node is null means there is no child of that node
            if(x!=-1){
                t=new Node(x);
                t->lchild=t->rchild=NULL;
                p->rchild=t;
                // pushing address of rchild node which is just created
                q.push(t);
            }
        }
    }

    Node* getRoot(){
        return root;
    }

    void preorder(Node* p){
        //if root->data==-1 then root is Null and preorder cannot be displayed
        if(root->data==-1){
            cout<<"Preorder cannot be displayed";
            return;
        }else if(p){
            cout<<p->data<<" ";
            preorder(p->lchild);
            preorder(p->rchild);
        }
    }

    void inorder(Node* p){
        //if root->data==-1 then root is Null and inorder cannot be displayed
        if(root->data==-1){
            cout<<"Inorder cannot be displayed";
            return;
        }else if(p){
            inorder(p->lchild);
            cout<<p->data<<" ";
            inorder(p->rchild);
        }
    }


    void postorder(Node* p){
        //if root->data==-1 then root is Null and postorder cannot be displayed
        if(root->data==-1){
            cout<<"Postorder cannot be displayed";
            return;
        }else if(p){
            postorder(p->lchild);
            postorder(p->rchild);
            cout<<p->data<<" ";
        }
    }

    void levelorder(Node* p){
        queue<Node*> q;
        //if root->data==-1 then root is Null and levelorder cannot be displayed 
        if(root->data!=-1){
            cout<<p->data<<" ";
            // pushing address of root node
            q.push(p);
            while(!q.empty()){
                // getting the front element of queue and popping it
                p=q.front();
                q.pop();
                if(p->lchild){
                    cout<<p->lchild->data<<" ";
                    // pushing address of lchild node
                    q.push(p->lchild);
                }
                if(p->rchild){
                    cout<<p->rchild->data<<" ";
                    // pushing address of rchild node
                    q.push(p->rchild);
                }
            }
        }else{
            cout<<"Levelorder cannot be displayed";
            return;
        }
    }

    int treeHeight(Node* p){
        int x=0,y=0;
        //if root->data==-1 then root is Null and preorder cannot be displayed
        if(p==NULL || root->data==-1) return -1;
        x=treeHeight(p->lchild);
        y=treeHeight(p->rchild);
        if(x>y) return x+1;  //incrementing height by 1
        else return y+1;   //incrementing height by 1
    }

    // this function counts the number of nodes in a tree
    int count(Node* p){
        int x=0,y=0;
        // if root is -1 then there is no node in the tree
        if(p && root->data!=-1){
            x=count(p->lchild);
            y=count(p->rchild);
            return x+y+1;
        }
        return 0;
    }

    // this function counts the number of nodes in a tree same as above one
    // but code is less
    int count2(Node* p){
        // if root is -1 then there is no node in the tree
        if(p && root->data!=-1)
            return count2(p->lchild)+count2(p->rchild)+1;
        return 0;
    }

    // this is the function to count node with degree two
    int countNodeWithDegreeTwo(Node* p){
        int x=0,y=0;
        // if root is -1 then there is no node in the tree
        if(p && root->data!=-1){
            x=countNodeWithDegreeTwo(p->lchild);
            y=countNodeWithDegreeTwo(p->rchild);
            // if both left and right child is there
            if(p->lchild && p->rchild)
            return x+y+1;    //increment only when both left and right child of a node is there otherwise don't increment
            else
            return x+y;
        }
        return 0;
    }

    // this is the function to count node with degree one
    int countNodeWithDegreeOne(Node* p){
        int x=0,y=0;
        // if root is -1 then there is no node in the tree
        if(p && root->data!=-1){
            x=countNodeWithDegreeOne(p->lchild);
            y=countNodeWithDegreeOne(p->rchild);

            // if either left or right child is there
            //the condition used below is for XOR
            // if((p->lchild==NULL && p->rchild!=NULL) || (p->lchild!=NULL && p->rchild==NULL))    
            
            // so we can also write the above mentioned commented condition as follows
            // but here giving condition that it is not null is important otherwise bitwise operator will give error
            if((p->lchild!=NULL) ^ (p->rchild!=NULL))    
            return x+y+1;    //increment only when either left or right child of a node is there otherwise don't increment
            else
            return x+y;
        }
        return 0;
    }

    // this is the function to count leaf nodes on the tree(or node with degree zero)
    int countLeafNode(Node* p){
        int x=0,y=0;
        // if root is -1 then there is no node in the tree
        if(p && root->data!=-1){
            x=countLeafNode(p->lchild);
            y=countLeafNode(p->rchild);
            // if both left and right child is not there
            if(!p->lchild && !p->rchild)  // !p means p==NULL
            return x+y+1;    //increment only when both left and right child of a node is NULL otherwise don't increment
            else
            return x+y;
        }
        return 0;
    }

    // this is the function to count node with degree one or two
    int countNodeWithDegreeOneOrTwo(Node* p){
        int x=0,y=0;
        // if root is -1 then there is no node in the tree
        if(p && root->data!=-1){
            x=countNodeWithDegreeOneOrTwo(p->lchild);
            y=countNodeWithDegreeOneOrTwo(p->rchild);
            // if either left or right or both child is there
            if(p->lchild || p->rchild)
            return x+y+1;    //increment only when either left or right or both child of a node is there otherwise don't increment
            else
            return x+y;
        }
        return 0;
    }

    // this function sum all the elements of the tree
    int sum(Node* p){
        int x=0,y=0;
        // if root is -1 then there is no node in the tree
        if(p && root->data!=-1){
            x=sum(p->lchild);
            y=sum(p->rchild);
            return x+y+p->data;
        }
        return 0;
    }
};

int main(){
    tree t;
    t.createTree();
    cout<<endl;
    cout<<"Preorder:- ";
    t.preorder(t.getRoot());
    cout<<endl;
    cout<<"Inorder:- ";
    t.inorder(t.getRoot());
    cout<<endl;
    cout<<"Postorder:- ";
    t.postorder(t.getRoot());
    cout<<endl;
    cout<<"Levelorder:- ";
    t.levelorder(t.getRoot());
    cout<<endl;
    cout<<"Height of tree:- "<<t.treeHeight(t.getRoot())<<endl;
    cout<<"No. of nodes:- "<<t.count(t.getRoot())<<endl;
    cout<<"No. of 1 degree nodes:- "<<t.countNodeWithDegreeOne(t.getRoot())<<endl;
    cout<<"No. of 2 degree nodes:- "<<t.countNodeWithDegreeTwo(t.getRoot())<<endl;
    cout<<"No. of 1 or 2 degree nodes:- "<<t.countNodeWithDegreeOneOrTwo(t.getRoot())<<endl;
    cout<<"No. of leaf nodes:- "<<t.countLeafNode(t.getRoot());
    cout<<endl<<endl;

    return 0;
}