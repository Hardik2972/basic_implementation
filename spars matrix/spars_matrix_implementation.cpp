#include<iostream>
using namespace std;

class elements{
    public:
      int i;
      int j;
      int k;
};

class spars{
    public:
      int n;
      int m;
      int num;
      elements* arr;
};

void create(spars &s){
    cout<<"enter the no. of rows";
    cin>> s.n;
    cout<<"enter the no. of col";
    cin>> s.m;
    cout<<"enter the no. of non-zero element";
    cin>> s.num;
    s.arr = new elements[s.num];
    for(int i=0 ;i<s.num;i++){
        cin>>s.arr[i].i>>s.arr[i].j>>s.arr[i].k;
    }
}

void display(spars &s){
    int l=0;
    for(int i=0;i<s.n;i++){
        for(int j=0;j<s.m;j++){
            if(s.arr[l].i==i && s.arr[l].j==j){
                cout<<s.arr[l++].k<<" ";
            }
            else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
}
int main(){
    spars s;
    create(s);
    display(s);
    return 0;
}