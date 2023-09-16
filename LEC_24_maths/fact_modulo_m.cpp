//calculate 212! mod m
#include<iostream>
using namespace std;

int main()
{   
    system("cls");
    int a=212;
    cout<<"factorial of \""<<a<<" modulo m\" is: ";
    int res=1;
    while(a)
    {
        res = (res*a)%1000000007;
        a--;
    }
    cout<<res<<endl<<"where m is 1000000007 or 10^9+7";
    
    return 0;
}
