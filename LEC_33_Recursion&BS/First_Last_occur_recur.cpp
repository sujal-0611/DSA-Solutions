#include<iostream>
#include<vector>
using namespace std;

int BS_firstOccur( vector<int> arr, int target, int start, int end)
{
    if( start > end)    //base case 1
        return -1;
    
    int mid = start + ((end-start)/2);
    
    if( arr[mid] == target && (mid == 0 || target > arr[mid - 1]))   //base case 2
        return mid;
    else if(target > arr[mid])
        return BS_firstOccur(arr, target, mid+1,end);  //rr1
    else
        return BS_firstOccur(arr, target, start, mid-1);   //rr2 this one connected to base case 2
}
int BS_lastOccur( vector<int> arr, int target, int start, int end)
{
    if( start > end)    //base case 1
        return -1;
    
    int mid = start + ((end-start)/2);
    
    if( arr[mid] == target && (mid == arr.size()- 1 || target < arr[mid + 1]))   //base case 2
        return mid;
    else if(  target < arr[mid])
        return BS_lastOccur(arr, target, start,mid-1);  //rr1
    else
        return BS_lastOccur(arr, target, mid+1,end);   //rr2 this one connected  to Base case 2
}

pair<int,int> F_and_L(vector<int> vec, int target)
{
    pair<int,int> p;


    p.first = BS_firstOccur(vec,target,0,vec.size()-1);
    p.second =BS_lastOccur(vec,target,0,vec.size()-1);

    return p;
}
int main()
{   
    system("cls");
    vector<int> vec = {0,1,1,5};
    int target = 1;
    pair<int,int> p;

    p = F_and_L(vec,target);

    cout<<p.first<<" "<<p.second<<endl;
    
    return 0;
}