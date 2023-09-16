//REVERSE THE DOUBLY LINKED LIST
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node *next;    //stores address of next node

        Node(int data)  //intializing each node with a value and having null addresss
        {
            this->data=data;
            this->prev =NULL;
            this->next = NULL; 
        }
};

//PRINT LINKED LIST
void print_LL(Node* head)   //**no reference this time since we are going to traverse only so no need to edit original LL
{
    Node* current = head;   //current is pointer to have current node and print it

    cout<<endl<<"\nLinked List as follows:\nHead<=> ";
    while( current != NULL) //traverse till our "current" pointer doesnt reach the end(i.e till it encounter NULL as address for next node)
    {
        cout<<current->data<<"<=> ";
        current = current->next;
    }
    cout<<"NULL\n";
}

//RETURNS THE SIZE OF LL
int getSize_LL(Node* head)
{
    int n=0;
    if(head == NULL)
        return 0;

    Node* current=head;
    while(current != NULL)
    {
        n++;
        current = current->next;
    }
    return n;
}

//INSERT AT END OF LL
void Insert_at_tail(Node* &head,Node* &tail,int data)
{
    Node* temp_node = new Node(data);   

    if(tail != NULL)   
    {   
        tail->next =temp_node; 
        temp_node->prev = tail;
        tail = tail->next;     
    }
    else
    {
       head =temp_node;    //bcz head was also NUll so has to be updated to first node as head
        tail=temp_node;     //since there's first node to be inserted so it will be pointed by head as well as tail
    }
}

Node* recursive_func(Node* previous, Node* current)
{
    if(current == NULL)
        return previous;

    Node* forward = current->next;

    current->next = previous;
    current->prev = forward;

    return recursive_func(current,forward);
}
//REVERSE THEDLL
Node* reverse_DLL(Node* &head,Node* &tail)
{
    Node* previous = NULL;
    Node* current = head;

    tail = head;
    return recursive_func(previous,current);
}
int main()
{   
    system("cls");
    Node* head=NULL;
    Node* tail=NULL;

    Insert_at_tail(head,tail,10);
    Insert_at_tail(head,tail,12);
    Insert_at_tail(head,tail,15);
    Insert_at_tail(head,tail,16);
    Insert_at_tail(head,tail,17);
    Insert_at_tail(head,tail,18);
    Insert_at_tail(head,tail,19);

    cout<<"Doubly";
    print_LL(head);

    head = reverse_DLL(head,tail);
    cout<<"Doubly";
    print_LL(head);
    return 0;
}