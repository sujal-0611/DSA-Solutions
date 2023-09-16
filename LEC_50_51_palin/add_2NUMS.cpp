//IF LL IS PALINDROME OR NOT
#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
        int data;
        Node *next;    //stores address of next node
        Node(): data(0), next(NULL){}
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

/* APPROACH 1 from line 81 to 163
//Custom function to recursively reverse the LL
Node* LL_recur( Node* prev,Node* current)
{   
    //BASE CASE
    if(current == NULL) return prev;    //prev is the last node in LL(of original LL) and first node of reversed LL in the end
    
    Node* forward = current->next;    //before disconnecting next node with current node store its address
    current ->next = prev;
    return LL_recur(current,forward);  //i.e sending address of 'current' in 'prev' and 'forward' in 'current' 

}
//REVERSE THE LINKED LIST IN RECURSIVE WAY
Node* reverse_LL(Node* &head)
{   
     if(head == NULL or head->next == NULL)
    {
        cout<<"Linked List is empty or there's only one element  exiting";
        return head;
    }
    //tail=head;  //first making tail to point at head (as after reversed the node pointed by head will be last)
    return LL_recur(NULL, head);

}

//function to add 2 LLs
Node* add(Node* head1, Node* head2)
{
    Node* ans_head = NULL;
    Node* ans_tail = NULL;
    int carry=0;
    int sum=0;;
    Node* current1 =head1;
    Node* current2 =head2;

    while(current1 != NULL || current2 != NULL )
    {
        int vahead1=0;
        if(current1  !=NULL)
        {
            vahead1 = current1->data;
            current1 = current1->next;
        }

        int vahead2=0;
        if(current2 !=NULL)
        {
            vahead2 = current2->data;
            current2 = current2->next;
        }
         sum = vahead1 + vahead2 +carry;        
        int digit = sum%10;
        Insert_at_tail(ans_head,ans_tail,digit);
        carry = sum/10;
    }
     while(carry != 0) 
		 {
			int sum = carry;
            int digit = sum%10;
            Insert_at_tail(ans_head,ans_tail,sum);
			carry = sum/10;		
        }
    return ans_head;
}
//CODE TO ADD 2 LLs and RETURNING A 3rd LL containing the ANSWER
Node* add_2_LL(Node* head1,Node* head2)
{
    if(head1 == NULL)  return head2;
    if(head2 == NULL)  return head1;

    //step 1. Reverse both Linked lists
    head1 = reverse_LL(head1);
    head2 = reverse_LL(head2);
    
    //STEP 2. add both LLS
    Node* ans_head = add(head1,head2);

    //Step 3. reverse the 3rd LL (ans)
    ans_head = reverse_LL(ans_head);

    //return ans as answer LL
    return ans_head;
}
*/

//APPROACH 2
Node* add_2_LL(Node* head1,Node* head2)
{
    Node* dummy = new Node();
    Node* temp = dummy ;
    int carry = 0;
    while(head1!= NULL || head2!= NULL || carry){
        int sum = 0;
		
         if(head1 != NULL){
              sum = sum + head1->data;
             head1 = head1->next;
         }
		 
        if(head2 != NULL){
             sum = sum + head2->data;
             head2 = head2->next;
         }
		 
        sum = sum + carry;
        carry = sum/10;
        Node*node = new Node(sum%10);
		
        temp->next= node;
        temp= temp->next;
    }
    return dummy->next;
}
int main()
{   
    system("cls");
    system("cls");
    Node* head=NULL;
    Node* tail = NULL;

    Node* head1=NULL;
    Node* taihead1=NULL;

    Node* head2=NULL;
    Node* taihead2=NULL;

    Insert_at_tail(head1,taihead1,2);
    Insert_at_tail(head1,taihead1,4);
    Insert_at_tail(head1,taihead1,9);
    //Insert_at_tail(head1,taihead1,3);
    //Insert_at_tail(head1,taihead1,2);
   

    Insert_at_tail(head2,taihead2,5);
    Insert_at_tail(head2,taihead2,6);
    Insert_at_tail(head2,taihead2,4);            
    Insert_at_tail(head2,taihead2,9);            
   // Insert_at_tail(head2,taihead2,0);            
   
    print_LL(head1);
    print_LL(head2);
   
   head = add_2_LL(head1,head2);
   print_LL(head);
   
    

    return 0;
}