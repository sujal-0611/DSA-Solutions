#include<iostream>
using namespace std;

int sum(int *arr,int size)
{
    if( size == 0)  //base cases
        return 0;
    if( size == 1)
        return arr[0];
    
    int sums = arr[0] + sum(arr+1, size-1); //processing + RR
    //add arr[0] to sum and make call for next element, i.e when we pass arr+1 on next FC 
    //int *arr is get intialized with (arr+1) address i.e int *arr get address of 1st index as base index 
    //so in second iteration arr[0] would be arr[1] of original and so on
    return sums;

    //return arr[0]+sum(arr+1,size-1);
}
int main()
{   
    system("cls");
    int arr[]={4,6,3,8};
    int Size= *(&arr+1)-arr;
    cout<<"Sum is: "<<sum(arr,Size);
    
    return 0;
}