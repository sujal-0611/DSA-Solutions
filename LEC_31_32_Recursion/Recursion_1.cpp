//by using recursion find 1. factorial 2. power
#include<iostream>
using namespace std;

int factorial(int n)
{   
    //base case
    if( n==0 )  //for 0! is 1
        return 1;

    int smallprob= factorial(n-1);  
    int bigprob = n* smallprob;     //recursive/recurrence relation

    return bigprob;
}

int power(int num,int n)
{   
    //base case
    if(n==0)
        return 1;
    
    return num*power(num,n-1);
}       

void count(int n)
{
    if(n==0)    
        return ;

    cout<<n<<" ";   // for n=5 will print 5 4 3 2 1
    count(n-1);
    cout<<n<<" ";   //for n=5 will print 1 2 3 4 5  ( as first FC is made ,so afer resolving each FC it will print
                    // so at first FC for n=1 is resolved then n=2 and so on..)
}
int main()
{   
    system("cls");
    //int n=3;
    //cout<<"Factorial of 5 is "<<factorial(n);

    //int num=3,pow=4;
   //cout<<num<<" raised to the power "<<pow<<" is: "<<power(3,4);

    int n=5;
    count(n);
    
    return 0;
}