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

//INSERT AT BEGINING OF LL
void Insert_at_head(Node* &head,Node* &tail, int data)  //**by reference bcz so that we dont work on copy ,we are working at original LL
{
    Node* temp_node = new Node(data);

  
    //get address of head node and store it (link it with temp_node) in it's next
    //**incase LL is empty(i.e head is NULL) temp_node ke next mei NULL assign hoga
    temp_node->next= head; 
    if(head == NULL)
        tail = temp_node;
    //update head : by making head pointer to point to temp_node , temp_node is a new head node
    head = temp_node;
}
  
//APPROACH 1: Merge 2 sorted LLs (using merge 2 sorterd array logic) NOT WORKING PROPERLY
Node* merge_2LL_1(Node* head1,Node* head2,Node* &tail)
{
    if( head1 ==NULL and head2 == NULL)  return NULL;
    else if(head1 ==NULL)  return head2;
    else if(head2 == NULL) return head1;

    Node* traverse1 = head1;
    Node* traverse2 = head2;
     
    Node* head3 = NULL;
    Node* tail3 = NULL;
    while(traverse1 != NULL and traverse2 != NULL)
    {
        if(traverse1->data <= traverse2->data)
        {
            Insert_at_tail(head3,tail3,traverse1->data);
            traverse1 = traverse1->next;
        }
        else
        {
            Insert_at_tail(head3,tail3,traverse2->data);
            traverse2 = traverse2->next;
        }
    }
    if(traverse1 != NULL)
        Insert_at_tail(head3,tail3,traverse1->data);
    if(traverse2 != NULL)
        Insert_at_tail(head3,tail3, traverse2->data);

    tail = tail3;
    return head3;
    
}

//we are solving with logic data of first node in head1 is smaller than data of first node of head2
Node* solve(Node* head1, Node* head2)
{   
    //case: if there's only one node in first LL
    if(head1->next == NULL)
    {
        head1->next = head2;
        return head1;
    }
    Node* current1 = head1;
    Node* next1 = head1->next;
    Node* current2 = head2;
    Node* next2 = current2->next; //to keep track of LL2

    while( next1 !=NULL and current2 !=NULL)
    {
        if(( current1->data <= current2->data) and (current2->data <= next1->data) )
        {
            //1.Node addition
            current1->next = current2; 
            next2 = current2->next;    //getting address of node after traverse 2 in LL2
            current2->next = next1;

            //2.After inserting node update both currents(1 and 2) to next nodes
            current1 = current1->next;  
            //next1 = next1->next;  //**we do not update next because , if we update next1 as well then current1 and next1 will have a gap (as we inserted a new node(current2) in between)
            current2 = next2;   //to next node of LL2
        }
        else
        {    
            //go 1 step ahead in first LL
             current1 = current1->next;  
             next1 = next1->next;

            if(next1 == NULL) //i.e LL1 was smaller than LL2 hence LL1 reached end and and thre are some nodes of LL2 still remain to be entered then,
            {
                current1->next = current2;
                return head1;
            }
        }
    }
    return head1;
    
}
//APPROACH 2
Node* merge_2LL_2(Node* head1, Node* head2)
{
    if( head1 ==NULL and head2 == NULL)  return NULL;
    else if(head1 ==NULL)  return head2;
    else if(head2 == NULL) return head1;

    if(head1->data <= head2->data)
        return solve(head1,head2);
    else
        return solve(head2,head1); 
}
int main()
{   
    system("cls");
    Node* head=NULL;
    Node* tail = NULL;

    Node* head1=NULL;
    Node* tail1=NULL;

    Node* head2=NULL;
    Node* tail2=NULL;

    Insert_at_tail(head1,tail1,7);
    Insert_at_tail(head1,tail1,8);
   

    Insert_at_tail(head2,tail2,1);
    Insert_at_tail(head2,tail2,3);
    Insert_at_tail(head2,tail2,4);            
    Insert_at_tail(head2,tail2,6);            
   
    print_LL(head1);
    print_LL(head2);
    
   //head = merge_2LL_1(head1,head2,tail);        //using array logic (merge 2 sorted arrays)
   head = merge_2LL_2(head1,head2);
   print_LL(head);
  
    

    return 0;
}