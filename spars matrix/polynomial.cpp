#include <iostream>
using namespace std;

class term{
    public:
      int coeff;
      int exp;
};

class poly{
    public:
      int n;
      term* arr;
};

void create(poly &p)
{
    cout<<"enter the no. of terms";
    cin>>p.n;
    p.arr = new term[p.n];
    for(int i=0;i<p.n;i++){
        cin>>p.arr[i].coeff>>p.arr[i].exp;
    }
}

poly add(poly p1 , poly p2)
{
    poly sum;
    sum.n=p1.n+p2.n;
    sum.arr = new term[sum.n];
    int i=0;
    int j=0;
    int k=0;
    while(i<p1.n && j<p2.n){
        if(p1.arr[i].exp>p2.arr[j].exp){
            sum.arr[k++]=p1.arr[i++];
        }
        else if(p1.arr[i].exp<p2.arr[j].exp){
            sum.arr[k++]=p2.arr[j++];
        }
        else{
            sum.arr[k].exp=p1.arr[i].exp;
            sum.arr[k++].coeff=p1.arr[i++].coeff+p2.arr[j++].coeff;
        }
    }
    for(;i<p1.n;i++) sum.arr[k++]=p1.arr[i];
    for(;j<p1.n;j++) sum.arr[k++]=p2.arr[j];
    return sum;
}

poly multiply(poly p1,poly p2){
    poly mul;
    mul.n=p1.n*p2.n;
    int flag = 1;
    int t=0;
    for(int i=0;i<p1.n;i++){
        for(int j=0;j<p2.n;j++){
            int coeff = p1.arr[i].coeff*p2.arr[j].coeff;
            int exp = p1.arr[i].exp+p2.arr[j].coeff;
            for(int k =0;k<mul.n;k++){
                if(mul.arr[k].exp==exp) {
                    flag = 0;
                    mul.arr[k].coeff+=coeff;
                }
            }
            if(flag ==1) {
                mul.arr[t].coeff=coeff;
                mul.arr[t++].exp=exp;
            }
        }
    }
    return mul;
}
void display(poly p){
    for(int i=0;i<p.n;i++){
        cout<<p.arr[i].coeff<<"x^"<<p.arr[i].exp<<" ";
    }
    cout<<endl;
}
int main()
{
    poly p1,p2;
    create(p1);
    create(p2);
    poly sum = multiply(p1,p2);
    display(sum);
    return 0;
}

