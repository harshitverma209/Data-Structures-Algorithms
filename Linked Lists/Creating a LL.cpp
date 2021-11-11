#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node * next;
    node(int data){
        this->data = data;
        this->next = NULL;
    }
}
void insertAtHead(node * &head,int data){
    if(head==NULL){
        head = new node(data);
        return;
    }
    node * n=new node(data);
    n->next=head;
    head=n;
}
void printLL(node * head){
    while(head!=NULL){
        cout<<head->data<<"\t";
        head=head->next;
    }
}
int main(){
    node * head=NULL;
    insertAtHead(head,4);
    insertAtHead(head,5);
    insertAtHead(head,6);
    printLL(head);
    printLL(head);
}