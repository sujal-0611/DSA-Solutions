//basically calculate a^b using fast exponentiation
//CodeStudio:MOdular Exponentiation- to calculate exponents faster (and to accomodate numbers under the range )
#include<iostream>
using namespace std;

//Brute force- solving in O(n)
void mod_expo1(int x,int n,int m)
{
    //bruteforce- solving in O(n)
	//long long res=1;    //to accomodate number larger than 2^31(or 10^9)
    //or simply make res of int type but type cast it to long long(LL) in loop
    int res=1;
	for(int i=0; i< n;i++)
	{
		res= ( 1LL*(res) * (x)%m )%m;  //doing modulation at the same time so that number may not become large
	}
	cout<<res;
}
//Using fast exponentiation and modular approach
void mod_expo2(int x,int n,int m)
{   
    //Using fast exponentiation and modular approach
    //DRY RUN if u dont understand for smaller cases

    int res=1 ; //final result

    while(n>0)
    {
        if(n & 1)   //i.e check if n is odd or not (by bitwise and operation)
        {
            //we typecase it to LL so that we can accomodate immediate answer and get its modulus to get back it in int range
            res= ( 1LL*(res) * (x)%m) %m;   //for odd case: if b is odd then - (a^b/2)^2 * a;
            //this will run atleast one time ( as we right shift n, so n eventually going to become 1)
        }
        x=(1LL* (x)%m * (x)%m)%m; //we are doing %m simultaniously so that answer dont go out of range and also we get the answer
        n=n>>1; 
    }
    cout<<res;
}

int main()
{   
    system("cls");
    int x,n,m;
    x=5;n=2;m=10;
    //mod_expo(x,n,m);  //Brute force- solving in O(n)
    mod_expo2(x,n,m); //Using fast exponentiation and modular approach - better
    return 0;
}