//gfg: circular tour of truck between petrol pumps
#include<iostream>
#include<queue>
using namespace std;

struct petrol_pump
{
    int petrol;
    int distance;
};

//kinda queue approach of front and rear terms
int find_start(petrol_pump p[],int n)
{
    int balance =0;
    int deficit=0;
    int start=0;

    queue<petrol_pump> q;

    for(int i=0; i<n;i++)
    {
        balance = balance + p->petrol - p->distance;

        if(balance<0)   //i.e travelling is possible
        {
            deficit+=balance;

            start = i+1;
            balance = 0;    //making balance back to zero since we gonna start from new "start" point

        }
    }
    if(deficit+balance >=0)
        return start;
    else
        return -1;
}
int main()
{   
    system("cls");
    petrol_pump p[4];

    cout<<"enter petrol and distance for pumps"<<endl;
    int pet,dis;
    for(int i=0; i<4; i++)
    {
        cin>>pet>> dis;

        p->petrol=pet;
        p->distance=dis;
    }

    int starting_point = find_start(p,4);
    cout<<endl<<"starting point should be petrol pump: "<<starting_point;
    
    return 0;
}