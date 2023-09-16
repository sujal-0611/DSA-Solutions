//check if LL is circular 
//check if LL has loop(cycle) or not
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

//APPROACH 1 : FUNCTION TO DETECT CYCLE/LOOP IN A LL USING MAP
bool islooping(Node* head)  //****ACTUALLY  this function can also serve for detecting if LL iS CIRCULAR OR NOT (line 88 to 93)
{
     if(head == NULL or head->next == head)
        return true;
    else if(head->next == NULL)
        return false;

    unordered_map<Node*,bool> mp;

    Node* traverse = head;
    while(traverse != NULL)
    {   
        if(mp[traverse] == true)     //if the node is found already visited 
        {
            return true;

            //   **if LL is circular or not **
            if( traverse == head)  //and this already visisted node is head then its a circular 
                return true;
            else                //its cyclic only
                return false;
        }
        mp[traverse] = 1;
        traverse = traverse->next;   
    }
   return false;
}

//FUNCTION TO DETECT WHETHER A LL IS CIRCULAR OR NOT
bool isCircular(Node* head){

    if(head == NULL or head->next == head)
        return true;
    else if(head->next == NULL)
        return false;

      Node *traverse = head->next;
      while (traverse != head and traverse != NULL)
        traverse = traverse->next;

    if (traverse == head)
        return true;

    return false; 
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
    Insert_at_tail(head,tail,18);
    Insert_at_tail(head,tail,19);
    print_LL(head);


   //MAKING LL CIRCULAR
   tail->next = head;

   if(isCircular(head))
        cout<<"circular";
   else
    cout<<"not circular";

   if(islooping(head))
        cout<<"\ncircular";
   else
        cout<<"not circular";



    return 0;
}