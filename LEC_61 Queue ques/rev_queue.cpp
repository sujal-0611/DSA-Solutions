//REVERSED THE QUEUE
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//print queue
void print(queue<int> q)
{
    int n = q.size();
    cout<<"\nfront<- ";
    for(int i=0; i<n; i++)
    {
        cout<<q.front()<<"<- ";
        q.pop();
    }
    cout<<"rear\n";
}

//approach 1: using extra space ; S.C= O(2n)
queue<int> rev_queue1(queue<int> q)
{
    if(q.empty() || (q.size()==1))
        return q;
        
    queue<int> qp;
    
    stack<int> s;
    int sizee=q.size(); //getting queue size
    
    //push all elements into stack
    for(int i=0; i< sizee;i++)
    {
        s.push(q.front());
        q.pop();
    }
    sizee = s.size();   //getting stack size
    
    //now access all the elements
    for(int i=0; i<sizee; i++)
    {
        qp.push(s.top());
        s.pop();
    }

    return qp;
}

void recur_func(queue<int> &q)
{
    //base case
    if(q.empty())
        return ;

    
    int front_element = q.front();  //get current front element 
    q.pop();                        //and pop it
     recur_func(q);                  //recursive call

     q.push(front_element);         //after all calls are made start pushing back all the elements back to queue
                                    //(it will happen so that element pushed in queue would be in reverse of original queue)
}
//approach 2: Without using extra space, S.C = O(1)
queue<int> rev_queue2(queue<int> q)
{   
    if(q.empty() || (q.size()==1))
        return q;

    recur_func(q);
    
    return q;
}
int main()
{   
    system("cls");
    queue<int> q;

    q.push(4);
    q.push(7);
    q.push(2);
    q.push(8);
    q.push(9);

    cout<<"original queue";
    print(q);

    //q=rev_queue1(q);
    q=rev_queue2(q);

    cout<<"Reversed queue";
    print(q);

   
    
    return 0;
}