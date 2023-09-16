//*****leet code question : power of 2:- check if given number is a power of 2 or not
#include<iostream>
#include<climits>
using namespace std;



 int power(int a,int n)
    {
        int sum=1;
        while(n)
        {
           if(sum< INT_MAX/2)  
                return sum;
            sum=sum*a;
            n--;
        }

        return sum ;
    }
    
bool powof_two(int a)
{
    int ans =1,i=0;
    while(i<31)
    {
        if(ans==a)
            return true;

        ans=ans*2;
        i++;
        
    }
    return false;

}

//better approach using setbits i.e of binary form of given number has only 1 true bit then its a power of 2
bool powof_two2(int a)      
{   
    int count=0;
    while (a)
    {
        int bit=a & 1;
        if(bit==1)
            count++;

        a= a>>1;
    }
    if(count == 1)
        return true;
    else
        return false;
}

int main()
{   
    system("cls");
    cout<<"enter the number"<<endl;
    int a;
    cin>>a;
    cout<<endl<<a<<" is a power of 2 ? ";
    /*
     if(powof_two(a))       
        cout<<"true";
    else
        cout<<"false";    
        */

    if(powof_two2(a))       //powof_two2() is better than powof_two()
        cout<<"true";
    else
        cout<<"false";    
    
    return 0;
}