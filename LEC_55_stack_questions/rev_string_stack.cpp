//Reverse a string using stack
#include<iostream>
using namespace std;

template <typename T>
class Node{ 
    public:
        T data;
        Node<T>* next;       
    
        Node(T datas): data(datas), next(NULL){}      
};

template <typename T>
class stack{
    public:
        Node<T>* top;
    
        stack() : top(NULL){}

        //if Stack is Empty
        bool isEmpty()
        {
            if(top == NULL)
                return true;
            return false;
        }

        //Insertion into Stack
        void push(T data)
        {
            Node<T>* newNode = new Node<T>(data);
            if(top == NULL)
                top = newNode;
            else
            {
                newNode->next = top;
                top = newNode;
            }
        }

        //deletion of Top element of stack
        void pop()
        {
            Node<T>* temp = top;
            top = top->next;
            temp->next = NULL;

            delete temp;
        }

        //getting top element of stack
        T peek()
        {
            if(isEmpty())
            {
                cout<<"stack is empty";
                exit(0);
            }
            else
            {
                T ans = top->data;
                return ans;
            }
        }
        
        //Print all
        void print()
        {
            if(isEmpty())
                return;
            
            cout<<"Top";
            while(!isEmpty())
            {
                cout<<"-> "<<peek();
                pop();
            }
        }
};


int main()
{   
    system("cls");

    stack<char> s;
    string str = "sujal sharma";
    int n = str.length();
    int i =0;

    while(i<n)
    {
        s.push(str[i]);
        i++;
    }
    cout<<"Original: "<<str;
    string ans;
    while(!s.isEmpty())
    {
        ans.push_back(s.peek());
        s.pop();
    }

    cout<<endl<<"reversed: "<<ans;

   // cout<<s.peek();

    s.print();
    
    return 0;
}