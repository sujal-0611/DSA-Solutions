#include <bits/stdc++.h> 
#include<queue>
class CircularQueue{

    public:
    // Initialize your data structure.
        int *arr;
        int size;
        int front;
        int  rear;

    CircularQueue(int n){
        // Write your code here.
        this->size =n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value) {
      // Write your code here.

      // if queue is full base cases
        if ((front == 0 and rear == size - 1) or
            (rear == ((front - 1) % (size - 1))))
            return false;

        if(front ==-1)  //first element to e pushed
            front = rear =0;
        else if ((rear == size - 1) and front != 0)    //if rear is just behind front
            rear = 0;
        else
            rear++;
            
        arr[rear] = value;

        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.

        if( (front == -1))  //queue is empty
            return -1;

        int temp = arr[front];
        arr[front] =-1;

        if (front == rear) // only one element
        {
          front = rear = -1;
        }

        else if(front == size-1)   //i.e front at last position (cyclic nature maintain krna)
        {
            front = 0;
        }
        else
        {   
            //normal pop karo
            front++;
        }
        return temp;
    
    }
}; 