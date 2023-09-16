#include<iostream>
using namespace std;

template <typename T>
class Node{
    public:
        T data;
        Node<T> *next; 

        Node(T datas): data(datas),next(NULL) {}
};
template <typename T>
T peek(Node<T>* head)
{
    return head->data;
}

int main()
{   
    system("cls");
    Node<char>* head= NULL;
    Node<char>* newNode = new Node<char>('a');

    head = newNode;

    cout<<peek(head);

    
    
    return 0;
}