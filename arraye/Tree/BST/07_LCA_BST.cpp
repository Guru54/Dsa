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
Node* lca(Node* root,int p,int q){
      Node* cur= root;
      while(true){
        if(cur->val<p&&cur->val <q){
            cur  = cur->left;
        }else if(cur->val>p&&cur->val>q){
            cur= cur->right; 
        }else{
            break;
        }
      }
      return cur;
}
int main(){
     vector<int> arr = {6,2,8,0,4,7,9,-1,-1,3,5};

    Node *root = build_tree(arr, 0);
     Node *ans = lca(root,2,8);
     cout<<ans->val;
    

    return 0;
}