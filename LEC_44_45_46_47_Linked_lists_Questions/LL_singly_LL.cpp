#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next_node;    //stores address of next node

        Node(int data)  //intializing each node with a value and having null addresss
        {
            this->data=data;
            this->next_node = NULL; 
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
        current = current->next_node;
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
        current = current->next_node;
    }
    return n;
}

//INSERT AT BEGINING OF LL
void Insert_at_head(Node* &head,Node* &tail, int data)  //**by reference bcz so that we dont work on copy ,we are working at original LL
{
    Node* temp_node = new Node(data);

  
    //get address of head node and store it (link it with temp_node) in it's next
    //**incase LL is empty(i.e head is NULL) temp_node ke next mei NULL assign hoga
    temp_node->next_node= head; 

    
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
         //update tail node's next (which previously had NULL) to point to new temp_node we created (i.e linking)
        tail->next_node =temp_node; 

        //now update tail , as new temp_node we inserted at end is our new tail
        tail = tail->next_node;

        //we dont need to do anything with temp_node's 'next' as  temp_node is tail node and tail node's next always have NULL 
        //and temp_node's next already been initialized with NULL DURING temp_node's creation 
        
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
    //if postion at which data to be inserted is at beginning only(i.e insert at first place) then its basically a call for insertion at head 
    if(position == 1)      //1 is for first place (not 0 , 0 represent nothing for positioning)
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
    
     /*why i<position : as we starts from i=2 (the case of i=1 i.e head case already been covered) also at first curr_pos have head ,
     so for i=2 curr_pos then will have address of 2nd node(node at 2nd position),for i=3 curr_pos=address of node at 3rd position and so on....*/
    for(int i=2; i< position; i++)   
        previous=previous->next_node;

    Node* current = previous->next_node ;

    temp_node->next_node = current;
    previous ->next_node = temp_node;
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
        head= head->next_node;
        
        temp->next_node=NULL; //optional as we gonna delete whole node so doesnt matter if we delink this node or not (**matter if we write custom destructor for delete)
        delete temp;
    }

    //REST cases : Deletion in middle or tail 
    Node* previous=head;    
    for(int i=2; i<position;i++)    //to get to the previous node (which is the node previous to the node we gonna delete)
        previous = previous->next_node;

    Node* current =previous->next_node; //getting the node we actually want to delete

    //updating previous node's next field with current node's next field(which contain address of node right after current node)
    previous->next_node = current->next_node;   //i.e linking previous node to "node after current node"
    
    //*****or shorter way   previous->next_node is nothing but "current node" ,here instead of storing it into "current" we are directly accessing it
    //previous->next_node = previous->next_node->next_node;  
    if(current->next_node == NULL)
        tail =previous;

    current->next_node=NULL;
    delete current;     
}

//not running perfectly RN
void delete_all(Node* &head,Node* &tail)
{   
    int n=getSize_LL(head);
    cout<<endl<<"deleting all nodes"<<endl<<"size: "<<n<<endl;
    for(int i=1; i<n-1; i++)  
    {
        delete_node(head,tail,i);
    }
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

    //cout<<"Head->"<<head->data<<"->"<<head->next_node->data<<" ";   
    //head->next_node is a address of next node so for data of that node will be that_node->data , i.e (head->next_node)->data

    print_LL(head);
    cout<<endl<<"Enter the data to be inserted at middle of LL: ";
    cin>>data;

    cout<<endl<<"Enter the Postion at which you want to enter this data(should be  less than equal to (size of LL +  1) ): ";
    cin>>position;


    Insert_at_middle(head,tail,data,position);
    print_LL(head);
    cout<<endl<<"deleting 3rd node\n";
    delete_node(head,tail,3);
    print_LL(head); 
    delete_all(head,tail);  //error hai isme
    print_LL(head);
    
    return 0;
}