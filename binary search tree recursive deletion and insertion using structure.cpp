#include<iostream>
using namespace std;

struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;

};
struct node *root=nullptr;

struct node *rinsert(struct node *p,int key)
{
    struct node *t=nullptr;
    if(p==nullptr)
    {
        t=new node [sizeof(node)];
        t->data=key;
        t->lchild=t->rchild=nullptr;
        return t;
    }
    if(key<p->data)
        p->lchild=rinsert(p->lchild,key);
    else if(key>p->data)
        p->rchild=rinsert(p->rchild,key);

    return p;

};

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

int height(struct node *p)
{
    int x,y;
    if(p==nullptr)
        return 0;
    x=height(p->lchild);
    y=height(p->rchild);
    return x>y?x+1:y+1;
}
struct node*inpre(struct node *p)
{
    while(p && p->rchild!=nullptr)
        p=p->rchild;

    return p;
}
struct node *insucc(struct node *p)
{
    while(p && p->lchild!=nullptr)
        p=p->lchild;

     return p;
}

struct node * rdelete(struct node *p,int key)
{struct node *q;
    if(p==nullptr)
        return nullptr;
    if(p->lchild==nullptr && p->rchild==nullptr)
    {
        if(p==root)
            root=nullptr;
            delete(p);
            return nullptr;

    }


if(key<p->data)
    p->lchild=rdelete(p->lchild,key);
else if (key>p->data)
    p->rchild=rdelete(p->rchild,key);
        else
        {
            if(height(p->lchild)>height(p->rchild))
            {

                q=inpre(p->lchild);
                p->data=q->data;
                p->lchild=rdelete(p->lchild,q->data);

            }
            else
            {
                q=insucc(p->rchild);
                    p->data=q->data;
                    p->rchild=rdelete(p->rchild,q->data);
            }
        }

return p;
}

int main()
{
    int n;
    struct node *temp;
    root=rinsert(root,10);
    rinsert(root,5);
    rinsert(root,20);
    rinsert(root,8);
    rinsert(root,30);

    rdelete(root,20);

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
