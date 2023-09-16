///N stacks in an array - codestudio
#include<iostream>
#include<cstring>   //for memset()
using namespace std;

void print(stack s,int stack_no)
{  
    cout<<"Top";
    while(!s.empty(stack_no))
    {
        cout<<"-> "<<s.top(stack_no);
        s.pop(stack_no);
    }
    cout<<endl;
}

class stack{
    public:
        int *arr;
        int *top;
        int *next;  
        int size;
        int freespot;

        stack(int n,int s)
        {
            this->size = s;
            arr = new int[size];
            next = new int[size]; //it represent next free space 
            top = new int[n];   //top array to store top element of 'n' stacks
            
            //initialize top
            for(int i=0; i<n;i++)
                top[i] =-1;
            
            //or use memset () to set -1 in all top elements
            //memset(top,-1,n);

            //intitialize next
            for(int i=0; i< size; i++)
                next[i] = i+1;

            next[size] = -1;     //it represent next free space ,so for last element there's no next free space

            //intitialize freespot
            freespot = 0;

        }  

        void push(int element, int stack_no)
        {

        }
        void pop(int stack_no)
        {

        }

        bool empty(int stack_no)
        {

        }

};

int main()
{   
    system("cls");
    int n = 3;
    int s = 6;
    int q = 5;

    

    return 0;
}