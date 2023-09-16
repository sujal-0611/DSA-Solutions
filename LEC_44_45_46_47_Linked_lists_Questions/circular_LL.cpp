#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data)
        {
            this->data=data;
            this->next = NULL;
        }
};

//PRINTS CIRCULAR LINKED LIST
void print_LL(Node* tail)
{
    if(tail !=NULL)
    {   
        Node* traverse=tail->next;  ////storing first node's address (which was stored in tail)
   
        cout<<"first -> ";
        
        do{
            cout<<traverse->data<<" -> ";
            traverse=traverse->next;
        }while(traverse != tail->next); //till again it encounter first element traverse the circular LL

        //cout<<traverse->data<<" <- ";   //since after loop traverse would be back at first element
        cout<<"first";
    }
    else
        cout<<"Linked List is empty"<<endl;
}

//RETURNS THE SIZE OF LL
int getSize_LL(Node* tail)
{
    int n=0;
    if(tail == NULL)
        return 0;

    Node* current=tail->next;   //storing first node's address (which was stored in tail)
    while(current != tail)
    {
        n++;
        current = current->next;
    }
    return n;
}

//INSERTION AT RIGHT SIDE OF TAIL
void Insertion(Node* &tail, int data)
{   
    Node* temp_node = new Node(data);

    if(tail ==NULL)
    {
        tail = temp_node;
        tail->next = temp_node; //making next field of tail to point itself
        return;
    }

    //if tail is not NULL

    //i.e store address of first element that tail had to next field of temp_node (so that temp now point to first node)
    temp_node->next = tail->next;  
    //since tail is no longer a last node(Which points to first node) ,update tail's next field to make it point to new last node(temp_node)
    tail->next= temp_node;   
    //now update tail to make it point to temp_node as new tail node
    tail=temp_node;   
}

//DELETION OF NODE BY FINDING ITS POSITION
void delete_node_by_position(Node* &tail,int position)
{
    if(tail == NULL)
    {
        cout<<"Linked List is empty cant delete!"<<endl;
        return;
    }

    // first node CASE 
    if(position == 1)
    {
        Node* first_node = tail->next;
        tail->next= first_node->next;   //or tail->next= tail->next->next;

        //CASE **i.e THERE'S ONLY A SINGLE NODE IN LL so make tail point to NULL
        if(first_node == tail) 
            tail = NULL;

        first_node->next = NULL;
        delete first_node;
        
        return;
    }

    Node* previous = tail->next;    //storing address of first node in previous

    for(int i=2; i<position; i++)
        previous = previous->next;

    //now we have address of a node that is just before of a node we want to delete
    Node* current = previous->next;

    previous->next= current->next;  //or previous->next = previous->next->next;

    
    if(current == tail) ////case if we gonna delete tail node then update previous node as new tail node
        tail = previous;

    current->next = NULL;
    delete current;  
}   

void delete_node_by_data(Node* &tail,int datas)
{
    if(tail == NULL)
    {
        cout<<"Linked List is empty cant delete!"<<endl;
        return;
    }
    //case for first element
    if(tail->next->data == datas)
    {   
        cout<<"\nFirst Node case"<<endl;
        Node* first_node = tail->next;
        tail->next= first_node->next;   //or tail->next= tail->next->next;
        
        //**i.e THERE'S ONLY A SINGLE NODE IN LL so make tail point to NULL
        if(first_node == tail) 
            tail = NULL;
        
        first_node->next = NULL;
        delete first_node;
        return;
    }

    Node* previous = tail;    //incase of finding node with data element we will start with tail
    int count=0;
    while(previous->next->data != datas)
    {
        previous = previous->next;
        count++;

        if(count > getSize_LL(tail)){      //i.e if it already traversed all of circular LL and still no match is found then return  
            cout<<"No element matched with: "<<datas<<" to be deleted";
            return;
        }
    }    
    //now we have address of a node that is just before of a node we want to delete
    Node* current = previous->next;

    previous->next= current->next;  //or previous->next = previous->next->next;

    //case if we gonna delete tail node then update previous node as new tail node
    if(current == tail)
    {   
         cout<<"\nlast Node case";
        tail = previous;
    }
     else
        cout<<"\nanywhere case";

    current->next = NULL;
    delete current;  
}
 int main()
{   
    system("cls");

    //in circular LL , tail matter more than head
    Node* tail=NULL;   

    int n,data,position;

    cout<<"Enter the number of elements you want to enter in the Circular linked list: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter the element you want to enter in the doubly linked list: ";
        cin>>data;
        //INSERTION AT RIGHT SIDE OF TAIL
        Insertion(tail,data);
    }

    cout<<"\n\nThe Circular linked list is: ";
    print_LL(tail);
    
    //DELETION BY POSITION
    cout<<endl<<"enter the position of node to be deleted: ";
    cin>>position;

    delete_node_by_position(tail,position);
    cout<<"\nThe Circular linked list is: ";
    print_LL(tail);

    //DELETION BY DATA
    cout<<endl<<"enter the number(data) to be deleted: ";
    cin>>data;

    delete_node_by_data(tail,data);
    cout<<"\nThe Circular linked list is: ";
    print_LL(tail);

    

    return 0;
}