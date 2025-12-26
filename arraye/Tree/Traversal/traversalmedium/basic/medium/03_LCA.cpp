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
Node* lowestCommonAn(Node* root,int p,int q){
    if(!root|| root->val ==p || root->val ==q){
        return root;
    }
    Node* left = lowestCommonAn(root->left,p,q);
    Node* right = lowestCommonAn(root->right,p,q);
     if(left&&right){
        cout<<left->val<<" "<<right->val<<endl;
     }
    if(!left){
        return right;
    }else if(!right){
        return left;
    }else{
        return root;
    }
}
int main(){
   // vector<int> arr = {1,2,3,-1,-1,4,5,-1,-1,-1,-1,8,-1,6,7};
    vector<int> arr = {1,2,3,4,5,8,9,-1,-1,6,7};

    Node *root = build_tree(arr, 0);
     Node *ans = lowestCommonAn(root,4,7);
     cout<<ans->val;
    

    return 0;
}