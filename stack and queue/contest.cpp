#include<iostream>
using namespace std;
int main(){
    int t;
    int o;
    cin>>t;
    o=t;
    while(t){
        long long int s,d,k;
        cin>>s>>d>>k;
        long long int buns=2*(s+d);
        long long int inside=s+(2*d);
        if(buns>k && inside>=k){
            cout<<"Case #"<<o-t+1<<": YES"<<endl;
        }
        else{
            cout<<"Case #"<<o-t+1<<": NO"<<endl;
        }
        t--;
    }
}