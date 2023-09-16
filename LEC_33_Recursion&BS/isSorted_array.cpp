//check if array is sorted or not by recursion
#include<iostream>
#include<vector>
using namespace std;

//my way (not so good)
bool sorted1(vector<int> vec,int n)
{   
    if( n+1 >= vec.size())  //base case
        return true;

    if( vec[n] >  vec[n+1])     //processing
        return false;
    
    return sorted1(vec,n+1); //recursive relation
}

//proper way to recursive solve when array and its size is passed
bool sorted2(int *arr, int size)
{
    //base cases
    if( size == 0 || size == 1)     //if size is 0 or 1 for array then consider it sorted and return 1
        return true;

    //processing
    if( arr[0] > arr[1])        //samjho
        return false;

    //RR
    return sorted2( arr+1, size-1);     //sending 1st index address so that new array(copy created) start from 1st index of older array 
}
int main()
{   
    system("cls");
    vector<int> vec={ 1,2,3,9,5,6,7,8};
    int arr[]= {1,2,3,4,9,6,7,8};
    int size = *(&arr+1) - arr;

    bool res; 
    //res = sorted1(vec,0);
    res= sorted2(arr,size);

    if( res)
        cout<<"array is sorted";
    else
        cout<<"array is not sorted";
    
    
    return 0;
}