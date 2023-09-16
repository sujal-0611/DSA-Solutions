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
//APPROACH 2: better soln, no extra space  USE INSERT AT BOTTOM LOGIC
void reverse_stack2(stack<int>& s)
{   
    if(s.empty())
        return;
    
    int element = s.top();
    s.pop();

    reverse_stack2(s);

    insert_at_bottom(s,element);
    
}

void recur_func(stack<int>& s,stack<int>& dummy)
{
    if(s.empty())
    {
        return;
    }

    //delete top element from original stack
    s.pop();

    //recursive call
    recur_func(s,dummy);

    //push top element of dummy stack to original stack
    //(as recursive function backstack the original stack is empty then gradually filled with elements fro mdunmmy but in reversed order)
    s.push(dummy.top());

    //pop top element to get new top
    dummy.pop();
}
//APPROACH 1: using recursion + extra space
void reverse_stack(stack<int>& s)
{
    //create a another stack having exact same elements as of original
    stack<int> dummy(s);

    //call to recursive function
    recur_func(s,dummy);

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

    //aprroach1;: uses extra space
    //reverse_stack(s);

    //approach2: use insert at bottom logic
    reverse_stack2(s);
    print(s);


    return 0;
}