#include<iostream>
using namespace std;
class TwoStack{
    int top1;
    int top2;
    int *arr;
    int size;
    public:
      TwoStack(int size){
        this->size=size;
        top1=-1;
        top2=size;
        arr = new int[size];
      }
       void push1(int data){
           if(top1+1==top2) cout<<"the stack is full";
           else{
            top1++;
            arr[top1]=data;
           }
       }
       
       void push2(int data){
           if(top2-1==top1) cout<<"the stack is full";
           else{
            top2--;
            arr[top2]=data;
           }
       }

       void pop1(){
        if(top1==-1) cout<<"underflow";
        else top1--;
       }

       void pop2(){
        if(top2==size) cout<<"usnderflow";
        else top2++;
       }

       void peek1(){
        if(top1==-1) cout<<"the stack is empty";
        else cout<<arr[top1];
       }
       
       void peek2(){
        if(top2==size) cout<<"the stack is empty";
        else cout<<arr[top2];
       }


};
int main(){
    TwoStack s1(5);
    s1.push1(1);
    s1.push1(2);s1.push1(3);
    s1.push2(4);
    s1.push2(5);
    s1.peek1();
    s1.pop1();
    s1.peek1();
    s1.peek2();
    
}