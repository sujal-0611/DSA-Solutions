#include<iostream>
#include<climits>
using namespace std;

void pow_of_3(int a)
{
    int b=1;
    while(b< INT_MAX/2)
        b=b*3;
        

    cout<<b;

}
int main()
{   
    system("cls");
    int a;
    cout<<"Enter the number ";
    cin>>a;
    pow_of_3(a);
    
    return 0;
}