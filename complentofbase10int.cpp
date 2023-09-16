//leet code question compliment of base 10 integer
#include<iostream>
#include<cmath>
using namespace std;

int bitwiseComplement2(int n)
{
    int bin=0; 
    int a=n;
    int sum=0;   
    int b=~n, i=0; 

    while(a)
    {
        int bit=b &1;
        b=b>>1;
        sum=( bit * pow(2,i) ) + sum;
        i++;
        a= a >> 1;
    }
    return sum;


}

int bitwiseComplement(int n) 
{   
        int bin=0; 
        int a=n;
        int mask=0;   
        int b=~n;   
    
        while(a)                            
        {     
            mask = mask << 1;  /*then left shift by 1 so that at the end of loop we can have our mask which
                                         we will bitwise AND with NOT n to get answer we want  */                                 
             a= a >> 1;  
             mask = ( mask | 1 ) ;    //mask or 1       
            
        }
        int ans = (~n) & mask;  //bitwise and of complement of n and mask
      
            
            
            return ans;
}

int main()
{   
    system("cls");
    int x=5;
    cout<<"compliment of "<<x<<" in decimal form is "<<bitwiseComplement(x);      //from love baber video
    //cout<<"compliment of "<<x<<" in decimal form is "<<bitwiseComplement2(x);      // my own solution
    return 0;
}