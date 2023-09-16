#include<iostream>
using namespace std;

int climb_stairs(int n)
{   
    //base cases
    if( n<0)
        return 0;
    if(n == 0)
        return 1;
    
    return climb_stairs(n-1) + climb_stairs(n-2);   //RR
}
int main()
{   
    system("cls");
    int stairs =5;

    int ans= climb_stairs(stairs);
    cout<<" The number of ways we can climb the "<<stairs<<" stair is "<<ans;
    
    return 0;
}