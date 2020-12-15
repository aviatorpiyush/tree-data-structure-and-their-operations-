#include <iostream>
using namespace std;
struct Node
{
struct Node *lchild;
int data;
int height;
int bf;
struct Node *rchild;
};
struct Node *root=nullptr;

int NodeHeight(struct Node *p)
{
int hl,hr;
hl=p && p->lchild?p->lchild->height:0;
hr=p && p->rchild?p->rchild->height:0;
return hl>hr?hl+1:hr+1;
}
int BalanceFactor(struct Node *p)
{
int hl,hr;
hl=p && p->lchild?p->lchild->height:0;
hr=p && p->rchild?p->rchild->height:0;

return hl-hr;
}
struct Node * LLRotation(struct Node *p)
{

struct Node *pl=p->lchild;
struct Node *plr=pl->rchild;
pl->rchild=p;
p->lchild=plr;
p->height=NodeHeight(p);
pl->height=NodeHeight(pl);
if(root==p)
root=pl;
return pl;
}
struct Node * LRRotation(struct Node *p)
{

struct Node *pl=p->lchild;
struct Node *plr=pl->rchild;
pl->rchild=plr->lchild;
p->lchild=plr->rchild;
plr->lchild=pl;
plr->rchild=p;
pl->height=NodeHeight(pl);
p->height=NodeHeight(p);
plr->height=NodeHeight(plr);
if(root==p)
root=plr;
return plr;
}

struct Node * RRRotation(struct Node *p)
{
int lbf,rbf;
struct Node *pr=p->rchild;
pr->bf=0;
p->rchild=pr->lchild;
pr->lchild=p;
lbf=NodeHeight(p->lchild)+1;
rbf=NodeHeight(p->rchild)+1;
p->bf=lbf-rbf;
if(p==root)root=pr;
return pr;
}

struct Node * RLRotation(struct Node *p)
{
int lbf,rbf;
struct Node *pr=p->rchild;
struct Node *prl=pr->lchild;
prl->bf=0;
p->rchild=prl->lchild;
pr->lchild=prl->rchild;
prl->rchild=pr;
prl->lchild=p;
lbf=NodeHeight(p->lchild)+1;
rbf=NodeHeight(p->rchild)+1;
p->bf=lbf-rbf;
lbf=NodeHeight(pr->lchild)+1;
rbf=NodeHeight(pr->rchild)+1;
pr->bf=lbf-rbf;
if(p==root)root=prl;
return prl;

}

struct Node *RInsert(struct Node *p,int key)
{
struct Node *t=nullptr;
if(p==nullptr)
{
t= new Node [sizeof(struct Node)];
t->data=key;
t->height=1;
t->lchild=t->rchild=nullptr;
return t;
}
if(key < p->data)
p->lchild=RInsert(p->lchild,key);
else if(key > p->data)
p->rchild=RInsert(p->rchild,key);
p->height=NodeHeight(p);
if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
return LLRotation(p);
else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
return LRRotation(p);
else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
return RRRotation(p);
else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
return RLRotation(p);
return p;
}
void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

struct Node * Search(int key)
{
struct Node *t=root;
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
int main()
{
struct Node *temp;
root=RInsert(root,30);
RInsert(root,20);

RInsert(root,50);
RInsert(root,40);
RInsert(root,10);

RInsert(root,42);
RInsert(root,46);
Inorder(root);
RLRotation(root);
cout<<"\n";
Inorder(root);
cout<<"\n";

return 0;
}
