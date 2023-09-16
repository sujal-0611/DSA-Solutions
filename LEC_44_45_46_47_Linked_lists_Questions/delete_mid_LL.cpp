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

    cout<<endl<<"Linked List as follows:\nHead-> ";
    while( current != NULL) //traverse till our "current" pointer doesnt reach the end(i.e till it encounter NULL as address for next node)
    {
        cout<<current->data<<"-> ";
        current = current->next;
    }
    cout<<"NULL";
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

//INSERT AT BEGINING OF LL
void Insert_at_head(Node* &head,Node* &tail, int data){
    Node* temp_node = new Node(data);

    temp_node->next= head; 

    if(head == NULL)  //to make tail also point to first element inserted in empty LL
        tail=temp_node;
    

    //update head : by making head pointer to point to temp_node , temp_node is a new head node
    head = temp_node;

}
  


//INSERT AT END OF LL
void Insert_at_tail(Node* &head,Node* &tail,int data)
{
    Node* temp_node = new Node(data);   

    if(tail != NULL)    //if LL is not empty(i.e atleast one node exist)
    {   
        tail->next =temp_node; 

        tail = tail->next;

        
    }
    else
    {
       head =temp_node;    //bcz head was also NUll so has to be updated to first node as head
        tail=temp_node;     //since there's first node to be inserted so it will be pointed by head as well as tail
    }
}

//INSERT AT MIDDLE
void Insert_at_middle(Node* &head,Node* &tail,int data, int position)
{
    if(position == 1)     
    {
        cout<<endl<<"Insetion at Head"<<endl;
        Insert_at_head(head,tail,data);
        return;
    }

    //getSize_LL() func returns size of LL and if we want to enter at last then last position would be "getSize_LL(head)+1"
    if(position == getSize_LL(head)+1) 
    {   
        cout<<endl<<"Insertion at Tail"<<endl;
        Insert_at_tail(head,tail,data);
        return;
    }

    cout<<endl<<"Insertion in middle"<<endl;
    Node* temp_node = new Node(data);
    Node* previous=head; 
    
    for(int i=2; i< position; i++)   
        previous=previous->next;

    Node* current = previous->next ;

    temp_node->next = current;
    previous ->next = temp_node;
}

//DELETE A NODE 
void delete_node(Node* &head,Node* &tail,int position)
{
    if(head == NULL)
    {
        cout<<"LL is empty, exiting....";
        return;
    }

    //Handling deletion at Head case 
    if(position == 1)    //Head case
    {
        Node* temp=head;
        head= head->next;
        
        temp->next=NULL; //optional as we gonna delete whole node so doesnt matter if we delink this node or not (**matter if we write custom destructor for delete)
        delete temp;
    }

    //REST cases : Deletion in middle or tail 
    Node* previous=head;    
    for(int i=2; i<position;i++)    //to get to the previous node (which is the node previous to the node we gonna delete)
        previous = previous->next;

    Node* current =previous->next; //getting the node we actually want to delete

    //updating previous node's next field with current node's next field(which contain address of node right after current node)
    previous->next = current->next;   //i.e linking previous node to "node after current node"
    
    //*****or shorter way   previous->next is nothing but "current node" ,here instead of storing it into "current" we are directly accessing it
    //previous->next = previous->next->next;  
    if(current->next == NULL)
        tail =previous;

    current->next=NULL;
    delete current;     
}

//delete_mid_node
Node* delete_mid(Node* head)
{
    if(head == NULL)
            return head;
        else if(head->next == NULL)
        {
            Node* temp = head;
            head=NULL;
            delete temp;
            return head;
        }

        Node* prev=NULL;
        Node* slow = head;
        Node* fast = head->next;

        while(fast !=NULL)
        {   
            prev=slow;
            slow = slow->next;
            fast = fast->next;

            if(fast !=NULL)
                fast = fast->next;
        }
        cout<<endl<<slow->data<<" is deleted"<<endl;
        prev->next = slow->next;
        slow->next = NULL;
        delete slow;

        return head;
}
int main()
{   
    system("cls");

    Node* head=NULL;
    Node* tail=NULL;
    int n;
    int data;
     int position=0;

    cout<<"Enter the number of elements you want to enter in Linked List ";
    cin>>n;

    //INSERTION AT HEAD
    for (int i = 0; i < n; i++)
    {   
        cout<<"Enter the data-"<<i+1<<" to be entered ";
        cin>>data;
        //Insert_at_head(head,tail,data);
        Insert_at_tail(head,tail,data);
    }

    //cout<<"Head->"<<head->data<<"->"<<head->next->data<<" ";   
    //head->next is a address of next node so for data of that node will be that_node->data , i.e (head->next)->data

    print_LL(head);

    head = delete_mid(head);
    print_LL(head);

    return 0;
}