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
//brute
int findmax(Node* root,int &d){
    if(!root) return 0;
    int lh = findmax(root->left,d);
    int rh = findmax(root->right,d);
    d = max(d,lh+rh);
    return 1+max(lh,rh);

}
int diameter(Node* root){
    int d =0;
    findmax(root,d);
    return d;
}
int main(){
    vector<int> arr = {1,3,2,5,4,-1,-1,7,6};

    Node *root = build_tree(arr, 0);
    
    cout<<diameter(root);

    return 0;
}