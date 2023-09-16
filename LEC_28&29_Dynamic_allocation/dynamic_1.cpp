//dynamic allocation of arrays
#include<iostream>
using namespace std;

void printarr(int *arr,int n)
{
    for(int i=0; i< n;i++)
        cout<<*(arr+i)<<" ";
    cout<<endl;
}
int main()
{   
    system("cls");
    int n;
    cout<<"enter the size for array\n";
    cin>>n;
    
    int* arr=new int[n];    //dynamic allocation to create variable size array

    cout<<"enter the elements till "<<n<<endl;
    for(int i=0; i<n;i++)
        cin>>arr[i];
    
    printarr(arr,n);
    //delete arr[];
    
    return 0;
}