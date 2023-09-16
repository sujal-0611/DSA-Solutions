#include<iostream>
using namespace std;

void update(int *a)
{
    *a=*a+1;
    a=a+1;
}

int main()
{   
    system("cls");  
    int a=5;
    int *ptr=&a;
    cout<<"Before "<< ptr<<endl;
    cout<<"Before "<< *ptr<<endl;       

    update(ptr);

    cout<<"after "<<ptr<<endl;  //address remains same bcz it was passed by value
    cout<<"after "<<*ptr<<endl; //variable's value actually gets changed    
    
   
    
    return 0;
}