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

Node* recursive_func(Node* head, int k) {
    //base call
    if(head == NULL)
        return NULL;
    
    //step1: reverse first k nodes  //solving(reversing) first group (i.e zero to k)
    Node* previous = NULL;
    Node* curr = head;
    Node* forward = NULL;
   
    
    int count= 0;
    
    while( curr != NULL && count < k ) 
    {
        forward = curr -> next;
        curr -> next = previous;
        previous = curr;
        curr = forward;
        count++;
    }
    
    //step2: Recursion dekhlega aage ka 
    if(forward != NULL) 
        head -> next = recursive_func(forward,k);
    
    //step3: return head of reversed list
    return previous;
}
void reverse_kgroups(Node* &head,int k)
{
    head = recursive_func(head,k);  //call to recursive function

    /* waste code didnt work
    int n = getSize_LL(head);
    int groups = n/k;

    Node* traverse = head;
    Node* head2=head;

    Node* previous =NULL;
    Node* current = head2;
    Node* forward =NULL;

    int i=0;
    
    while (i<groups)
    {   
        if(i==0)
            for(int j=1; j<k; j++)
                traverse=traverse->next;
        else    
            for(int j=0; j<=k; j++)  
                traverse=traverse->next;

        //current = head2;
        forward = NULL;
        Node* end= traverse->next;

        while(current != end)
        {
            forward = current->next;
            current->next = previous;
            previous = current;
            current = forward;
        }    
        head2 ->next = current;
        
        if(i==0)
            head = previous; 
        
        cout<<head2->data<<" "<<previous->data<<" "<<current->data<<endl; 
       
        previous = head2;
        head2 = current;

        i++;
    } 
    */
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
    //Insert_at_tail(head,tail,17);
    //Insert_at_tail(head,tail,18);
    //Insert_at_tail(head,tail,19);

    print_LL(head);

    reverse_kgroups(head,2);
    print_LL(head);

    return 0;
}