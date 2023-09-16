//calculating a raise to b ( a^b) using fast exponentiation method (plus in recursive way)
#include<iostream>
using namespace std;

//iterative way
int power1(int a,int b)
{
    int sum =1;
    while(b >0)
    {
        if( b&1)    //for odd case will run atleast 1 time
            sum = sum*a;

        a = a * a;
        b = b>>1;
    }
    return sum;
}

//recursive way : optimized(my code but not so good)
int power2(int a,int b,int sum)
{   
     
    if(b ==0)   //BC
        return sum;

    if( b&1)            //from line 25 to 29 : solving one case 
       sum = sum*a;
    
    a = a*a;        
    b= b>>1;

    return power2(a,b,sum); //recursuve call  //and let recusrsion handle rest

}

//more optimized recursive way  (not need of passing sum)
int power3(int a,int b)
{   
    if( b == 0)     //Base case 1
        return 1;

    if(b == 1)      //base case 2
        return a;
    
    //Recursive call
    int sum = power3( a,b>>1);  //finding a^b/2

    //now according to odd or even do fast exponentiation to find a^b 
    //(from line 49 to 53: solving one case and let recursion(line 40 to 47) handle rest of cases)
    if( b&1)
        return a*sum *sum;      //fast exponentiation :odd case a^b= a* a^b/2 * a^b/2
    else
        return sum*sum;         //fast exponentiation : even case a^b= a^b/2 * a^b/2
}
int main()
{   
    system("cls");
    int a =2,b =11;
    int sum =1;

    cout
        <<a<<" raise to "<<b<<" is "<<power1(a,b) //iterative way  
        <<endl<<a<<" raise to "<<b<<" is "<<power2(a,b,sum)     //recursive way
        <<endl<<a<<" raise to "<<b<<" is "<<power3(a,b)     //recursive way - more optimized
        ;
    
    return 0;
}