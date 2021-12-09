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
};
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
void insertAtIndex(node * &head,int data,int index){
    if(index==0){
        insertAtHead(head,data);
        return;    
    }
    node * n=new node(data);
    node * temp=head;
    for(int i=1;i<index;i++){
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;
}
node * recReverseLL(node * &head){
    //Base Case(head->next==NULL)
    if(head==NULL || head->next==NULL){
        return head;
    }
    //Recursive Case
    node * shead=recReverseLL(head->next);
    head->next->next=head;
    head->next=NULL;
    return shead;
}
node * iterReverseLL(node * head){
    node * curr = head, * prev=NULL, * next=NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
node * kReverseLL(node * head, int k){
    //Base Case
    if(head == NULL){
        return head;
    }
    //Recursive Case
    int count = 1;
    node * curr = head, * prev=NULL, * next=NULL;
    while(curr!=NULL && count<=k){
        next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL){
        head->next=kReverseLL(next,k);
    }
    return prev;
}
int main(){
    node * head=NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtIndex(head,2,0);
    insertAtHead(head,1);
    head=recReverseLL(head);
    head=iterReverseLL(head);
    head=kReverseLL(head,2);
    printLL(head);
    // printLL(head);
}
