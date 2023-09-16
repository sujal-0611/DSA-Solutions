//next small element
//reverse stack using recursion
#include<iostream>
#include<stack>
#include<vector>
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

void insert_at_bottom(stack<int>& s,int data)
{
    //base case
    if(s.empty())
    {
        s.push(data);
        return;
    }
    //store top element
    int element = s.top();
    //delete top element
    s.pop();

    //recursive call    (sending new stack without top element)
    insert_at_bottom(s,data);

    //now add back the top element to the stack
    s.push(element);
}

//APPROACH 1: brute force T.C = O(n^2)
vector<int> next_small1(vector<int> vec)
{   
    vector<int> ans;
    for(int i =0; i<vec.size();i++)
    {   
        int min=vec[i]; int pos=0;

        for(int j=i+1; j<vec.size();j++)
        {
            if(min >vec[j])
            {   
                pos=1;
                min=vec[j];
                break;
            }
        }
        if(pos==1)
            ans.push_back(min);
        else
            ans.push_back(-1);
    }
    return ans;
}

//APPROACH 2: using stack
vector<int> next_small2(vector<int> vec)
{
    vector<int> ans(vec.size());
    stack<int> s;
    s.push(-1);

    int n = vec.size()-1;
    while(n>=0)
    {   
        while(s.top() >=vec[n])
            s.pop();
        
        //now top has element smaller than vec[n]
        //ans.push_back(s.top()); //in this case answer will be stored in reversed order
        ans[n] = s.top();   //this one store in original order
        s.push(vec[n]);
    
        n--;
    }
    return ans;
}

void abc(vector<int> vec)
{
    vector<int> ans;

    for(int i =0; i< vec.size()-1; i++)
    {
        if(vec[i] > vec[i+1])
            ans.push_back(vec[i+1]);
        else
            ans.push_back(-1);
    }
    ans.push_back(-1);

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
}
int main()
{   
    system("cls");
    vector<int> vec={2,1,0,4,3};
    vector<int> ans;

    /*
    //ans = next_small1(vec);
    ans = next_small2(vec);
    
    for(int i=0; i<ans.size();i++)
        cout<<ans[i]<<" ";  */

    abc(vec);
  


    return 0;
}