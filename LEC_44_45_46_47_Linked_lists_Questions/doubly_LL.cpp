#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

//PRINT DOUBLY LL
void print_LL(Node* &head)
{
    Node* traverse=head;

    cout<<"Head <=> ";
    while( traverse != NULL)
    {
        cout<<traverse->data<<" <=> ";
        traverse=traverse->next;
    }
    cout<<"NULL";
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

//since we have doubly LL we cant enter on both sides of head using head ptr only
void Insert_at_head(Node* &head, int data)
{
    Node* temp_node =new Node(data);

    temp_node->next=head;   //since temp_node is first field we will keep prev field of temp_node as NULL
    if(head != NULL)
        head->prev = temp_node; //updating prev field of head
    head = temp_node;    //now update head 
}

//its basically a "INSERTION AT TAIL" but since its doubly LL we can do it by head ptr only
void Insert_at_tail(Node* &head,int data)   //implementing without tail pointer
{
    Node* temp_node =new Node(data);

    if(head != NULL)    //if LL have atleast one node
    {
        Node* traverse = head;
        while(traverse->next != NULL)   //for last node: last_node->next would be NULL, so traverse would have last node( not null)
            traverse=traverse->next;    //getting to last nodee

        traverse->next = temp_node;
        temp_node ->prev= traverse;
    }
    else    //if LL is empty and head point to null
        head=temp_node;
}

//INSERTION AT MIDDLE
void Insert_at_Any(Node* &head,int data,int position)
{
    if(position == 1)
    {
        cout<<endl<<"Insert at head case:"<<endl;
        Insert_at_head(head,data);
        return;
    }
    if(position == getSize_LL(head)+1)
    {
        cout<<endl<<"Insert at tail case:"<<endl;
        Insert_at_tail(head,data);
        return;
    }

    //for in between case
    cout<<endl<<"Insert at middle case:"<<endl;
    Node* temp_node = new Node(data);

    //to get the node just before the position where we want to enter (previous node to position node)
    Node* previous =head;   //(in singly we named it "current_pos" ....both are same)

    for(int i=2; i<position; i++)
        previous = previous->next;

    Node*current =previous->next;   //the node that is current at "position" and now going to be displaced(not literally)
    
    //Linking previous node and temp_node
    previous->next=temp_node;
    temp_node->prev= previous;

    //Linking temp_node and current node and 
    temp_node->next =current;
    current->prev = temp_node;

}

//DELETION OF A NODE
void delete_node(Node* &head,int position)
{
    if(head == NULL)
    {
        cout<<"LL is empty, exiting....";
        return;
    }

    //Handling deletion at Head case 
    if(position == 1)    //Head case
    {
        Node* temp=head;
        
        head= head->next;   //update head to next node

        //delinking  **if there was more than one nodes in the doubly LL
        if(head != NULL)    
            head->prev =NULL;   //prev field of new head to null 
        //else as there's only one node in LL then this condition will be false and there's no prev field in NULL so do nothing for else case

        //delinking
        temp->next=NULL; 

        delete temp;
        return;
    }

    //REST cases : Deletion in middle or tail 
    Node* previous=head;    
    for(int i=2; i<position;i++)    //to get to the previous node (which is the node previous to the node we gonna delete)
        previous = previous->next;

    Node* current =previous->next; //getting the node we actually want to delete

    //updating previous node's next field with current node's next field(which contain address of node right after current node)
    previous->next = current->next;   //i.e linking previous node to "node after current node"

    if(current->next != NULL)   //i.e there's a node after current node
        current->next->prev = previous;     //current->next->prev is node after current node

    //*****or shorter way   
    //previous->next_node = previous->next_node->next_node;  
    //if(current->next == NULL)     //TAIL IS NOT MAINTAINED BY ME HERE SO COMMENTING THIS ONE 
        //tail =previous;

    current->next=NULL;
    current->prev=NULL;
    delete current;     
}


int main()
{   
    system("cls");
    
    Node* head=NULL;
    int data;
    int n;
    int position;

    cout<<"Enter the number of elements you want to enter in the doubly linked list: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter the element you want to enter in the doubly linked list: ";
        cin>>data;
        //Insert_at_head(head,data);
        Insert_at_tail(head,data);
    }
    cout<<"\n\nThe doubly linked list is: ";
    print_LL(head);

    cout<<endl<<"Enter the data to be inserted at middle of LL: ";
    cin>>data;

    cout<<endl<<"Enter the Postion at which you want to enter this data(should be  less than equal to (size of LL +  1) ): ";
    cin>>position;

    Insert_at_Any(head,data,position);
    cout<<"\nThe doubly linked list is: ";
    print_LL(head);

    
    cout<<endl<<"enter the position of node to be deleted: ";
    cin>>position;

    delete_node(head,position);
    print_LL(head);
    return 0;
}