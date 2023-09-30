#include<iostream>
using namespace std;
class Node{
    public:
      int data;
      Node* next;
      Node* prev;

      Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
      }
};

void insertdata(Node* &head,int data){
    Node* newNode = new Node(data);
    head->next = newNode;
    newNode->prev = head;
    head=newNode;
}

void insertAtAny(Node* &head1,int position,int data){
    Node* newNode = new Node(data);
    if(position==1){
        newNode->next=head1;
        head1->prev=newNode;
        head1=newNode;
        return ;
    }
    int t=1;
    Node* head=head1;
    while(t<position-1 && head->next!=NULL){
        head=head->next;
        t++;
    }
    newNode->prev=head;
    newNode->next=head->next;
    head->next=newNode;
}

void deleteNode(Node* &head1, int position){
    if(position ==1){
        head1=head1->next;
        return;
    }
    int t=1;
    Node* head=head1;
    while(t<position-1 && head->next->next!=NULL){
        head=head->next;
        t++;
    }
    head->next=head->next->next;
    if(head->next!=NULL){
        head->next->prev=head;
    }

}
void printdata(Node* head){
    while(head!=NULL){
        cout<<head->data<<endl;
        head=head->next;
    }
}

int main(){
    Node* head = new Node(10);
    Node* head1 = head;
    insertdata(head,12);
    insertdata(head,14);
    insertAtAny(head1,4,11);
    deleteNode(head1,5);
    printdata(head1);
    return 0;
}