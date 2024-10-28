#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int val){
    Node* newNode = new Node();
    newNode->data = val;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
Node* insert(Node* root, int val){
    if(root==nullptr){
        return createNode(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    }else if(val > root->data){
        root->right = insert(root->right, val);
    }
    return root;
}
void inOrderTraversal(Node* root){
    if(root == nullptr) return;
    inOrderTraversal(root->left);
    cout<< root->data << "  ";
    inOrderTraversal(root->right);
}
void preOrderTraversal(Node* root){
    if(root==nullptr) return;
    cout<< root->data <<"  ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

}
void postOrderTraversal(Node* root){
    if(root==nullptr) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<< root->data <<"  ";
}
bool search(Node* root, int val){
    if(root==nullptr) return false;
    if(root->data==val) return true;
     if(val==root->data){
        return search(root->left, val);
     }else{
        return search(root->right, val);
     }
}
int main(){
    Node* root = nullptr;
    root = insert(root,50);
    root = insert(root,30);
    root = insert(root,20);
    root = insert(root,40);
    root = insert(root,70);
    root = insert(root,60);
    root = insert(root,80);


    cout<<"IN-ORDER TRAVERSAL OF THE BST: ";
    inOrderTraversal(root);
    cout<<endl;
    cout<<"PRE-ORDER TRAVERSAL OF THE BST: ";
    preOrderTraversal(root);
    cout<<endl;
    cout<<"POST-ORDER TRAVERSAL OF THE BST: ";
    postOrderTraversal(root);
    cout<<endl;
    int key=100;
    if(search(root, key)){
        cout<< key <<" FOUND IN THE BST..."<<endl;
    }else{
        cout<< key <<" NOT FOUND IN THE BST"<<endl;
    }
    system("pause");
    return 0;
    
}