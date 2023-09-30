#include <iostream> 
class CircularQueue{
    int size;
    int front;
    int rear;
    int *arr;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
       size=n;
       front=-1;
       rear=-1;
       arr=new int[size];
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if((front==0 && rear==size-1)||(rear==(front-1)%(size-1))){
            return false;
        }
        else{
            if(front==-1){
                front=0;
                rear=0;
                arr[front]=value;
            }
            else if(rear==size-1 && front!=0){
                rear=0;
                arr[rear]=value;
            }
            else{
                rear++;
                arr[rear]=value;
            }
            return true;
            
        }
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        int ans;
        if(front==-1) ans=-1;
        else{
            if(front==rear){
                ans=arr[front];
                rear=front=-1;
            }
            else if(front==size-1){
                ans=arr[front];
                front=0;
            }
            else{
                ans=arr[front];
                front++;
            }
            
        }
        return ans;
        
    }
};
