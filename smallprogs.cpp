//small programs

#include<iostream>
using namespace std;

//count different notes of given value
void countnotes()
{
    int amt;
    cout<<"Enter the amount : ";
    cin>>amt;
    int hun,fif,twen,one;
    hun=fif=twen=one=0;
    
    switch(1)
    {

        case 1:     //if(amt >100)
        {
             hun=amt/100;
            amt=amt%100; 
            
        } 
       

        case 2:     //(if amt>50)
        {
            fif=amt/50;
            amt=amt%50 ;
            
        }

        case 3:     //if(amt>20)
        {
            twen=amt/20;
            amt=amt%20;
        }

        case 4:        //if(amt>1)    
        {
            one=amt/1;          
            amt=amt-one;
        }
    }
    cout<<"Hundred Rs. Notes: "<<hun<<"\nFifty Rs. Notes: "<<fif<<"\nTwenty Rs. Notes: "<<twen<<"\nONe Rs. Notes: "<<one;
}


int fact(int n)     //local function
{
    int sum=1;
    while(n)
    {
        sum=sum*n;
        n--;
    }
  
    return sum;
    
} //end of factorial function used in comb function

//calculate nCr combination formula
void comb()
{
    int n,C,r;
    n=C=r=1;
    cout<<"Enter values of n and r ";
    cin>>n>>r;

   C=  fact(n) / ( fact(r) * fact(n-r));

   cout<<"nCr is "<<C;

}//end of comb()

//AP
void AP()
{
    int n;
    cout<<"enter the place you want to see in ap ";
    cin>>n;
        //AP is 3*n +7
    cout<<((3*n)+7);

}

//count no. of 1(true) bit in a 2 numbers 
void countbit()
{
    cout<<"Enter the 2 numbers ";
    int a,b,count=0;
    
    cin>>a>>b;
    int c=a,d=b;

    while(a)
    {
       int bit= a&1;
       if(bit==1)
            count++;

        a=a>>1; 
    }
    while(b)
    {
        int bit = b & 1;
        if(bit==1)
            count++;
        
        b= b >> 1;
    }
    cout<<"total number of true bits in "<<c<<" and "<<d<<" are "<<count;
}//end of countbit function

void fibonacci()
{
    int n;
    cout<<"Enter the place of which we want the term in fibonacci series(limited to first 20 number only)\n";
    cin>>n;
    int a[20];
    a[0]=0, a[1]=1;

    int sum=a[0]+a[1];

    for(int i=2 ; i<=19 ; i++)
    {
        a[i]= a[i-2]+ a[i-1];   //formula for making fibonacci series
    }
    

    cout<<"At "<<n<<"th place the fibonacci number is "<<a[n-1];
}
int main()
{   
    system("cls");
    //countnotes();
    //comb();
    //AP();
    //countbit();
    fibonacci();

   return 0;
}
