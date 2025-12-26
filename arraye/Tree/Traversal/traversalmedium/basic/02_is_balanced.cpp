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
    if(i >= arr.size()) {
        return NULL;
    }
    
    Node* root = new Node(arr[i]);
    if(arr[i]==-1){
        root= nullptr;
    }else{
    root->left  = build_tree(arr, 2*i + 1);
    root->right = build_tree(arr, 2*i + 2);
    }
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

// int findlh(Node* root){
//     if(!root) return 0;
//     return 1+findlh(root->left);
// }
// int findrh(Node* root){
//     if(!root) return 0;
//     return 1+findrh(root->right);
// }
// bool check(Node* root){
//     if(!root) return true;
//     int lh = findlh(root->left);
//     int rh = findrh(root->right);
//     cout<<lh<<" "<<rh<<endl;
//     if(abs(rh-lh)> 1) return false;
//     bool left = check(root->left);
//     bool right = check(root->right);
//     if(!left || !right) return false;
//     return true;
// }
int height(Node* root){
    if(!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    if(lh==-1||rh==-1)return -1;
    if(abs(lh-rh)>1) return -1;
    return 1+max(lh,rh);

}
bool isbalanced(Node* root){
    return height(root)!=-1;
}
int main(){
    vector<int> arr = {1,3,2,5,4,-1,-1,7,6};

    Node *root = build_tree(arr, 0);
 // cout<<  check(root);
  cout<<isbalanced(root);
    
 // printl(root);

    return 0;
}
