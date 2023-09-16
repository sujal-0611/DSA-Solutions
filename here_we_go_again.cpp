#include<iostream>

using namespace std;

int poww(int a,int b)
{
    int prod=1;
    while(b)
    {
        prod=prod*a;
        b--;
    }
    return prod;
}

int main()
{   
    system("cls");
   {
    // swap alternate
    int arr[5]={1,2,3,4,5};
    int size= (*(&arr+1)-arr);
    
    int i=0;
    cout<<"Original array : ";
    for(int i:arr)
        cout<<i<<" ";
    while(i+1<size)
    {
        swap(arr[i],arr[i+1]);
        i+=2;
    }
    cout<<"\nSwapped Array : ";
    for(int i:arr)
        cout<<i<<" ";
   }
    return 0;
}