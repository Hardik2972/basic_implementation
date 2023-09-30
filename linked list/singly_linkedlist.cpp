#include<iostream>
using namespace std;
class Node{
    
    public:
      int data;
      Node *next;
      Node(int data){
        this->data=data;
        this->next=NULL;
      }
};

void insertdata(Node* &head,int data){
    Node* temp = new Node(data);
    head->next = temp;
    head=temp;
}

void insertmiddle(Node* &head1,int position,int data){
    int t=1;
    Node *head=head1;
    if (position==1){
        Node* newnode = new Node(data);
        newnode->next=head;
        head1=newnode;
        return ;
    }
    while(t<position-1 && head->next!=NULL){
        head=head->next;
        t++;
    }
    Node* temp=head->next;
    Node* newnode = new Node(data);
    head->next=newnode;
    newnode->next=temp;
}
//delete the node
void deletenode(Node* &head1,int position){
    int t=1;
    Node* head=head1;
    if(position==1){
        head1=head1->next;
        return;
    }
    while(t<position-1 && head->next->next!=NULL){
        head=head->next;
        t++;
    }
    head->next=head->next->next;
}

void printdata(Node* head){
    while(head!=NULL){
        cout<<head->data<<endl;
        head=head->next;
    }
}
int main(){
    Node* head = new Node(24);
    Node* head1=head;
    insertdata(head,12);
    insertdata(head,23);
    insertmiddle(head1,1,30);
    deletenode(head1,6);
    printdata(head1);
    
}