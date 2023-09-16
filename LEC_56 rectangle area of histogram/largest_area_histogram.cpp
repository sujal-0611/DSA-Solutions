//next small element
//reverse stack using recursion
#include<iostream>
#include<stack>
#include<vector>
#include<climits>
using namespace std;

void print(stack<int> s)
{   
    cout<<"Top";
    while(!s.empty())
    {
        cout<<"-> "<<s.top();
        s.pop();
    }
    cout<<endl;
}


//next smaller element indexes
vector<int> next_small(vector<int> vec)
{
    vector<int> ans(vec.size());
    stack<int> s;
    s.push(-1);

    int n = vec.size()-1;
    while(n>=0)
    {   
        while(s.top() !=-1 and vec[s.top()] >=vec[n])
            s.pop();
        
        //now top has element smaller than vec[n]
        //ans.push_back(s.top()); //in this case answer will be stored in reversed order
        ans[n] = s.top();   //this one store in original order
        s.push(n);
    
        n--;
    }
    return ans;
}

//previous smallers indexes
vector<int> prev_small(vector<int> vec)
{
    vector<int> ans(vec.size());
    stack<int> s;
    s.push(-1);

    int n = vec.size();
  
    for(int i=0; i<n; i++)
    {   
        while(s.top() !=-1 and vec[s.top()] >=vec[i])
            s.pop();
        
        //now top has element smaller than vec[n]
        //ans.push_back(s.top()); //in this case answer will be stored in reversed order
        ans[i] = s.top();   //this one store in original order
        s.push(i);

    }
    return ans;
}

int largest_area_histogram(vector<int> heights)
{
    int n= heights.size();
        
        vector<int> next(n);
        next = next_small(heights);

        cout<<endl;
        for(int i=0; i< next.size(); i++)
            cout<<next[i]<<" ";
        cout<<endl;
            
        vector<int> prev(n);
        prev = prev_small(heights);

        cout<<endl;
        for(int i=0; i< prev.size(); i++)
            cout<<prev[i]<<" ";
        cout<<endl;
        
        int max_area = INT_MIN;
        for(int i=0; i<n; i++) 
        {
            int length = heights[i];
            
            if(next[i] == -1)   //for case when all heights are equal
                next[i] = n;    
            
            int breadth = next[i] - prev[i] - 1;    //next[i] have height  smaller than ith height (so to get till that we use  (next[i] -1)th height

            int area = length*breadth;      //storing current height
            cout<<area<<" ";
            max_area = max(area, max_area);     //storing max height
        }
        cout<<endl;
        return max_area;

}
int main()
{   
    system("cls");
    vector<int> vec={2,3,1,2,5,6};

    int max_area = largest_area_histogram(vec);
    cout<<"largest area of a rectangle in histogram is: "<<max_area;
   


    return 0;
}