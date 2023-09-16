//Leet code: COunt Prime By Sieve of Eratosthenes
#include<iostream>
#include<vector>
using namespace std;

//Brute force
int prime1(int n)
{
    int count=0;
    int rec=1;

    if(n==0)
        return 0;
    else if ( n==1)
        return 0;

    for(int i=2;i<n;i++)
    {   
         rec=1;
        for(int j=2; j< i; j++)
        {
            if( i%j == 0)
            { 
                rec=0;
                break;
            }
        }
        if(rec)
        {    
            count++;  
        }
       
    }
    
    return count;    
}


//Optimized Solution: use "sieve of eranthroses" approach
int prime2(int n)
{
    //Optimized Solution: use "sieve of eranthroses" approach
    vector<bool> prime(n+1,true);
    int count=0;
    prime[0]=prime[1]=false;

    for(int i=2; i<n; i++)      //for numbers between 2 to n
    {
        if( prime[i] )    //if prime[i] is true.(if true then its prime no.)
        {
            count++;

            for(int j=2*i; j<n; j=j+i)    //and make all numbers that comes under the table of i false
                prime[j]=false; 
        }
    }
    return count;
}

//optimization of sieve approach
int prime3(int n)
{
    //Optimized version of "sieve of eranthroses" approach
    /* 1. for outer loop run it till i is less than sqrt(n) or i*i<n
    reason for reducing range to sqrt(n) is because inner loop start with j= i* i and till j<n 
    when i in outer loop cross certain value from where i*i is alway out of range of n(in innner loop) 
    so in outer loop further processing would be waste since inner loop's condition will going to remain false

    2.and inner loop should start from i*i not 2* i as if we start with 2*i
     we gonna make those indexes false again which are already false 
     also in optimized version we need to declare 'i' and 'j' as long long , since i*i can go out of range if int
    */
    vector<bool> prime(n+1,true);
    int count=0;
    prime[0]=prime[1]=false;

    for(long long  i=2; i*i<n; i++)      //optimization 1.
    {
        if( prime[i] )    //if prime[i] is true.(if true then its prime no.)
        {
            //count++;

            for(long long  j=i*i; j<n; j=j+i)    //Optimization 2.
                prime[j]=false; 
        }
    }
    for(int i=0;i<n;i++)
        if(prime[i] == true)
            count++;
    return count;
}
int main()
{   
    system("cls");
    int n=20;
    //cout<<"the no of primes less than "<<n<<" are "<<prime1(n);   //brute force
    //cout<<"the no of primes less than "<<n<<" are "<<prime2(n);   //BASiC sieve approach
    cout<<"the no of primes less than "<<n<<" are "<<prime3(n);     //further optimization of sieve

    
    return 0;
}