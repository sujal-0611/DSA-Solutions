#include<iostream>
using namespace std;

//Going to implement queue in "front <--- rear" direction, where "front" is head and "rear" is tail 
class queue{
    public:
        int *arr;
        int size;
        int front;
        int rear;

        queue(int size)
        {
            this->size = size;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        //PUSH: Insertion at head(or front) Def at line:
        void enqueue(int);

        //POP: Deletion at tail(or rear)  Def at line:
        int dequeue();

        //DISPLAY: head element of queue
        int head_element();

        //Isempty  Def at line:30
        bool empty();

        void print();
};

void queue::enqueue(int data)
{   
    //Overflow
    if(rear >= size-1) // if(Qsize() >=size)
        return;

    //if queue was empty
    if(empty())
    {
        front = 0;
        rear = 0;
        arr[rear] =data;
    }
    else
    {
        rear++;
        arr[rear] =data;        //i.e pushing at rear and pushing rear to next location
                                //i know its bit confusing but we are inserting at tail(rear)
    }
}

int queue::dequeue()
{
    //Underflow
    if(empty())
        return -1;

    int element = arr[front];
    arr[front] =-1;
    front++;    //pushing front toward rear , also direction is  front<---rear

    //if direction was this: rear-->front , then
    /* arr[front] =-1;
       front --;   */

    //if front and rear are at same location(i.e empty queue) somewhere in array then make then -1
    if(front == rear)   
    {
        front =-1;
        rear = -1;
    }

    return element;
}

int queue::head_element()
{
    if(empty())
        return -1;
    
    return arr[front];
}

bool queue::empty()
{   
    if(front == -1)
        return true;
    
    return false;
}

void queue::print()
{   
    cout<<endl<<"front-> ";
    for(int i=front; i<=rear; i++)
    {
        cout<<arr[i]<<"<-";
    }
    cout<<" rear";

    cout<<endl<<"or";

    cout<<endl<<"rear-> ";
    for(int i=rear; i>=front; i--)
    {
        cout<<arr[i]<<"->";
    }
    cout<<"front";

}

int main()
{   
    system("cls");
    int size;
    cout<<"Enter the size of queue ";
    cin>>size;
    queue q(size);

    cout<<"enter elements in queue"<<endl;
    for(int i=0; i<size; i++)
    {   
        int x;
        cin>>x;
        q.enqueue(x);
    }
    q.print();
    /*
   q.print();
    cout<<"\npush: 64\n";
    q.enqueue(64);  */

    int a = q.dequeue();
    cout<<"\nPoped element is: "<<a<<endl;

    q.print();
    cout<<endl<<"Top element: "<<q.head_element();
    return 0;
}