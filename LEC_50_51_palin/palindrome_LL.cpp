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
 
bool isPalin(vector<int> vec)
{
    int n = vec.size();
    int i=0;
    while(n)
    {
        if(vec[i] != vec[n-1])
            return false;
        i++;
        n--;
    }
    return true;
}
//APPROACH 1: sotre all data of each node into and vector(array )and then perform palindrome logic on vector
bool check_palin1(Node* head)
{   
    if(head->next == NULL)
        return true;

    vector<int> vec;
    while(head != NULL)
    {
        vec.push_back(head->data);
        head = head->next;
    }
    return isPalin(vec);

}


Node* reverse_LL(Node* head)
{
     Node* prev=NULL;
     Node* current = head;
     Node* forward = NULL;

     while(current != NULL)
     {  
        forward = current->next;
        current->next = prev;

        prev = current;
        current = forward;
       
     }    
     return prev;
}
//APPROACH 2: Reverse the 2nd half of LL and then compare 1st half and 2nd half.
bool check_palin2(Node* head)
{
    if(head->next == NULL)
        return true;
    
    //Get the size of LL
    int n = getSize_LL(head)-1;
    Node* traverse = head;
    int i=0;

    //traverse till middle of LL
    while(i < n/2)
    {
        traverse = traverse->next;
        i++;
    }
    
    //reverse the 2nd half of LL and receive its head in next field of traverse
    Node* temp = traverse;
    temp->next = reverse_LL(temp->next);
    

    //now make 2 pointers one points to start of LL and one points to node next ot middle node of LL(works for both odd-even size case)
    Node* current = head;
    traverse = traverse->next;

    //till traverse(which was pointing to first node of 2nd half of LL ) reach end of LL
    while(traverse != NULL)
    {
        if(current->data != traverse->data )
            return false;
        current = current->next;
        traverse = traverse->next;
    }
    //(optional) repeating one more time so that LL will return to its original form(re-reversing 2nd half of LL)
     temp->next = reverse_LL(temp->next);

    return true;
}

int main()
{   
    system("cls");
    Node* head=NULL;
    Node* tail = NULL;

    Insert_at_tail(head,tail,1);
    Insert_at_tail(head,tail,2);
    Insert_at_tail(head,tail,3);
    Insert_at_tail(head,tail,4);
    Insert_at_tail(head,tail,3);
    Insert_at_tail(head,tail,2);            
    Insert_at_tail(head,tail,1);            
    print_LL(head);
    
    //bool res = check_palin1(head);    //here S.C is O(n)
    bool res = check_palin2(head);      //here S.C is O(1)
    if(res)
        cout<<"\nLL is palindrome";
    else
        cout<<"\nNot a palindrome";
    print_LL(head);
    

    return 0;
}