#include<bits/stdc++.h>
#define for(x,y) for(int i=x;i<y;i++)
using namespace std;

class node{
    public: 
    int  data;
    node* next;
    
    node(int val){
        data=val;
        next=NULL; 
    }
};

void insrtbytail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;    
    }
    
    node* temp=head;
    while(temp->next!=NULL){
       temp= temp->next;
    }
    temp->next=n;
}
void insertbyhead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}
void deletion(node* &head,int n){
    if(head->data==n){
        node* todelete=head;
        head=head->next;
        delete todelete;
        return;
    }
       node* temp= head;
    while(temp->next->data!=n){
        temp=temp->next;
    }
 
    node* todelete= temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

bool search(node* head,int t){
   while(head!=NULL){
    if(head->data==t)return true;
    head=head->next;
   }return false;
}
node* reverselist(node* head){
    node* nxt;
    node* prev=NULL;
    node* curr=head;

   while(curr!=NULL){
    nxt=curr->next;
    curr->next=prev;
    prev=curr;
    curr=nxt;
   }
   return prev;
}
node* recursivereverse(node* &head){
    if(head==NULL || head->next==NULL)return head;
    node* newhead= recursivereverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
void makecycle(node* &head, int pos){
    node* temp=head;
    node *startnode;
    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startnode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startnode;
}
bool detectcycle(node* &head){
    node* slow=head;
    node* fast=head;
    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow){
            return true;
        }
    }
    return false;
}
void removecycle(node* &head){
    node* slow=head;
    node* fast=head;
    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){fast=head; break;}
    }
    while(fast->next!=slow->next){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=NULL;
}

void display(node* head){
     while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
     }cout<<"NULL" <<endl;
}

int main(){
    node* head=NULL;
    for(0,5){
        insrtbytail(head,i);
    }
  //  insertbyhead(head,-1);
    display(head);
    cout<<search(head,5)<<endl;
  //  deletion(head,3);
  makecycle(head,3);
  cout<<detectcycle(head)<<endl;
  removecycle(head);
  cout<<detectcycle(head)<<endl;
  //  node* newhead=reverselist(head);
  //  node* rnewhead=recursivereverse(head);  
   display(head);

}