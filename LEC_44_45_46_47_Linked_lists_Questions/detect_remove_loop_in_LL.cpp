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

            /*    **if LL is circular or not **
            if( traverse == head)  //and this already visisted node is head then its a circular 
                return true;
            else                //its cyclic only
                return false;
            */
        }
        mp[traverse] = 1;
        traverse = traverse->next;   
    }
   return false;
}

//APPROACH 2: DETECT LOOP(CYCLE) USING FLOYD CYCLE DETECTION
Node* floydDetect(Node* head)
{
    if(head == NULL or head->next == head)
        return head;
    else if(head->next == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while( slow !=NULL and fast !=NULL)
    {   
        slow = slow->next;  //jump by 1 step
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;  //jump by 2 step

        if(slow == fast)    //if at some point slow and fast pointing to same node(can be any) then LL has CYCLE/LOOP in it
            return slow;
    }
    return NULL;   //i.e iff LL is not cyclic then while loop will finish then return false
}

//FINDING BEGINNING NODE OF LOOP/CYCLE  (Using floyd detect function as well)
Node* find_beg_node_of_loop(Node* head)
{
    Node* intersection = floydDetect(head);
    Node* slow = head;

    if(intersection == NULL)
        return NULL;
    
    while( intersection != slow)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;    //now slow pointer is pointing to node of beginning of loop 
}

//REMOVE THE LOOP
void remove_loop(Node* head)
{   
    Node* start_ofLoop = find_beg_node_of_loop(head);
    if(start_ofLoop ==NULL)
        return ;

    Node* traverse = start_ofLoop;   //get start(beginning) node of loop

    while(traverse->next != start_ofLoop)
        traverse= traverse->next;
    
    //at the end of loop TRAVERSE have last node of cycle which is 19 
    //so we will disconnect it from stat_ofLoop and make it point to NULL, Removing Loop
    traverse->next = NULL; 
}

//FUNCTION TO DETECT WHETHER A LL IS CIRCULAR OR NOT
bool isCircular(Node* head){

    if(head == NULL or head->next == head)
        return true;
    else if(head->next == NULL)
        return false;

    if (!islooping(head)) {
      Node *traverse = head->next;
      while (traverse != head and traverse != NULL)
        traverse = traverse->next;

      if (traverse == head)
        return true;

      return false;
    }
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

    
    //MAKING A LOOP INSIDE A LL by manually linking tail to one of inbetween nodes of LL
    tail->next = head->next->next;  
    //print_LL(head); //ye fatega kuki ye loop ke andar stuck ho jayega
    
    //Finding beginning node of loop
    Node* loop_beg = find_beg_node_of_loop(head);
    if(loop_beg==NULL)
         cout<<"No cycle is detected inside Linked List"<<endl;
    else
        cout<<endl<<"Cycle is detected inside Linked List and beginning Node of LOOP is "<<loop_beg->data<<endl;

    //NOW REMOVE THE LOOP (by simply making the last node in cyle point to null)
    remove_loop(head);    

    //loop had been removed so now we can print LL normally
    cout<<"\nRemoved cycle/Loop";
    print_LL(head); 




    /* detecting loop
    if(islooping(head))
        cout<<endl<<"APPROACH 1:GIVEN Linked list Have CYCLE IN IT"<<endl;
    else
        cout<<"LL Dont have cyle/loop in it"<<endl;
    
    if(floydDetect(head))
        cout<<endl<<"APPROACH 2:GIVEN Linked list Have CYCLE IN IT"<<endl;
    else
        cout<<"LL Dont have cyle/loop in it"<<endl;
    */

   //MAKING LL CIRCULAR
   //tail->next = head;


    return 0;
}