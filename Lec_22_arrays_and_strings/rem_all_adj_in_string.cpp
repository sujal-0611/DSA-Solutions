
#include<iostream>
#include<stack>
using namespace std;
/*
string removeDuplicates(string s) {

        int n=s.length();
        int i=0;
        while( i<s.length()-1)
        {
            if( s[i] == s[i+1])
            {
                int t=i;
                //s.replace(i,2,"");
                
                i=i-1;
                s.erase(s.begin()+t,s.begin()+t+2);
               
            }
            else 
                i++;
        }
     
        return s;
    }
    */

int main()
{   
    system("cls");
    string s="abbaca";

    stack<char> st;
    st.push(s[0]);
    for(int i=1; i< s.length();i++)
    {   if(!st.empty() && st.top() == s[i])
                st.pop();
        else
            st.push((s[i]));       
    }
    s="";
    while(!st.empty())
    {
        s= s+st.top();
        st.pop();
    }
    int start=0,end=s.length()-1;
     while( start <= end )
        {
            swap(s[start++],s[end--]);
        }
    cout<<s;

    
    return 0;
}