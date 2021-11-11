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
int middleElement(node * head){
    node * slow=head, * fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->data;
}
int kthLast(node * head,int k){
    node * slow=head, * fast=head;
    while(k>0){
        fast=fast->next;
        k--;
    }
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    return slow->data;
}
node * midPoint(node * head){
    node * slow=head, * fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
node * mergeSortLL(node * head){
    //Base Case
    if(head==NULL || head->next==NULL){
        return head;
    }
    //Recursive Case
    node * left=head, * mid = midPoint(head);
    node * right=mid->next;
    mid->next=NULL;
    left=mergeSortLL(left);
    right=mergeSortLL(right);
    return mergeSortedLL(left, right);
    
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
    cout<<middleElement(merger)<<endl;
    cout<<kthLast(merger,2)<<endl;
    node * unsorted=new node(5);
    insertAtHead(unsorted,4);
    insertAtHead(unsorted,9);
    insertAtHead(unsorted,3);
    insertAtHead(unsorted,6);
    node * sortedLL=mergeSortLL(unsorted);
    printLL(sortedLL);
    // printLL(head);
}