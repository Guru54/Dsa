#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node(int val){
        this->val = val;
        left = right = nullptr;
    }
};

Node* build_tree(vector<int> &arr, int i){
    if(i >= arr.size() || arr[i] == -1){
        return nullptr;
    }

    Node* root = new Node(arr[i]);
    root->left  = build_tree(arr, 2*i + 1);
    root->right = build_tree(arr, 2*i + 2);

    return root;
}

void printl(Node *root){
    if(!root) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node *curr = q.front();
        q.pop();

        cout << curr->val << " ";

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}
Node* build(vector<int> &arr,int &i,int bound){
    if(i==arr.size()||arr[i]>bound)return nullptr;
    Node* root = new Node(arr[i++]);
    root->left = build(arr,i,root->val);
    root->right =  build(arr,i,bound);
    return root;
}
Node* bstFromPreOrder(vector<int> &arr){
    int i = 0;
    return build(arr,i,INT_MAX);
}
int main(){
    vector<int> arr = {8,5,7,10,12};

    Node *root = bstFromPreOrder(arr);
    printl(root);
    
    

    return 0;
}