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

void inorderp(node* root){
    if(root == NULL)return;
    inorderp(root->left);
    cout<<root->data<<" ";
    inorderp(root->right);
}

node* insertBST(node* root,int val){
    if(root==NULL){
        node* n=new node(val);
        return n;
    }
    if(val<root->data){
        root->left=insertBST(root->left,val);
    }
    else{
        root->right=insertBST(root->right,val);
    }
    return root;

}

int main(){
    node* root=NULL;
    root= insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);

    inorderp(root);
}