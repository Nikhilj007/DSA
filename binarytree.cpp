#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }

};
//DFS are of three types:- preorder, inorder, postorder deifined as below.

void preorderp(node* root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    preorderp(root->left);
    preorderp(root->right);
}

void inorderp(node* root){
    if(root==NULL)return;
    inorderp(root->left);
    cout<<root->data<<" ";
    inorderp(root->right);
}

void postorderp(node* root){
    if(root==NULL)return;
    postorderp(root->left);
    postorderp(root->right);
    cout<<root->data<<" ";
}

//** Now iterative Breadth First Search

void itpreorder(node* root){
    if(root==NULL)return;
    stack<node*> st;
    st.push(root);
    while(st.size()){
        root= st.top();
        st.pop();
        cout<<root->data<<" ";
        if(root->right!=NULL)st.push(root->right);
        if(root->left!=NULL)st.push(root->left);
    }
}

void itinorder(node* root){
    if(root==NULL)return;
    stack<node*> st;
    st.push(root);
    while(st.size()){
        root= st.top();
        st.pop();
        cout<<root->data<<" ";
        if(root->right!=NULL)st.push(root->right);
        if(root->left!=NULL)st.push(root->left);
    }
}


//BFS is a level wise traversal defined as below.

void levelorder(node* root){
    if(root==NULL)return;
    queue<node*> q;
    q.push(root);
    while(q.size()){
        for(int i=0;i<q.size();i++){
           node* x=q.front();
           q.pop();
           if(x->left!=NULL)q.push(x->left);
           if(x->right!=NULL)q.push(x->right);
           cout<<x->data<<" "; 
        }
    }
}

int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(curr==inorder[i])return i;
    }return -1;
}

node* buildTree(int preorder[],int inorder[],int start ,int end){
    static int idx=0;
    if(start>end)return NULL;
    int curr=preorder[idx];
    
    idx++;
    node* Node = new node(curr);
   // cout<<Node->data<<endl;
    if(start==end){
        return Node;
    }
    int pos=search(inorder,start,end,curr);
    Node->left=buildTree(preorder,inorder,start,pos-1);
    Node->right=buildTree(preorder,inorder,pos+1,end);
    return Node;
}

int main(){
    
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    node* root=buildTree(preorder,inorder,0,4);
    preorderp(root);
    cout<<endl;
    itpreorder(root);
    cout<<endl;
    inorderp(root);
    cout<<endl;
    postorderp(root);
    cout<<endl;
    levelorder(root);

}