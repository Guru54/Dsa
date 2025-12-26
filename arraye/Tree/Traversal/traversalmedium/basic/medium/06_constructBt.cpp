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
Node* solve(int i,int sin,int ein,vector<int> &in,vector<int> &pre){
    if(i>=pre.size()||sin >ein) return nullptr;

    int ind = -1;
    for(int j= sin;j<=ein;j++){
        if(in[j]==pre[i]){
            ind = j;
            break;
        }
    }
    Node* root = new Node(pre[i]);
    root->left= solve(i+1,sin,ind-1,in,pre);
    root->right= solve(i+(ind-sin+1),ind+1,ein,in,pre);
    return root;
}
Node* build(vector<int> & in,vector<int> & pre){
     
    return solve(0,0,in.size()-1,in,pre);

}
int main(){
    vector<int> inorder = {40,20,50,10,60,30};
    vector<int> preorder = {10,20,40,50,30,60};

 
    Node *root = build(inorder,preorder);
    printl(root);

    
    

    return 0;
}