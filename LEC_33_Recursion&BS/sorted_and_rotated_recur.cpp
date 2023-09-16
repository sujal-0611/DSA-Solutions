//RECURSIVE SOLUTION FOR "sorted and rotated" - code studio
#include<iostream>
using namespace std;

//FUNCTION OT FIND PIVOT
int BS_recur_pivot(int *arr,int start,int end)
{   
    int mid = start + ((end-start)/2);
    if(start > end) //BASE CASE1
        return 0;

    if( arr[mid-1] > arr[mid] && arr[mid] < arr[mid+1]) //BASE CASE 2
        return mid;
    else if( arr[mid] > arr[0])
        return BS_recur_pivot( arr, mid+1,end);   //comparision with first element ot determine if we are on right side or left side of pivot
    else if (arr[mid] < arr[0])
        return BS_recur_pivot(arr,start,mid);
}

//BS to find element
int BS_recur(int* arr,int start , int end,int k)
{
    int mid = start + ((end-start)/2);

    if(start>end)   //B.C 1
        return -1;

    if( arr[mid] == k)  //B.C 2
        return mid;


    if ( k > arr[mid])
        return BS_recur(arr,mid+1,end,k);
    else
        return BS_recur(arr,start,mid-1,k);
}

int S_and_R(int* arr,int size,int k)
{
    int pivot =BS_recur_pivot(arr,0,size-1);
    if( k == arr[pivot])
        return pivot;

    //checking for right side of pivot (including special case if pivot is zero)
    if( ( pivot ==0 or pivot < arr[size-1] ) and k > arr[pivot])   
        return BS_recur(arr,pivot,size-1,k);
    else
        return  BS_recur(arr,0,pivot-1,k);
    
}
int main()
{   
    system("cls");
    int arr[] = {5, 6, 7 ,8, 9 ,10 ,1 ,2, 3};
    int size = *(&arr+1)-arr;
    int k=10;

    int res = S_and_R(arr,size,k);
    cout<<res;
    
    return 0;
}