#include<iostream>
using namespace std;

void saydigits(int n)
{   
    if ( n == 0)  //base case
        return;

    string names[]={ "zero","one","two","three","four","five","six","seven","eight","nine"};
    //cout<<names[n%10]<<" ";     //this one print two one four (reversed)
    saydigits(n/10);    //RR
    cout<<names[n%10]<<" ";     //this one orin four one two (original order)
}
int main()
{   
    system("cls");
    int n=140;

    saydigits(n);
    
    return 0;
}