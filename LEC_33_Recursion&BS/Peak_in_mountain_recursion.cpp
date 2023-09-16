#include<iostream>
using namespace std;

int BS_recur(int *arr,int start, int end)
{
    int mid = start + (end-start)/2;

    if( start > end)    //BASE CASE 1
        return 0;

    if( ( arr[mid-1] < arr[mid] ) && (arr[mid] > arr[mid+1] ) ) //BASE CASE 2
        return mid;
    else if(arr[mid-1] < arr[mid])
        return BS_recur(arr,mid+1,end);     //RR1
    else
        return BS_recur(arr,start,mid);     //RR2

}
int peak_index(int *arr,int size)
{
    int ans = BS_recur(arr,0,size-1);
    return ans;
}
int main()
{   
    system("cls");
    int arr[]={0,1,2,5,10,5,2};
    int size = *(&arr+1)-arr;

    int res;
    res = peak_index(arr,size); 
    cout<<res;
    
    return 0;
}