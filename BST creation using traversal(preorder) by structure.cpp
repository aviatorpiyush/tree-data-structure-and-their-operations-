#include<iostream>
using namespace std;

struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};
struct node *root=nullptr;
struct stack
{
    int size;
    int top;
    struct node **s;

};
void stackcreate(struct stack *st,int size)
{
    st->size=size;
    st->top=-1;
    st->s=new node * [(st->size)*sizeof(struct node *)];

}

void push(struct stack *st,struct node *x)
{
    if(st->top==st->size-1)
    {
        cout<<"stack overflow";
    }
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
}
struct node *pop(struct stack *st)
{
    struct node *x=nullptr;
    if(st->top==-1)
    {
        cout<<"stack underflow";

    }
    else
    {
        x=st->s[st->top];
        st->top--;
    }
    return x;
}
 int isstackempty(struct stack st)
 {
     if(st.top==-1)
        return 1;
     else
        return 0;
 }
int isstackfull(struct stack st)
 {
     return st.top==st.size-1;

 }

node * stacktop(struct stack st)
 {

     if(!isstackempty(st))
        return (st.s[st.top]);
     else
        return nullptr;

 }
 void iterativePreorder(struct node *p) {
    struct stack stk;
    stackcreate(&stk,100);
    while (p != nullptr || !isstackempty(stk)){
        if (p != nullptr)
            {
            cout << p->data << " ";
            push(&stk,p);
            p = p->lchild;

            }
        else
            {
            p =pop(&stk);

            p = p->rchild;
            }
    }
cout<<endl;
}
void createpre(int pre[],int n,struct node*p)
{
    struct stack st;
    stackcreate(&st,100);
    struct node *t;
    int i=0;
    root=new node[sizeof(node)];
    root->data=pre[i++];
    root->lchild=root->rchild=nullptr;
    p=root;
    while(i<n)
    {
        if(pre[i]<p->data)
        {
            t=new node[sizeof(node)];
            t->data=pre[i++];
            t->lchild=t->rchild=nullptr;
            p->lchild=t;
            push(&st,p);
            p=t;
        }
        else if(pre[i] > p->data && pre[i] < isstackempty(st) ? 32767 : int ((stacktop(st))->data))
        {
            t=new node[sizeof(node)];
            t->data=pre[i++];
            t->lchild=t->rchild=nullptr;
            p->rchild=t;
            p=t;

        }
        else
            {p=pop(&st);
        }
    }
}

int main()
{
    int A[]={30,20,10,15,25,40,50,45};
    createpre(A,8,root);
    cout<<"\n";

    iterativePreorder(root);
return 0;

}
