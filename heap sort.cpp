#include<iostream>
using namespace std;
void insert(int A[],int n)
{
    int i=n;
    int temp;
    temp=A[n];
    while(i>1 && temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}
int Delete(int A[],int n)
{
    int x,i,j,temp,val;
    val=A[1];
    x=A[n];
    A[1]=A[n];
    A[n]=val;
    i=1;
    j=2*i;
    while(j<n-1)
    {
        if(A[j+1]>A[j])
            j=j+1;
        if(A[i]<A[j])
        {
            temp=A[j];
            A[j]=A[i];
            A[i]=temp;
            i=j;
            j=2*i;
        }
        else
            break;


    }
    return val;
}
int main()
{
    int H[]={0,10,20,30,25,5,40,35};
    for(int i=2;i<=7;i++)
    {
        insert(H,i);
    }

    for(int i =1;i<7;i++)
    {
        cout<<H[i]<<" ";

    }
    cout<<endl;
    for(int i=7;i>=1;i--)
    {
        Delete(H,i);
    }

    for(int i =1;i<7;i++)
    {
        cout<<H[i]<<" ";

    }
    cout<<endl;

}
