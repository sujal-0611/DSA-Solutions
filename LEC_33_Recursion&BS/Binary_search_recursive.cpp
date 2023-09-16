//BINARY SEARCH USING RECURSION
#include<iostream>
using namespace std;

bool BS( int *arr,int start, int end,int num)
{
    //base case 1
    if( start > end)
        return false;
    
    int mid = start + ((end-start)/2);

    if( arr[mid] == num)    //base case 2
        return true;

    //solving one case
    if(num > arr[mid] )    //processing 1 and RR
        return BS(arr,mid+1,end,num);
    else        
        return BS( arr,start,mid-1,num);    //processing 2 and RR
}
int main()
{   
    system("cls");
    int arr[]= { 1,2,3,4,5,6,7};
    int start = 0, end = (*(&arr+1)-arr) -1;
    int num = 43;
    bool res;
    res = BS( arr, start,end,num);
    if(res)
        cout<<"present";
    else
        cout<<"absent";
    
    return 0;
}