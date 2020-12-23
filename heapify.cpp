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
void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
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
            swap(A,i,j);
            i=j;
            j=2*i+1;

        }
        else
            break;

    }

    return val;
    }

void Heapify(int A[], int n)
{
    // # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i=(n/2)-1; i>=0; i--){

        int j = 2 * i+1;  // Left child for current i

        while(j < n-1){
            // Compare left and right children of current i
            if (A[j] < A[j+1]){
                j = j+1;
            }

            // Compare parent and largest child
            if (A[i] < A[j]){
                swap(A, i, j);
                i = j;
                j = 2 * i+1;
            } else {
                break;
            }
        }
    }
}int main() {

    int A[] = {5, 10, 30, 20, 35, 40, 15};
    for(int i=1;i<=7;i++)
    {
        cout<<A[i]<<" ";
    }
 cout << endl;
    Heapify(A,7);
     for(int i=1;i<=7;i++)
    {
        cout<<A[i]<<" ";
    }


    cout << endl;

//    int B[] = {5, 10, 30, 20};
//    Print(B, sizeof(B)/sizeof(B[0]), "B");
//
//    Heapify(B, sizeof(B)/sizeof(B[0]));
//    Print(B, sizeof(B)/sizeof(B[0]), "Heapified B");

    return 0;
}
