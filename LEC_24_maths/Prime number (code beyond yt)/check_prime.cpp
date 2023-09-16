//check if a given number is prime or not - in optimized way (count and sqrt() approach)
#include<iostream>
#include<cmath>
using namespace std;

int main()
{   
    /*1. reason: as we limited our range to sqrt(n) as after sqrt factors gonna interchange  (for ex: for 8 factors are 1*8,2*4,4*2,8*1
     if u notice afte 2*4 the remaining 2 factors-> 4*2 and 8*1 are nothing but interchange of 1*8 and 2*4) so we will count all factors
     BUT limit our range to half( or sqrt(n)) and increment count by 2. But one pair(equivalents) gonna counted two times if we simply increment 
    count by 2(count = count+2) ,so that we need to put a condition for that pair to be not counted again( as by count= count+2 , 
     we are assuming  for i*j there's a j*i pair as well so we are counting it , but for i*i we dont need to count i*i again as its same)
    that is why we dont increment count by 2 for equivalent pairs */
    system("cls");
    int a = 1000000007; //10^9 +7
    int count=0;

    for( int i=1 ; i*i <=a; i++)
    {
        if( a%i == 0 )
        { 
             count++;       
             if( a/i != i)      //1.
                count++;
        }    
    }
    //now check if count is 2 i.e given number have only 2 factors (1 and itself) then given number is prime
    cout<<count<<endl;
    if(count == 2)
        cout<<"yes "<<a<<" is Prime";
    else
        cout<<"No "<<a<<" is not a Prime";
    return 0;
}