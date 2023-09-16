//creating first node of LL
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
int main()
{   
    system("cls");

    //since LL uses heap memory for memory allocations so we are creating dynamic objects 
    Node* node1= new Node(5);    //creating dynamic nodes and intializing each with some data(info)
    Node* head; //to keep track which node is at top

    head = node1;

    return 0;
}