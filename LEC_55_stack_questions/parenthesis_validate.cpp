//validate parenthesis
#include<iostream>
#include<stack>
using namespace std;

bool check_parenthesis(string s)
{
    stack<char> st;

    for(int i=0; i<s.length();i++)
    {   
        //if its s[i] is opening bracket
        if( s[i] =='{' || s[i] =='(' || s[i] =='[')
        {
            st.push(s[i]);
        }
        else        //its a closing bracket
        {
            if(!st.empty())     
            {
                int ch= st.top();
                if( (ch =='{' and s[i]=='}') || ( ch =='(' and s[i] ==')' ) ||(  ch=='[' and s[i] == ']') )
                {
                    st.pop();
                }
                else    
                    return false;
            }
            else    //i.e stack is empty but there's s still a open bracket i.e unbalanced string
            {
                return false;
            }
        }
    }
    if(st.empty())   //i.e for all closed brakcets , all open brackets are poped from stack and now stack is empty i.e BALANCED
        return true;
    else
        return false;
}
int main()
{   
    system("cls");
    string s = "[{()}]()";  //this is balanced

    bool res =check_parenthesis(s);
    if(res)
        cout<<"Balanced";
    else
        cout<<"Unbalanced";
    
    return 0;
}
