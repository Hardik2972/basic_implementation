#include<iostream>
using namespace std;

class heap{
    public:
      int arr[100];
      int size=0;
      heap(){
        size=0;
        arr[0]=-1;
      }
      void insert(int val){
          size=size+1;
          int index = size;
          arr[index]=val;
          while(index>1){
            int parent = index/2;
            if(arr[parent]<arr[index]){
                swap(arr[index],arr[parent]);
                index=parent;
            }
            else return;
          }
      }
      void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
      }

      void delte(){
        arr[1]=arr[size];
        size-=1;
        int index=1;
        while(index<size){
            int childl=2*index;
            int childr=2*index+1;
            if(childl<size && arr[childl]>arr[index]){
                swap(arr[childl],arr[index]);
                index=childl;
            }
            else if(childr<size && arr[childr]>arr[index]){
                swap(arr[childr],arr[index]);
                index=childr;
            }
            else{
                return ;
            }
        }

      }
};



int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.delte();
    h.print();
    
    return 0;
}