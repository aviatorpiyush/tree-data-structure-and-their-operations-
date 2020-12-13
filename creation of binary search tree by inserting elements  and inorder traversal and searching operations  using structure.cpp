#include<iostream>
using namespace std;

struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;

};
struct node *root=nullptr;

void insert(int key)
{
    struct node *t=root;
    struct node *r,*p;
    if(root==nullptr)
    {
        p = new node [sizeof(node)];
        p->data=key;
        p->lchild=p->rchild=nullptr;
        root=p;
        return;
    }
    while(t!=nullptr)
    {
        r=t;
        if(key<t->data)
        {
            t=t->lchild;

        }
        else if(key>t->data)
        {
            t=t->rchild;
        }
        else
            return ;
    }
    p= new node [sizeof(node)];
    p->data=key;
    p->lchild=p->rchild=nullptr;
    if(key<r->data)
    {
        r->lchild=p;
    }
    else
        r->rchild=p;

}

void inorder(struct node *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}

struct node* search(int key)
{
    struct node *t=root;
    while(t!=nullptr)
    {
        if(key==t->data)
            return t;
        else if(key<t->data)
            t=t->lchild;
            else
                t=t->rchild;
        }
        return nullptr;
}

// recursive insert function//
struct node *rinsert(struct node *p,int key)
{
    struct node *t=nullptr;
    if(p==nullptr)
    {
        t=new node [sizeof(struct node)];
        t->lchild=t->rchild=nullptr;
        return t;
    }
    if(key<p->data)
        p->lchild=rinsert(p->lchild,key);
    else if(key>p->data)
        p->rchild=rinsert(p->rchild,key);

    return p;

};

int main()
{
    struct node * temp;
    int n;
     insert(10);
     insert(5);
     insert(20);
     insert(8);
     insert(30);

     inorder(root);
     cout<<"\n";

     cout<<"enter element to be searched"<<" ";
     cin>>n;
     temp=search(n);
     if(temp!=nullptr)
        cout<<"element "<<temp->data<<" is found"<<endl;
     else
        cout<<"element "<<temp->data<<" is not found"<<endl;
return 0;
}

