//GENERIC CODE: STACK AS LINKED LISTS
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
            {
                cout<<"Stack is empty";
                return;
            }
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

    stack<string> s;
    s.push("abc");
    s.push("bsf");
    s.push("gsg");
    s.push("wrgr");
    s.push("grg");

   // cout<<s.peek();

    s.print();
    
    return 0;
}