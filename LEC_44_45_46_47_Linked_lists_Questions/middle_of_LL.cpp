///codestudio/ leetcode :FIND MIDDLE OF LL 
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

//FIRST APPROACH TRAVERSE TILL MID by first finding size
Node *findMiddle1(Node *head) {
    
    if(head == NULL)
        return NULL;
    else if(head->next == NULL)
        return head;

    Node* traverseMid = head;

    int n = getSize_LL(head);

    //vese no need of it as without it code is running the same so its optional
    if(n&1 !=1)  //if size is even (as question asked for second middle)
        n++;

    for( int i= 1;i<=n/2; i++)  // or i=0 but i< n/2
        traverseMid = traverseMid->next;

    return traverseMid;
}

//SECOND APPROACH TRAVESE TILL END using fast pointer while slow pointer will reach till mid only
Node *findMiddle2(Node *head) {
    
    if(head == NULL or head->next == NULL)
        return head;

    Node* fast=head->next;
    Node* slow=head;

    while(fast !=NULL)
    {
        fast = fast->next;  //moving 1 step
        if(fast != NULL)
            fast= fast->next;   //moving 2nd step (only if fast is not at NULL)

        //meanwhile slow will move 1 step only
        slow = slow->next;
    }
    return slow;
}

int main()
{   
    system("cls");
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
    Insert_at_tail(head,tail,29);

    Node* mid = findMiddle1(head);
    cout<<"MIDDLE OF LL IS(using first approach)  :"<<mid->data;

    mid = findMiddle2(head);
    cout<<endl<<"MIDDLE OF LL IS(using second approach) :"<<mid->data;


    
    return 0;
}