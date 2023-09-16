#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int>& stalls,int cur_min,int cows)
{
    //function to determine if with current ans(cur_min) if we can place all cows 

    int cow_count =1;
    int last_pos= stalls[0];   
    /* as we gonna place cows , for example- there are three cows to be placed but first we will place first 2 cows ,in a loop last_pos is 0th index, and i is a second cow
     we interate 'i' till our condition is true , if our condition is true we update that ith postion as last_pos , as first cow and second cow's placing is done 
    now that ith index is last_pos i.e second cow and further iterations are next cow (3rd cow ) ,again till our condition is again true ,i.e placing 3rd cow,
    again! updating last_pos to that ith index(3rd cow), further iterating (for 4t cow ) , also we update cow_count when condition is true .....
    this process continue till cow_count is <= to no_cows*/
    
    for( int i=1; i< stalls.size(); i++)
    {
       int temp_distance = stalls[i]-last_pos; 

       if( temp_distance >=cur_min)
       {
            cow_count++;
            last_pos = stalls[i];

            if(cow_count >=cows)    //if cow count reached our no of cows then return true (we were able to place all aggressive cows succeessfully)
                return true;
       }
    }
    return false;   //i.e loop is over (traversed all stalls) and we still not able place all cows("cow_count" didnt "reached cows") then return false
}

//Recursive BS function applied on search space
int BS_recur(vector<int>& stalls,int start,int end, int cows,int ans)
{
    int mid = start+ ((end-start)/2);
    //BC
    if( start > end)    return ans;

    if( isPossible(stalls,mid,cows))
    {
        ans = mid; //store possible solution
        return BS_recur(stalls,mid+1,end,cows,ans); //if mid is possible sol then look for bigger(that is why start=mid+1)
    }
    else
        return BS_recur(stalls,start,mid-1,cows,ans);   //if mid is too big to accomodate all cows
}
int agg_cows(vector<int>& stalls, int cows)
{
    sort(stalls.begin(),stalls.end());  //sorting aray for isPossible() function 

    int start = 0,end = stalls[stalls.size()-1]-stalls[0];  //getting max difference 

    int ans = -1;   //default answer if placing of cows are not possible
    return BS_recur(stalls,start,end, cows,ans);    //call to recursive BS function
}
int main()
{   
    system("cls");
    vector<int> stalls= {4,2,1,3,6};
    int cows = 2;

    cout<<" the largest of all min distance with which aggressive cows are kept is "<<agg_cows(stalls,cows);
    
    return 0;
}