#include<iostream>
#include<cmath>
using namespace std;

void  bintodeci(int a)
{
    int sum=0;
    double i=0;
    int b=a;
   

        while(b>0)
        { 
            sum= ((b%10) * int(pow(2,i)) ) + sum;
            i++;
            b=b/10;
        }
        cout<<"Decimal Equivalent of " <<a <<" is "<<sum;

}
int main()
{   
    system("cls");
    int a=101;
    bintodeci(a);
    
    return 0;
}