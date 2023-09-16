#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//brute force , altho T.C is still O(n) and S.C = (n)
queue<int> rev_k1(queue<int> q,int k)
{
    queue<int> qp;
    stack<int> s;

    for(int i=0;i<k; i++)
    {
        s.push(q.front());
        q.pop();
    }

    for(int i=k-1;i>=0;i--)
    {
        qp.push(s.top());
        s.pop();
    }
    

    int n = q.size();
    for(int i=0; i<n;i++)
    {    
        qp.push(q.front());
        q.pop();
    }

     n = qp.size();
    for(int i=0; i<n;i++)
    {
        cout<<qp.front()<<" ";
        qp.pop();
    }
    
    return qp;
}

//better soln in s.c- O(k)
queue<int> rev_k2(queue<int> q,int k)
{
    stack<int> s;
    int sizee = q.size();

    //push first k eleent in stack 
    for(int i=0;i<k; i++)
    {
        s.push(q.front());
        q.pop();
    }

    int n=s.size();
    //push stack elements back to queue
    for(int i=0; i<n ;i++)
    {
        q.push(s.top());
        s.pop();
    }

    //now front se nikalo and piche daalo
    for(int i=0; i<sizee-k; i++ )
    {
        q.push(q.front());  //aage wale element ko piche daalo
        q.pop();    //then aage wale ko delete kr do
    }

    return q;

}
int main()
{   
    system("cls");
    
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k=3;
    queue<int> qp;
   // qp = rev_k1(q,k);
    qp = rev_k2(q,k);
    
    int n = qp.size();
    for(int i=0; i<n;i++)
    {
        cout<<qp.front()<<" ";
        qp.pop();
    }
    return 0;

}