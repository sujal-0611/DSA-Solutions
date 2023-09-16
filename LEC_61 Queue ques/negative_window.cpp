//First negative number in window of k size
#include<iostream>
#include<vector>
#include<deque>
using namespace std;

//brute force T.C-O(n*k)l S.C-O(N-K+1) WORKS GREAT!!
vector<int> neg_win(vector<int> vec,int k)
{
    int n=vec.size();
    vector<int> ans;

    //run a loop for whole array till size-k
    for(int i=0; i<n-k+1; i++)
    {   
        int pos=0;
        //loop for every window of size k  
        for(int j=i; j<i+k; j++)
        {
            if(vec[j] < 0)
            {
                pos=1;
                ans.push_back(vec[j]);
                break;
            }
        }
        if(pos ==0)         //if no negative no found in a particular window then push 0
            ans.push_back(0);
    }
    return ans;
}

// better approach using DeQue
vector<int> neg_win2(vector<int> vec,int K)
{   
    int N=vec.size();
    deque<int> dq;
    vector<int> ans;
    
    // step 1 -> process first k size window
    for(int i = 0; i < K; i++) 
    {
        if(vec[i] < 0)
            dq.push_back(i);
    }
    
    // step 2 -> find the answer for first k size window
    if(!dq.empty()) 
        ans.push_back(vec[dq.front()]);
    else 
        ans.push_back(0);
    
    // step 3 -> process remaining windows
    for(int i = K; i < N; i++) 
    {
        // step 4 -> pop previous elements from the dequeue
        if(!dq.empty() and (i - dq.front() >= K))   //means if the element(whose index is at dq.front is outside of window or not if yes then pop)
            dq.pop_front();
        
        // step 5 -> push new element in the dequeue
        if(vec[i] < 0) 
            dq.push_back(i);
        
        // step 6 -> find answer for every window
        if(!dq.empty()) 
            ans.push_back(vec[dq.front()]);
        else 
            ans.push_back(0);
    }
    
    // step 7 -> return the final vector which stores the answer
        return ans;
}

//best approach

int main()
{   
    system("cls");
    vector<int> vec = {12, -1, -7, 8, -15, 30, 16, 28};
    vector<int> ans;
    int k=3;
    ans = neg_win(vec,k);

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    
    return 0;
}