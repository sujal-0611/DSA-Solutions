//remove duplicates from sorted ll
#include<iostream>
#include<unordered_map>
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

    cout<<endl<<"Linked List as follows:\nHead-> ";
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


void remove_duplicates(Node* &head)
{
    if(head == NULL or head->next == NULL)
    {
        cout<<"LL is empty or have one element only";
        return;
    }

    Node* current = head;
    while(current->next != NULL)
    {
        if(current->data == current->next->data)    //if 2 consecutive nodes have same data then delete latter node
        {   
            //deletion code
            Node* temp = current->next; 
            current->next = current->next->next;
            temp->next = NULL;
            delete temp;
        }
        else    //else normal traversal
            current = current->next;
    }
}
int main()
{   
    system("cls");
    Node* head=NULL;
    Node* tail=NULL;

    Insert_at_tail(head,tail,1);
    Insert_at_tail(head,tail,2);
    Insert_at_tail(head,tail,2);
    Insert_at_tail(head,tail,3);
    Insert_at_tail(head,tail,3);
    Insert_at_tail(head,tail,4);
    Insert_at_tail(head,tail,5);
    Insert_at_tail(head,tail,5);
    Insert_at_tail(head,tail,5);
    Insert_at_tail(head,tail,5);
    Insert_at_tail(head,tail,6);
    print_LL(head);
   
    remove_duplicates(head);    //didnt handled tail
    print_LL(head);
    
    

    return 0;
}