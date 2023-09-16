#include<iostream>
using namespace std;

void fiboacci(int n)
{
    int a=0,b=1;
    int sum=0;
   //fibonacci series is like  0, 1, 1, 2, 3, 5, 8.....
    for(int i=1;i<n;i++)
    {  
        
        sum=a+b;               //first adding 2 values 
        cout<<(a+b)<<" ";
        a=b;                //then storing vlaue of 2nd variable(i.e b) which is after a
         b=sum;             //DP..... storing sum in b
        
    }
}

int main()
{   
    system("cls");
    int a=9;
    cout<<"Fibonacci series is as follows "<<endl;
    cout<<0<<" "<<1<<" ";
    fiboacci(a);
    return 0;
}