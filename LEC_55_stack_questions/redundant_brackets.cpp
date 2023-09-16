//remove redundant brackets
//reverse stack using recursion
//example  (a+(b*c)) have no redundant bracket
//but this: ((a)+ (b*c)) have reduntant bracket - (a)
#include<iostream>
#include<stack>
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

bool rem_redBrac(string& s)
{
    stack<char> st;
    for(int i=0; i<s.length(); i++) {
        char ch =s[i];
        
        if(ch == '(' || ch == '+' ||ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else
        {
            //ch ya toh ')' hai or lowercase letter
            
            if(ch == ')') {
                bool isRedundant = true;
                
                while(st.top() != '(') {
                    char top = st.top();
                    if(top == '+' ||top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop();
                }
                
                if(isRedundant == true)
                    return true;
                st.pop();
            }
            
        } 
    }
    return false;
}
int main()
{   
    system("cls");
    string s="((a)+(a*c))";

    if(rem_redBrac(s))
        cout<<"there are redundant brackets";
    else
        cout<<"there are no redundant brackets";

    return 0;
}