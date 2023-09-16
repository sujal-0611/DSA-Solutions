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
void Insert_at_head(Node* &head, int data)  //**by reference bcz so that we dont work on copy ,we are working at original LL
{
    Node* temp_node = new Node(data);

  
    //get address of head node and store it (link it with temp_node) in it's next
    //**incase LL is empty(i.e head is NULL) temp_node ke next mei NULL assign hoga
    temp_node->next= head; 

    //update head : by making head pointer to point to temp_node , temp_node is a new head node
    head = temp_node;
}
  
//Count approach
void Sort_a_012(Node* head)
{
    if(head == NULL or head->next == NULL)
    {
        cout<<" LL is sorted";
        return;
    }

    int zero=0,one=0,two=0;

    Node* current=head;

    //LOOP TO COUNT 0s 1s and 2s
    while(current != NULL)
    {
        if(current->data == 0)
            zero++;
        else if(current->data == 1)
            one++;
        else
            two++;

        current= current->next;
    }
    cout<<"\none: "<<one<<" two: "<<two<<" zero: "<<zero;

    current = head;

    //NOW CHANGE NODE's DATA field Accordingly
    while(current != NULL)
    {
        if(zero)
        {
            current->data = 0;
            zero--;
        }
        else if(one)
        {
            current->data = 1;
            one--;
        }
        else
        {
            current->data = 2;
            two--;
        }
        current=current->next;
    }

}

//IF changing node's data field is not allowed
Node* Sort_b_012(Node* head)
{
     if(head == NULL or head->next == NULL)
    {
        cout<<" LL is sorted";
        return head;
    }
    int zero=0,one=0,two=0;
    Node* current=head;

    //LOOP TO COUNT 0s 1s and 2s
    while(current != NULL)
    {
        if(current->data == 0)
            zero++;
        else if(current->data == 1)
            one++;
        else
            two++;

        current= current->next;
    }

    Node* head0= NULL;
    Node* head1= NULL;
    Node* head2= NULL;
    
    current = head;
    while(zero--)
        Insert_at_head(head0,0);
    while(one--)
        Insert_at_head(head1,1);
    while(two--)
        Insert_at_head(head2,2);

    //from line 174 to 185 MERGING ALL 3  LINKED LISTS TOGETHER (basically connecting each other)
    current=head0;
    while(current->next !=NULL)
        current = current->next;
    //at the end current will have address of last node of Linked list 0(of zeros)
    
    current->next = head1;
    current = head1;
     while(current->next !=NULL)
        current = current->next;
    //at the end current will have address of last node of Linked list 1(of ones)

    current->next = head2;

    return head0;
}
int main()
{   
    system("cls");
    Node* head=NULL;
    Node* tail=NULL;

    Insert_at_tail(head,tail,2);
    Insert_at_tail(head,tail,1);
    Insert_at_tail(head,tail,0);
    Insert_at_tail(head,tail,2);
    Insert_at_tail(head,tail,0);
    Insert_at_tail(head,tail,1);
    Insert_at_tail(head,tail,2);
   
    print_LL(head);
    //Sort_a_012(head); //count and change data approach
     head = Sort_b_012(head);
    print_LL(head);
   
  
    

    return 0;
}