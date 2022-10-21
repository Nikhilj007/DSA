#include<bits/stdc++.h>
#define fr(x,y) for(int i=x;i<y;i++)
#define int long long
#define vec(v) vector<int> v
#define vp(v) vector<pair<int,int>> v
#define mi(m) map<int,int> m
#define msi(m) map<string,int> m 

using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    if(head!=NULL)head->prev=n;
    head=n;
}

void insertAtTail(node* &head,int val){
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    node* n=new node(val);
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
    return;
}
void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    head->prev=NULL;
    delete todelete;
    return;
}

void deletion(node* &head,int pos){
    if(pos==0){
        deleteAtHead(head);
        return;
    }
    int c=0;
    node* temp=head;
    
    while(temp!=NULL && c!=pos){
        temp=temp->next;
        c++;
    }
     temp->prev->next=temp->next;
    if(temp->next!=NULL)temp->next->prev=temp->prev;
    delete temp;
}

void display(node* head){
    while(head!=NULL){
       
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL\n";
}

signed main(){
    node* head=NULL;
    fr(1,5)insertAtTail(head,i);
    display(head);
  //  insertAtHead(head,0);
    deletion(head,0);
    display(head);
    
}