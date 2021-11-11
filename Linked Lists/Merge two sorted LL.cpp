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
    cout<<endl;
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
node * mergeSortedLL(node * h1, node * h2){
    if(h1!=NULL && h2!= NULL){
        node * temp=NULL;
        if(h1->data>h2->data){
            temp=h2;
            temp->next=mergeSortedLL(h1,h2->next);
        }else{
            temp=h1;
            temp->next=mergeSortedLL(h1->next,h2);
        }
        return temp;
    }
    else{
        if(h1==NULL){
            return h2;
        }
        if(h2==NULL){
            return h1;
        }
    }
}
int main(){
    node * head=NULL;
    insertAtHead(head,9);
    insertAtHead(head,7);
    insertAtHead(head,5);
    insertAtIndex(head,3,0);
    insertAtHead(head,1);
    head=recReverseLL(head);
    head=iterReverseLL(head);
    // head=kReverseLL(head,2);
    printLL(head);
    node * h2=new node(8);
    insertAtHead(h2,6);
    insertAtHead(h2,4);
    insertAtHead(h2,2);
    printLL(h2);
    node *merger=mergeSortedLL(head,h2);
    printLL(merger);
    // printLL(head);
}