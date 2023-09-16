//EKO - SPOJ problem
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

//Brute force
int sawblade1(vector<int> &vec,int M)        //M=7
{
    int n= vec.size();
    int h= -1;
    int temp_M=0;


    while(1)
    {
        h++;
        temp_M=0;
        for (int j = 0; j < n; j++)         //this loops is same in BS
        {
            int sum = vec[j] - h;
            if(sum < 0)
                sum = 0;
            temp_M = temp_M + sum ;
        }
        if(temp_M == M)
        {
            return h;
        }
          
    }  
    

}


bool isvalid(vector<int> &vec,int mid, int M)
{
    int temp_M=0;

    for (int j = 0; j < vec.size(); j++)    //this loop check for that particular height (mid), if its a possible solution or not
    {   if( vec[j] > mid)  //if arr[i] is smaller than mid(current height) ,so that we can ignore -ve answers
        {
            int sum = vec[j] - mid;    
            temp_M = temp_M + sum ;
            // or just write : temp_M= temp_M + (vec[j]-mid);
            if(temp_M >= M)    //if temp_M is possible solution then return true
            {
                return true;
            }
        }
    }
    
    return false;
}

int sawblade2(vector<int> &vec,int M)
{
    sort(vec.begin(),vec.end());

    int s =0,e=vec[vec.size()-1],mid;
    int ans=-1;
   
  
    while(s<=e)     //this loop find take various heights 
    {
        mid= s+ ((e-s)/2);
        if(isvalid(vec,mid,M))
        {
            ans=mid;
            s= mid+1;
        }
        else    
            e= mid-1;
    }
   return ans;
}

int main()
{   
    system("cls");
    vector<int> vec= {20,15,10,17};
    int M=7;

    cout<<"The maximum  height of the sawblade Machine that still allows to cut off at least M metres of wood is: ";
    //cout<<sawblade1(vec,M);         //brute force
    cout<<sawblade2(vec,M);         //Binary search
    
    return 0;
}