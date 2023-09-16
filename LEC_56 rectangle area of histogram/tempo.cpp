//reverse stack using recursion
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


int main()
{   
    system("cls");
     stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    
    print(s);

  


    return 0;
}