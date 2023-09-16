//First non-repeating character in a stream
#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>

using namespace std;

string non_rep(string A)
{
    queue<int> q;
    vector<int> vec(26);
    string s="";

    //mapping i.e counting which character appearing how many times 
    for(int i=0; i< A.length();i++)
    {
        int num = A[i] -'a';
        vec[num]++;
        
        q.push(A[i]);

        while(!q.empty())
        {
            //repeating character
            num = q.front()-'a';
            if(vec[num]>1)
                q.pop();
            else         //non repeating character
            {
                    s.push_back(q.front());
                    break;
            }
        }

        //now here control reaches only if either queue is empty or while loop encountered break(ie queue is not empty)
        if(q.empty())
            s.push_back('#');     
    }
    return s;
   
}

int main()
{   
    system("cls");
    string A="aabc";

    string res;
    res=non_rep(A);
    cout<<res;
    
    return 0;
}