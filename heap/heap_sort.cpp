#include<iostream>
using namespace std;
void heapify(int arr[],int n,int index){
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;
    if(left<n && arr[largest]<arr[left]){
        largest = left;
    }
    if(right<n && arr[largest]< arr[right]){
        largest = right;
    }
    if(largest!=index){
        swap(arr[largest],arr[index]);
        heapify(arr,n,largest);
    }

}
void heap_sort(int arr[],int n){
    if(n==1){
        return ;
    }
    swap(arr[0],arr[n-1]);
    n--;
    heapify(arr,n,0);
    heap_sort(arr,n);
}

void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]={1,2,3,4,5,6,7};
    for(int i=7/2;i>=0;i--){
        heapify(arr,7,i);
    }
    print(arr,7);
    heap_sort(arr,7);
    
    print(arr,7);
    return 0;
}