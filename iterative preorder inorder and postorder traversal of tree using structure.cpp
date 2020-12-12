#include<iostream>
using namespace std;

struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};
struct queue
{
    int size;
    int front;
    int rear;
    struct node **qu;
};
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


 // empty of stack definition*//
void create(struct queue *q,int size)
{
    q->size=size;
    q->front =q->rear=0;
    q->qu = new node * [(q->size)*sizeof(node*)];

}

void enqueue(struct queue *q,struct node *x)
{
    if((q->rear+1)%q->size==q->front)
        cout<<"queue is full";
    else
        q->rear=(q->rear+1)%q->size;
        q->qu[q->rear]=x;

}

struct node *dequeue(struct queue *q)
{
    struct node *x=nullptr;
    if(q->front==q->rear)
        cout<<"queue is empty";
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->qu[q->front];
    }
    return x;
}

int isqueueEmpty(struct queue q)
{
return q.front==q.rear;
}

// empty of queue definition //

struct node *root=nullptr;
void Treecreate()
{
struct node *p,*t;
int x;
struct queue q;
create(&q,100);
cout<<"Eneter root value"<<" : ";
cin>>x;
root= new struct node  [sizeof(struct node)];
root->data=x;
root->lchild=root->rchild=nullptr;
enqueue(&q,root);
while(!isqueueEmpty(q))
{
p=dequeue(&q);
cout<<"eneter left child of"<<p->data<<" : ";
cin>>x;
if(x!=-1)
{
t=new struct node [sizeof(struct node)];
t->data=x;
t->lchild=t->rchild=nullptr;
p->lchild=t;
enqueue(&q,t);
}
cout<<"eneter right child of"<<p->data<<" : ";
cin>>x;
if(x!=-1)
{
t=new struct node [sizeof(struct node)];
t->data=x;
t->lchild=t->rchild=nullptr;
p->rchild=t;
enqueue(&q,t);
}
}
}


int Height(struct node *p) {
    int l = 0;
    int r = 0;
    if (p == nullptr){
        return 0;
    }

    l = Height(p->lchild);
    r = Height(p->rchild);

    if (l > r){
        return l + 1;
    } else {
        return r + 1;
    }
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

void iterativeinorder(struct node *p)
{
    struct stack st;
    stackcreate(&st,100);
    while(p!=nullptr || !isstackempty(st))
    {
        if(p!=nullptr)
    {
        push(&st,p);
        p=p->lchild;

    }
    else
    {
        p=pop(&st);
        cout<<p->data<<" ";
        p=p->rchild;
    }
}
cout<<endl;
}

void iterativepostorder(struct node *p)
{
    struct stack st;
    stackcreate(&st,100);
    long int temp;
    while(p!=nullptr || !isstackempty(st))
    {
        if(p!=nullptr)
        {
            push(&st,p);
            p=p->lchild;
        }
        else
        {
            temp=int (pop(&st));
            if(temp>0)
            {
                push(&st,((node*)(-1*temp)));
                p=((node*)temp)->rchild;

            }
            else
            {
                cout<<((node*)(-1*temp))->data<<" ";
                p=nullptr;
            }
        }

    }
    cout<<endl;
}
int main()
{
Treecreate();
cout<<"height"<<Height(root);

cout<<"\n";
cout<<"iterative preorder"<<endl;
iterativePreorder(root);


cout<<"iterative inorder"<<endl;
iterativeinorder(root);
//
cout<<"iterative postorder"<<endl;
iterativepostorder(root);
return 0;
}

