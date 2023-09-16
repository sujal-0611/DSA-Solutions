#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
class Node{
    public:
        int data;
        Node* next;
        Node(int d) : data(d),next(NULL) {}
};

class stack{
    public:
        Node* top;
        stack() : top(NULL) {}

        void push(int d) 
        {
            Node* new_node = new Node(d);
            new_node->next = top;
            top = new_node;
        }
        
        int pop() 
        {
            if(top == NULL)
            {
                cout << "Stack Underflow" << endl;
                return -1;
            }
            int d = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return d;
        }
        
        int peek() 
        {
            if(top == NULL) 
            {
                cout << "Stack Underflow" << endl;
                return -1;
            }
            return top->data;
        }
        
        bool isEmpty() 
        {
            if(top == NULL) 
                return true;
                
            return false;
        }
        
        int size() 
        {
            int s = 0;
            Node* temp = top;
            while(temp != NULL) 
            {
                s++;
                temp = temp->next;
            }
            return s;
        }
};
*/

//Brute force (Not working)
int check_celeb_exist1(vector<vector<int>> vec )
{
    bool ans = true;
    int celeb=-1;
    int n = vec.size();
    int m= vec[0].size();

    for(int i=0; i<n; i++ )
    {
        //for row 
        for(int j = 0; j< m; j++ )
        {
            if( vec[i][j] !=0)
            {
                ans =false;
                break;
            }
        }
          if( ans == true)
          {
                celeb = i;
                //for column
                for (int k = 0; k < m; k++)
                {
                    if( vec[k][i] == 0 and i != k)  //i!=k is a diagonal case
                    {
                        ans = false;
                        break;
                    }
                }
                if( ans == true)
                {
                    celeb = i;
                    return true;
                }
          }
    }
    
    return celeb;
}

//USING STACK
int check_celeb_exist2(vector<vector<int>> vec )
{   
    stack<int> s;
    int n = vec.size();
    int i =0;

    //STEP 1
    //push all people
    while(i<n)
    {
        s.push(i);
        i++;
    }
    
    //STEP 2
    //this loop find potential celebrity
    while( s.size() !=1)
    {
        int a = s.top();    s.pop();
        int b = s.top();    s.pop();

        if( vec[a][b] == 1)     //if 'a' 'b' ko janta h
        {
            s.push(b);
        }
        else if(vec[b][a] == 1) //if 'b' 'a' ko janta h
        {
            s.push(a);
        }
        if(s.empty())   //for case when there's no celebrity(so stack might get empty so retturn -1)
            return -1;
    }   //at end only one person is left in stack and that  person is a "potential celebrity"
    
    //STEP 3
    //check if that "potential celebrity" is really a celebrity, celebrity knows no one and every one knows celebrity
    //for row : celebrity knows no one
    int celeb = s.top();
    int pos =1;
    for(int i =0; i < n; i++)
    {
        if( vec[celeb][i] !=0)
        {    pos =0;
            break;
        }
    }

    if(pos !=0)
    {
        //for column: everyone knows celebrity
        for(int i =0; i<n;i++)
        {
            if(vec[i][celeb] != 1 and i != celeb) // i!=celeb is diagonal case ,which is exception
            {
                pos = 0;
                break;
            }
        }
    }
    else
        return -1;


    if(pos == 1)
        return celeb;
    else    
        return -1;

}

int main() 
{   
    system("cls");
    //stack s;
    stack<int> s;

    vector<vector<int>> vec = { {0,1,0},
                                {0,0,0},
                                {0,1,0} };
    
    int res;  
    //res = check_celeb_exist1(vec); //brute force
    res = check_celeb_exist2(vec); //using stack    O(n) 

    cout<<res;
    
    return 0;
}