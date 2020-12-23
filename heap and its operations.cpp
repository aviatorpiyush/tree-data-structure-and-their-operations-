#include<iostream>
using namespace std;
void insert(int A[],int n)
{
    int temp;
    int i=n;
    temp=A[i];
    while(i>1 && temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}
int Delete(int A[],int n)
{

    int x,i,j,val,temp;
    val=A[1];
    x=A[n];
    A[1]=A[n];
    A[n]=val;
    i=1;
    j=i*2;



    while(j<n-1)
    {
        if(A[j+1]>A[j])
            j=j+1;
        if(A[i]<A[j])
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=j*2;
        }
        else
            break;

    }

    return val;
    }

int main()
{
    int H[]={0,10,20,30,25,5,40,35};
    // max heap output 40,25,35,10,5,20,30//

    for(int i=2;i<=7;i++)
    {
        insert(H,i);
    }

    // single element deletuion

    cout<<"deleted element is"<<Delete(H,7)<<endl;
    cout<<"deleted element is"<<Delete(H,6)<<endl;

    //heap sort prpogram//
//     for(int i=7;i>=1;i--)
//    {
//         cout<<Delete(H,i)<<endl;
//    }



    for(int i=1;i<=7;i++)
    {
        cout<<H[i]<<" ";
    }
    cout<<endl;



return 0;
}
