#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;    //stores address of next node

        Node(int data)  //intializing each node with a value and having null addresss
        {
            this->data=data;
            this->next = NULL; 
        }
};

//PRINT LINKED LIST
void print_LL(Node* head)   //**no reference this time since we are going to traverse only so no need to edit original LL
{
    Node* current = head;   //current is pointer to have current node and print it

    cout<<endl<<"\nLinked List as follows:\nHead-> ";
    while( current != NULL) //traverse till our "current" pointer doesnt reach the end(i.e till it encounter NULL as address for next node)
    {
        cout<<current->data<<"-> ";
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

    if(tail != NULL)    //if LL is not empty(i.e atleast one node exist)
    {   
         //update tail node's next (which previously had NULL) to point to new temp_node we created (i.e linking)
        tail->next =temp_node; 

        //now update tail , as new temp_node we inserted at end is our new tail
        tail = tail->next;

        //we dont need to do anything with temp_node's 'next' as  temp_node is tail node and tail node's next always have NULL 
        //and temp_node's next already been initialized with NULL DURING temp_node's creation 
        
    }
    else
    {
       head =temp_node;    //bcz head was also NUll so has to be updated to first node as head
        tail=temp_node;     //since there's first node to be inserted so it will be pointed by head as well as tail
    }
}

//REVERSE THE LINKED LIST IN ITERATIVE WAY
void reverse_LL_iterative(Node* &head,Node* &tail)
{
    if(head == NULL)
    {
        cout<<"Linked List is empty exiting";
        return;
    }
    else if(head->next == NULL)
    {
        cout<<"There's only one element in LL";
        return;
    }
    
    tail=head;  //making tail to point at first node

    //logic: instead of reversing the LL in array way ,WE CHANGE THE ADDRRESS OF NEXT field OF every NODE 
    //MAKE EVERY NODE's NEXT TO POINT TO PREVIOUS NODE AND UPDATE HEAD POINTER TO POINT AT LAST ELEMENT

    Node* prev=NULL;        
    Node* current = head;   
    Node* forward = NULL;    
     //forward to keep pointing a node after current , as we update next field of current, we would lost rest of node, so to keep track of it
     //we created forward node

     //code to reverse the LL
    while( current != NULL)
    {   
        forward = current->next;    //first make forward to point node after current node
        current->next = prev;   //then make next of "current" to point to its previous node(linking to previous node)
        prev = current;         //then make "prev" to point to "current, i.e make current" node as new 'prev'

        current = forward;      //now update current, make 'current' to point to forward(node after current) node 
    } 

    head = prev;    //as condition of loop is to end when 'current' reach NULL then 'prev' would be at last node so using it update 'head'
}

//Custom function to recursively reverse the LL
Node* LL_recur( Node* prev,Node* current)
{   
    //BASE CASE
    if(current == NULL)
        return prev;    //prev is the last node in LL(of original LL) and first node of reversed LL in the end
    

    Node* forward = current->next;    //before disconnecting next node with current node store its address
    current ->next = prev;
    return LL_recur(current,forward);  //i.e sending address of 'current' in 'prev' and 'forward' in 'current' 

    /* long form
    prev = current;
    current = forward;
    return LL_recur(prev, current);  */
}
//REVERSE THE LINKED LIST IN RECURSIVE WAY
void reverse_LL_recursive(Node* &head,Node* &tail)
{   
     if(head == NULL or head->next == NULL)
    {
        cout<<"Linked List is empty or there's only one element  exiting";
        return;
    }
    tail=head;  //first making tail to point at head (as after reversed the node pointed by head will be last)
    head = LL_recur(NULL, head);

    /*
    Node* prev=NULL;
    Node* current = head;
    tail=head;
    head =LL_recur(NULL, current); */  
    
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

    print_LL(head);
    cout<<endl<<"head: "<<head->data;
    cout<<endl<<"tail: "<<tail->data<<endl;

    reverse_LL_iterative(head,tail);
    cout<<"\nReversed (Iteratively)";
    print_LL(head);
    
    cout<<endl<<"head: "<<head->data;
    cout<<endl<<"tail: "<<tail->data<<endl;

    reverse_LL_recursive(head,tail);
    cout<<"\nReversed (recusively)";
    print_LL(head);

    cout<<endl<<"head: "<<head->data;
    cout<<endl<<"tail: "<<tail->data<<endl;
    return 0;
}