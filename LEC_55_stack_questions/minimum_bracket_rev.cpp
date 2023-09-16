//minimum braket reversal
//condtions to be valid - no of closed brackets = no of open brackets
//                      - there should be open bracket before closed bracket
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
//kisi ka code copy kiya h 
int findMinimumCost(string str) {
   int n = str.size(); stack<char>s;
    int count = 0;
   if(n%2 != 0) return -1;
    for(int i=0; i<n; i++){
     char ch = str[i];
        if(ch=='{'){
          s.push(ch);
        }
        else if(ch=='}'){
            if(s.empty()) s.push(ch);
        else if(s.top() == '{')s.pop();
            else{
                s.push(ch);
            }
        }
    }
    int p = s.size(); 
    for(int i=0; i<p/2; i++){
        char cp = s.top(); s.pop();
        char ct = s.top(); s.pop();
        if(cp != ct) count = count+2;
       else if(cp == ct) count ++;
}
    return count;
}
int main()
{   
    system("cls");
    string s="{{{}";

   cout<<findMinimumCost(s);


    return 0;
}