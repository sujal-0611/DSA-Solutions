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

//function to insert a single data in stack in sorted manner(i.e in its position)
void Insert_sorted_manner(stack<int>& s, int data)
{
    //base cases
    if(s.empty() or s.top() < data)
    {
        s.push(data);
        return;
    }

    int element = s.top();
    s.pop();
    
    Insert_sorted_manner(s,data);

    //after insertion of data in sorted manner , add back rest of elements of stacks
    s.push(element);
}
//MAIN FUNCTION to "SORT THE STACK"

void sort_Stack(stack<int>& s)
{
    if(s.empty())
        return;
    
    int element = s.top();
    s.pop();

    //recursive call , let recursion sort rest of stack
    sort_Stack(s);

    //now insert in sorted manner(call to another recursive function)
    Insert_sorted_manner(s,element);
}

int main()
{   
    system("cls");
     stack<int> s;

    s.push(11);
    s.push(26);
    s.push(63);
    s.push(42);
    s.push(56);
    s.push(16);
    
    print(s);

    sort_Stack(s);

    print(s);


    return 0;
}