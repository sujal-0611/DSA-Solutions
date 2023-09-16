//aggressive cow 
#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>

using namespace std;

bool isPossible(vector<int> &stalls,int no_cows,int mid)
{
    int cow_count=1;
    int last_pos= stalls[0];  
    // as we gonna place cows , for example- there are three cows to be placed but first we will place first 2 cows ,in a loop last_pos is 0th index, and i is a second cow
    // we interate 'i' till our condition is true , if our condition is true we update that ith postion as last_pos , as first cow and second cow's placing is done 
    // now that ith index is last_pos i.e second cow and further iterations are next cow (3rd cow ) ,again till our condition is again true ,i.e placing 3rd cow,
    //again! updating last_pos to that ith index(3rd cow), further iterating (for 4t cow ) , also we update cow_count when condition is true .....
    //this process continue till cow_count is <= to no_cows

    for (int i = 0; i < stalls.size(); i++)
    {
        if( stalls[i] -last_pos >= mid )       //if distance between of ith cow and i-1th cow is greater than mid (i.e a possible solution (minimum distance))
        {
            cow_count++;    //increase cow_count

            if(cow_count == no_cows)      //if given no_cows are successfully placed
                return true; 
        
            last_pos=stalls[i]; //update last position to placed cow
        }
    }
    return false;  // i.e not able to return true , not able to reach no_ of cows

}

int agg_cow(vector<int> stalls, int no_cows)
{
    sort(stalls.begin(),stalls.end());

    int sizee= stalls.size();
    int start=0,mid;
    int end=0;
    /*
    int mini=stalls[0],maxi=stalls[0];
    for (int i = 1; i < sizee; i++)
    {
        mini= min(stalls[i],mini);
        maxi= max(stalls[i],maxi);
    } */

    end = stalls[sizee-1];  //search space but here vector is sorted 
    //end= maxi-mini; //search space
    int ans=-1;
    while(start <= end)
    {
        mid = start + ((end-start)/2);
        if(isPossible(stalls,no_cows,mid))
        {
            ans = mid;
            start = mid + 1; //we are moving start if mid is possible answer , bcz we need to find largest of all minimum solutions
                            // if mid is solution , then its obvious that numbers greater than mid are also candidate for solution(also larger as all soluions are min. solutions)
                            //thats why we move start forward 
        }
        else
            end = mid - 1 ; //if mid is way too big for a solution then move end backward
    }
    return ans;
    
}
int main()
{   
    system("cls");
    vector<int> stalls={1,2,4,8,9};
    int no_cows=3;

    cout<<"The largest of all minimum distances to keep cows in stalls is: "<< agg_cow(stalls,no_cows);
    return 0;
}