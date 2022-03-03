#include<bits/stdc++.h>
using namespace std;

//二叉树的建立算法
#include <iostream>
using namespace std;
typedef struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
}Node,*BTnode;
//建树算法
Node *createBiTree(){
    BTnode root;
    int ch;
    cin >> ch;
    if (ch == 0)
        root = NULL;
    else{
        root = new node;
        root->data = ch;
        root->lchild=createBiTree();
        root->rchild = createBiTree();
    }
    return root;
}
void preorder(struct node *root){
    if (root){
        cout<<root->data<<" ";
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
int main(){
    BTnode T;
    T = NULL;
    T = createBiTree();
    cout << "建树成功" << endl;
    preorder(T);
}

