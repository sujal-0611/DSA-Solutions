//GFG: Max Rectangle in Binary Matrix with all 1's
#include<iostream>
#include<vector>
#include<stack>
#include<climits>
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

//next smaller element indexes
vector<int> next_small(int *vec,int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);

    //int n = vec.size()-1;
    n = n-1;
    while(n>=0)
    {   
        while(s.top() !=-1 and vec[s.top()] >=vec[n])
            s.pop();
        
        //now top has element smaller than vec[n]
        //ans.push_back(s.top()); //in this case answer will be stored in reversed order
        ans[n] = s.top();   //this one store in original order
        s.push(n);
    
        n--;
    }
    return ans;
}
//previous smallers indexes
vector<int> prev_small(int *vec,int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);

    //int n = vec.size();
  
    for(int i=0; i<n; i++)
    {   
        while(s.top() !=-1 and vec[s.top()] >=vec[i])
            s.pop();
        
        //now top has element smaller than vec[n]
        //ans.push_back(s.top()); //in this case answer will be stored in reversed order
        ans[i] = s.top();   //this one store in original order
        s.push(i);

    }
    return ans;
}

int largest_area_histogram(int *heights,int n)
{
        //int n= heights.size();
        
        vector<int> next(n);
        next = next_small(heights,n);
            
        vector<int> prev(n);
        prev = prev_small(heights,n);
        
        int max_area = INT_MIN;
        for(int i=0; i<n; i++) 
        {
            int length = heights[i];
            
            if(next[i] == -1)   //for case when all heights are equal
                next[i] = n;    
            
            int breadth = next[i] - prev[i] - 1;    //next[i] have height  smaller than ith height (so to get till that we use  (next[i] -1)th height

            int area = length*breadth;      //storing current height
            max_area = max(area, max_area);     //storing max height
        }
        return max_area;

}

//MAIN: FIND LARGEST RECTANGULAR AREA IN BINARY MATRIX
int max_area_matrix(int mat[4][4],int n,int m)
{   
    int max_area = INT_MIN;
    //Step 1 find area of laregest area in row 1
    max_area = largest_area_histogram(mat[0], m);

    //step 2:(for remaining rows) take current row as base and add it to upper row
    for(int i =1; i<n;i++)  //starting with row 1 ,since we separately solved for row 0
    {
        for(int j=0;j<m;j++)
        {   
            if(mat[i][j] !=0)   //only if base row(current row) not have zero
                mat[i][j] = mat[i][j] + mat[i-1][j];    //i-1 for previous row
            else
                mat[i][j] =0;   //optional since its zero that is only why condtion has failed

        }   //entire current row has been updated

        int area = largest_area_histogram(mat[i], m);   //calclate max_area for current updated row( or current histogram)
        max_area = max(max_area,area);
    }

    return max_area;

}


int main() 
{   
    system("cls");
    //stack s;
    stack<int> s;

    int matrix[4][4] = {{0,1,1,0},
                        {1,1,1,1},
                        {1,1,1,1},
                        {0,1,1,0}};
    
    int res = max_area_matrix(matrix,4,4);
    cout<<"largest area: "<<res;
    
    return 0;
}