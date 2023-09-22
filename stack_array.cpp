#include<iostream>
using namespace std;
class stack{
    int top;
    int *arr;
    int size;
    public:
      stack(int size){
        this->size=size;
        arr = new int[size];
        top=-1;
      }
      void push(int data){
        if(top==size-1) cout<<"stack overflow";
        else{
            top++;
            arr[top]=data;
        }
      }
      void pop(){
        if(top==-1) cout<<"stack underflow";
        else{
            top--;
        }
      }
      void peek(){
        if(top==-1) cout<<"stack is empty";
        else{
            cout<<arr[top];
        }
      }
      void isempty(){
        if(top==-1) cout<<"stack is empty";
        else cout<<"the stack is not empty";
      }
};
int main(){
    stack s1(5);
    s1.push(2);
    s1.push(3);
    s1.peek();
    s1.pop();
    s1.peek();
    s1.pop();
    s1.pop();
}