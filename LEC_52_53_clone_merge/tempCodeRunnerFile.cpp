//Clone LinkedLists with random pointers
//IF LL IS PALINDROME OR NOT
#include<iostream>
#include<map>
using namespace std;
class Node{
    public:
        int data;
        Node *next;    //stores address of next node
        Node* random;

        Node(int data) : data(data),next(NULL),random(NULL){}   
};

//PRINT LINKED LIST
void print_LL(Node* head)   
{
    Node* current = head;  

    cout<<endl<<"Linked List as follows:\nHead-> ";
    while( current != NULL) 
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

    if(tail != NULL)    
    {   
        tail->next =temp_node; 
        tail = tail->next;
    }
    else
    {
       head =temp_node;   
        tail=temp_node;     
    }
}

//INSERT AT BEGINING OF LL
void Insert_at_head(Node* &head,Node* &tail, int data)  
{
    Node* temp_node = new Node(data);

    temp_node->next= head; 
    if(head == NULL)
        tail = temp_node;
    
    head = temp_node;
}

Node* clone(Node* head)
{   
    Node* clone_head = NULL;
    Node* ans_tail= NULL;
    
    while(head != NULL)
    {
        Insert_at_tail(clone_head,ans_tail,head->data);
        head = head->next;
    }
    return clone_head;
}
//APPROACH 1 : Create a mapping using map stl- S.C : O(n)
Node* clone_random1(Node* head)
{
    //Step 1: do normal clone
    Node* clone_head = NULL;
    clone_head = clone(head);

     //base cases
        if(head ==NULL)
            return NULL;
        else if(head->next==NULL )
        { 
            if(head->random == head)
                clone_head->random = clone_head;
            
            return clone_head;
        }
    

    //2. Create Map object for mapping and mapp each node of original with clone linked list
    map<Node*,Node*> mapping;
    Node* original =head;
    Node* cloned =clone_head;

    //now mapping both original and clone Linked lists (i.e first node of original LL is mapped to first node of clone LL)
    //example , "head mapped to clone_head" , "second node of original Mapped to second Node of clone"...etc
    while(original!= NULL)
    {
        mapping[original] = cloned;
        
        original = original->next;
        cloned = cloned->next;
    }

    original=head;
    cloned=clone_head;
    
    //**NOW CLONING RANDOM FIELD OF ORIGINAL LL AS WELL INTO CLONE as well
    while(original !=NULL)
    {   
        //taking mapping from orignal and assigning it to clone's random
        //For ex: first node of origanal's random field have address of 4th node of original 
        //then first node of clone's random field will have "mapping[original->random]
        //mapping[original->random]  is mapping[4th node of original] as first node of original's random had address of 4th node
        // then mapping[4th node of origial] will return its mapping i.e "4th node of clone"
        //random of first node of clone will have address of 4th node of clone!!!
        cloned->random = mapping[original->random]; 
        original = original->next;
        cloned = cloned->next;
    }
    return clone_head;

}

void mapping(Node* original, Node* clone)
{   
    //basically inserting clone nodes inbetween original(mapping)
    while(original !=NULL)
    {
        Node* temp1 = original->next;
        Node* temp2 = clone->next;

        original->next = clone;
        original = temp1;

        clone->next = temp1;
        clone = temp2;
    }
}
//APPROACH 2: Create a mapping without using map stl (i.e in S.C O(1))
Node* clone_random2(Node* head)
{
     //Step 1: do normal clone
    Node* clone_head = NULL;
    clone_head = clone(head);

     //base cases
        if(head ==NULL)
            return NULL;
        else if(head->next==NULL )
        { 
            if(head->random == head)
                clone_head->random = clone_head;
            
            return clone_head;
        }


    //Step 2: create Mapping 
    mapping(head,clone_head);
      

    //step 3: clone random feild of clone_LL eaxctly same as original (using mapping we created in step 2)
    Node* original = head;
    Node* clone  = clone_head;
    cout<<endl;
    while(original != NULL and clone!= NULL )
    {   
        if(original->random != NULL){
            clone->random = original->random->next;         
            //getting to the node using mapping: original ke random se uss node pe jao then uska next karo kuki uska next clone se linked h toh ye staement clone node return krega
        }
        else
            clone->random = NULL;

        original = original->next->next;
        if(original != NULL)
            clone = original->next;  
    }
   
    //Step 4: reverse all the changes i.e remove the mapping 
    original = head;
    clone = clone_head;
   
    while( original != NULL and clone !=NULL)
    {
        original->next = clone->next;
        original = original->next;
        
        if(original != NULL)      //cuz we are iterating original 2 times in a single loop iteration 
             clone->next= original->next;
        clone = original->next;
    }
     cout<<"hi ";
    return clone_head;
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
    print_LL(head);

    //manually linking addresses of node to random field of other nodes
    head->random = head->next->next->next;      // 1 with 4
    head->next->random= head->next->next;       //2 with 3
    head->next->next->random = head;            // 3 with 1
    head->next->next->next->random = head->next;     // 4 with 2
    
    int count = 5;
    Node* temp = head;
    while(count--)
    {
        cout<<temp->data<<" ";
        temp = temp->random;
    }

    Node* clone_head =NULL;
    //clone_head = clone_random(head); //APPOROOACH 1 using Map stl(extra space)
    clone_head = clone_random2(head);   // without using Map (i.e in constant space )
    print_LL(clone_head);

    count = 5;
    temp = clone_head;
    while(count--)
    {
        cout<<temp->data<<" ";
        temp = temp->random;
    }
 
    return 0;
}