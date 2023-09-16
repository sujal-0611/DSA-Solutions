#include<iostream>
using namespace std;

int sum_factor(int n)
{
    //using "count logic of checking prime" here to find sum of factors
    int sum=0;

    for( int i=1 ; i*i <=n; i++)
    {
        if( n%i == 0 )  // if n is divisible by i then i is a factor
        { 
            sum = sum + i; 
            if( n/i != i)       // so that we dont count equal factors twice ( i.e the factor and result from number/factor are equal then dont count that factor)
                sum = sum + (n/i); 
        }    
    }
   return sum;
}
int main()
{   
    system("cls");
    cout<<"sum of factors is "<<sum_factor(36);

    return 0;
}