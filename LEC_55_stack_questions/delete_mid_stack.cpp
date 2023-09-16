#include<iostream>
#include<stack>
using namespace std;

void recur_func(stack<int>& st, int sizee,int count)
{
    //base cases
    if(count == (sizee/2))
    {        
        st.pop();
        return;
    }
    //store top element
    int element = st.top(); 
    //delete top element
    st.pop();   

     //recursive call with new stack(without top element)
    recur_func(st,sizee,count+1);  

    //add back the poped element
    st.push(element);       

}
void delete_mid(stack<int>& st)
{
    int sizeOfStack = st.size()-1;
    if(sizeOfStack< 1)
    {
        cout<<"stack is empty";
    }
    recur_func(st,sizeOfStack,0);
}
int main()
{   
    system("cls");
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    delete_mid(st);

    cout<<"Top";
    while(!st.empty())
    {
        cout<<"-> "<<st.top();
        st.pop();
    }
    
    return 0;
}