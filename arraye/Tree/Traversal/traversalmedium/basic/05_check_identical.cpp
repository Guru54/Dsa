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
bool isSameTree(Node *t1 ,Node *t2){
    if(!t1||!t2)return (t1==t2);

    return (t1->val==t2->val && isSameTree(t1->left,t2->left) && isSameTree(t1->right,t2->right));
}
int main(){
    vector<int> arr = {1,3,2,5,4,-1,-1,7,6};
    vector<int> arr2 = {1,2,3,-1,-1,4,5};

    Node *t1= build_tree(arr, 0);
    Node *t2 = build_tree(arr2,0);
    
    cout<<isSameTree(t1,t2);
    cout<<endl<<isSameTree(t1,t1);

    return 0;
}