/*Stack implementation
   ->1. by array
 */
#include<iostream>
using namespace std;

class Stack{
  private:
    int* arr;
    int size;
    int Top;

  public:
    
    
    Stack(int size)
    {
      this->size = size;
      arr = new int[size];
      Top = -1;

    }
    //check if stack is empty or not
    bool isEmpty();
    //insertion
    void push(int);
    //Deletion
    void pop();
    //top
    int top();
};

bool Stack::isEmpty()
{
    if(Top == -1)
      return true;

    return false;  
}

void Stack::push(int x)
{
  if(Top >= size)
  {
    cout<<"Stack Overflow..";
      return;
  }
  Top++;
  arr[Top] = x;
}

void Stack::pop()
{
    if(isEmpty())
    {
      cout<<"Stack is Already Empty";
      return;
    }
    arr[Top] = 0;
    Top--;
}

int Stack::top()
{
    if(isEmpty())
    {
      cout<<"Stack is Empty ";
      return -1;
    }
    
    return arr[Top];
}

//FUNCTION TO PRINT ALL ELEMENTS OF STACK
void print(Stack &s)
{ 
   cout<<"Top";
   while(!s.isEmpty())
   {
      cout<<"-> "<<s.top();
      s.pop();
   }
}
int main()
{   
    system("cls");
    int n;
    cout<<"Enter the size of Stack: ";
    cin>>n;
    Stack s(n);

    cout<<"\nEnter elements into the stack"<<endl;
    int data;
    for(int i =0; i < n; i++)
    {
        cin>>data;
        s.push(data);
    }

    cout<<"Top of the Stack: "<<s.top();
    s.pop();
    cout<<"\nTop of the Stack: "<<s.top();

    cout<<"\n All the stack elements: ";
    print(s);

    
    return 0;
}