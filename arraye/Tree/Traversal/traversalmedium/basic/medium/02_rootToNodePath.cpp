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
bool solve(Node* root,vector<int> &ans,int x){
    if(!root)return false;
    ans.push_back(root->val);
    if(root->val == x) return true;

    if(solve(root->left,ans,x)||solve(root->right,ans,x)) return true;

    ans.pop_back();

    return false;
}
vector<int> getpath(Node* root,int val){
    vector<int> ans;
    if(!root)return ans;
    solve(root,ans,val);
    return ans;
}
int main(){
    vector<int> arr = {1,2,-1,4,5,-1,-1,-1,-1,6,7};

    Node *root = build_tree(arr, 0);
    
  vector<int> ans=   getpath(root,7);
  for(auto i: ans){
    cout<<i<<" ";
  }

    return 0;
}