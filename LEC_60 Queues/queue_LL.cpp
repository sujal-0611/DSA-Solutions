//QUEUE: Linked List approach

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int datas) : data(datas), next(NULL) {}
};

class queue{
    public:
        Node *front;
        Node *rear;

        queue(): front(NULL), rear(NULL) {}

        //PUSH
        void enqueue(int data);

        int dequeue();

        //TOP
        int front_element();

        //IS EMPTY
        bool empty();
};

//PUSH: Insertion at rear(tail)
void queue::enqueue(int data)
{   
    Node *temp_node = new Node(data);

    if(front == NULL)
    {
        front = temp_node;
        rear = temp_node;
    }

    rear->next = temp_node;
    rear = temp_node;
}

//POP: deletetion at head(front)
int queue::dequeue()
{   
    //underflow
    if(front == NULL)
        return -1;

    Node* temp = front;
    front =front->next;

    temp->next = NULL;

    int deleted_data = temp->data;

    delete temp;

    return deleted_data;
}

//TOP: return front element
int queue::front_element()
{
    if(front == NULL)
        return -1;

    return front->data;
}

//IS EMPTY
bool queue::empty()
{
    if(front == NULL)
        return true;
    return false;
}

int main()
{   
    system("cls");
    queue q;

    q.enqueue(2);
    q.enqueue(5);
    q.enqueue(9);
    q.enqueue(6);

    cout<<q.front_element();    
    cout<<endl;
    cout<<q.dequeue();
    cout<<endl;
    cout<<q.front_element();
    return 0;
}