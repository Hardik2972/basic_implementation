#include<iostream>
using namespace std;

class queue{
    int size;
    int *arr;
    int qfront;
    int rear;
    public:
      queue(int size){
        this -> size= size;
        arr = new int[size];
        qfront = 0;
        rear = 0;
      }

      void enqueue(int data){
        if(rear==size-1) cout<<"the stack is full";
        else{
            arr[rear]=data;
            rear++;
        }
      }

      void dequeue(){
        if(qfront == rear ) cout<<"underflow";
        else{
            qfront++;
            if(qfront == rear){
              qfront=0;
              rear=0;
            }
        }
      }

      void front(){
        if(qfront==rear) cout<<"the stack is empty";
        else{
            cout<<arr[qfront]<<endl;
        }
      }
};
int main(){
   queue q(10);
   q.enqueue(23);
   q.enqueue(45);
   q.enqueue(50);
   q.dequeue();
   q.front();
}