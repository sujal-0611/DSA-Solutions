//Macros
#include<iostream>
using namespace std;
#define PI 3.14
#define Area(r) PI*r*r  //chained marcro(i.e PI(another macro) is written in this)

int main()
{   
    system("cls");
    
    int r=3;
    cout<<"area of a circle is "<<Area(r);
    
    return 0;
}