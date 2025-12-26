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
int fl(Node* root,int x){
    int ans =-1;
    while(root){
        if(root->val==x){
            return root->val;
        }else if(x>root->val){
            ans = root->val;
            root = root->right;
        }else{
            root= root->left;
        }
    }
    return ans;
}
int ceiil(Node* root,int x){
    int ans =-1;
    while(root){
        if(root->val==x){
            return root->val;
        }else if(x>root->val){
            root = root->right;
        }else{
            ans = root->val;
            root= root->left;
        }
    }
    return ans;
}
Node* search(Node* root,int val){
    // while(root){
    //     if(root->val==val)break;
    //    root =  root->val <val ? root->left: root->right;
    // }
    while(root&&root->val!val){
          root =  root->val < val ? root->left: root->right;
    }
    return root;
}
int main(){
    vector<int> arr = {1,3,2,5,4,-1,-1,7,6};

    Node *root = build_tree(arr, 0);
    
    

    return 0;
}