//finding GCD(or HCF) of 2 number using euclid's theorem
#include<iostream>
using namespace std;

int gcd(int a, int b) 
{
    
    if(a==0)
    return b;

    if(b==0)
    return a;

    while(a != b) {

        if(a>b)
        {
            a = a-b;
        }
        else{
            b = b-a;
        }
    }
    return a;
}

int main() 
{
    
    int a,b;
    cout << "Enter the Values of a and b" << endl;
    cin >> a >> b;

    cout << " The GCD of " << a << " & " << b << " is: " << gcd(a,b) << endl;



    return 0;
}