#include<iostream>
using namespace std;

bool LS(int *arr,int size,int n)
{
    //base case
    if( size==0)
        return false;
                                                                                                                 
    //Processing
    if( arr[0] == n)    //checking for 1 case 
        return true;

    //RR
    return LS(arr+1,size-1,n);  //then let recursion handle rest
}
int main()
{   
    system("cls");
    int arr[] = {4,8,3,27,9,4,78,5};
    int size = *(&arr+1)-arr;
    int n = 4;

    bool res;
    res = LS(arr,size,n);
    if(res == true)
        cout<<n<<" is found out";
    else   
        cout<<n<<" is not present";

    
    return 0;
}