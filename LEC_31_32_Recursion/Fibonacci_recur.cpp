//Fibonacci series by recursion
#include<iostream>
using namespace std;

//1. if a and b are also passed recursive function to print fibonacci series
void fibonacci1(int a,int b,int n)
{
    //base case
    if(n==0)
        return;
    
    int sum=a+b;
    cout<<sum<<" ";
    fibonacci1(b,sum,n-1);       //recursive relation: after sum a becomes b and b becomes sum....
}

//if only the no of terms(n) till we have processs fibonacci is given
//recursive function to find nth fibonacci number
int fibonacci2(int n)
{
    //base condtions
    if(n==0 || n==1)        //for f(0) and f(1) return n(as obviously the condition is true becuase n is 0 or 1)
        return n;

    int a=fibonacci2(n-1);
    int b=fibonacci2(n-2);
    
    return a+b; //sum
    
}
int main()
{   
    system("cls");
    //int a=0,b=1;
    int n=8;
    //cout<<a<<" "<<b<<" ";
    //fibonacci1(a,b,n-2);  //if a and b are also passed

    cout<<n<<"th term is "<<fibonacci2(n); // if only no of terms are passed
    
    return 0;
}