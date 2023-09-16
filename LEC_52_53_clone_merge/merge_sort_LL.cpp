//IF LL IS PALINDROME OR NOT
#include<iostream>
#include<vector>
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
 //Function to merge to 2 sorted linkedLists
 Node* merge_2sorted_LL(Node* &head1,Node* &head2)
 {
    if( head1 ==NULL and head2 == NULL)  return NULL;
    else if(head1 ==NULL)  return head2;
    else if(head2 == NULL) return head1;

    if(head1->data <= head2->data)
        return solve(head1,head2);
    else
        return solve(head2,head1); 
 }
//Function to find the middle node
Node* find_Mid(Node* head)
{
    Node* slow = head;
    Node* fast = head->next;
    while(fast !=NULL and fast->next !=NULL)
    {
        slow = slow->next;         //jump by 1 step
        fast = fast->next->next;   //jump by 2 step

    }
    return slow;
}
//APPROACH: using recursion to sort Linked list using Merge_sort
Node* merge_sort(Node* head)
{   
    //Base Cases
    if(head == NULL || head->next == NULL)
        return head;

    //1.get mid node 
    Node* mid_node = find_Mid(head);

    //2. split LL into 2 parts and assign head for each part
    Node* left = head;
    Node* right = mid_node->next;
    
    mid_node->next = NULL;  //breaking LL into 2 parts by delinking each parts

    //3. sort each parts **RECCURSIVE CALLS
    left = merge_sort(left);
    right = merge_sort(right);

    //4.Now Merge 2 sorted parts
    Node* Result_head = merge_2sorted_LL(left, right);
    return Result_head;
}
int main()
{   
    system("cls");
    Node* head=NULL;
    Node* tail = NULL;

    Insert_at_tail(head,tail,3);
    Insert_at_tail(head,tail,1);
    Insert_at_tail(head,tail,4);
    Insert_at_tail(head,tail,2);
    Insert_at_tail(head,tail,3);
    Insert_at_tail(head,tail,2);            
    Insert_at_tail(head,tail,1);            
    print_LL(head);
    
    head = merge_sort(head);
    cout<<endl<<"After Merge Sort"<<endl;
    print_LL(head);
    

    return 0;
}