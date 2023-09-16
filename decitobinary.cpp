//!!!!!Dont use c function pow() it doesnt work well, make ur own power function
//DECIMAL TO BINARY
#include<iostream>
#include<cmath>
using namespace std;
int poww(int a,int b)
{
    int prod=1;
    while(b)
    {
        prod=prod*a;
        b--;
    }
    return prod;
}
void DeciToBin(int a)
{
    int b=a;
    int sum=0;
    int bit,q=0;

    if(a>0)                                            
    {                                                    
        //binary of 12 is   1100                        
        while(a!=0)
        {
            bit= a&1;

            sum= ( bit * poww(10,q) ) + sum;
            //cout<<poww(10,q)*bit<<endl;
            
        // cout<<sum<<endl;
            a= a >>1;
            //cout<<a<<endl;
            q++;
        }
    cout<<"binary Form of "<<b << " is "<<sum<<endl;

    }
   
    else
    {
       
       int e=-a;
       //int arr[32];  //since integer cant store 32 bit length to representation binary we will operate on array
       int arr[32]={0};     //this will initialise all the elements of array with 0 and works for 0 only
       int count=0;
       int k=31; // for entering bits in from the end  in while loop

       while(e!=0)
        {
            bit= e&1;

            arr[k]=bit; //storing everybit in array (full representation of decimal number in binay),
                        // from last
            
            sum= ( bit * poww(10,q) ) + sum;
            //cout<<pow(10,q)*bit<<endl;
            k--;
            e= e >>1;
            q++;
        }
        
       cout<<"binary representation of "<< (-a) <<" is "<<sum<<endl;  

       cout<<"full binary representation of "<< (-a) <<" is ";  
       for(int i=0;i<32;i++)         //output if decimal number is 6 :  00000000000000000000000000000110 
            cout<<arr[i];
       
       
      //1's complement
      for(int i=0;i<32;i++)
      {
          if(arr[i]==1)
                arr[i]=0;
          else
                arr[i]=1;
      }
      
       cout<<"\n1's complement of  "<< (-a) <<" is ";  
       for(int i=0;i<32;i++)        
            cout<<arr[i];
        
        
        /* convert back to its original binary form, so that we can apply trick to calculate 2's complement
        which works directly on original bibary form of a decimal number */
        for(int i=0;i<32;i++)
        {
          if(arr[i]==1)
                arr[i]=0;
          else
                arr[i]=1;
        }
   
            
        //2's complement by using trick on GFG ** this trick works directly on binary of number not on 1s complement
        for( int i=31 ; i>0 ; i-- )
        {
            if(arr[i]==1)   //check from LSB if the bit is 1 or not , if 1 then turn rest bits in 1(if 0) or in 0(if 1)
            {               // ex  number is 0110100 then it will 1001000 is a 2's complement
            
                for(int j = i-1 ; j>=0 ; j--)    // keep j>0 if number is positve and j>=0 if number is negative
                {                                   // as MSB defines if number is negative or +ve ,its for representation only
                    if( arr[j] == 0 )
                        arr[j] = 1;
                }
            break;
            }   
        }
    
        cout<<"\n2's complement of  "<< (-a) <<" is ";  
        for(int i=0 ; i<32 ; i++ )        
            cout<<arr[i];
            
        
        cout<<endl<<endl<<"as negative decimal numbers are basically stored as 2's complement of postive decimal equivalent ";    
        
        arr[0]=1;   //since number is negative i am changing MSB to 1
        cout<<endl<<"Full  binary representation of "<<a<<" is ";
        for(int i=0;i<32;i++)        
            cout<<arr[i];
        
    }   //end of else
}    
int main()
{   
    system("cls");
    int a=-5;
    DeciToBin(a);
    return 0;
}