#include<iostream>
#include<vector>
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
spars transpose(spars &s){
    int nonzero=s.num;
    int col=s.m;
    int row=s.n;
    spars sc;
    sc.n=col;
    sc.m=row;
    sc.num=nonzero;
    sc.arr = new elements[nonzero];
    vector<int> count(col,0);
    vector<int> index(col,0);
    for(int i=0;i<nonzero;i++){
        count[s.arr[i].j]++;
    }
    index[0]=count[0];
    for(int i=1;i<col;i++){
        index[i]=index[i-1]+count[i-1];
    }
    for(int i=0;i<nonzero;i++){
        sc.arr[index[s.arr[i].j]].i=s.arr[i].j;
        sc.arr[index[s.arr[i].j]].j=s.arr[i].i;
        sc.arr[index[s.arr[i].j]].k=s.arr[i].k;
        index[s.arr[i].j]++;
    }
    display(sc);
    return sc;

}
int main(){
    spars s;
    create(s);
    transpose(s);
    display(s);
    return 0;
}