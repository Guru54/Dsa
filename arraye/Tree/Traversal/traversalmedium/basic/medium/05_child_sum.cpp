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
int child= 0;
void childsu(Node* root){
    if(!root) return;

 
   child =0;
    if(root->left)child+=root->left->val;

    if(root->right)child+=root->right->val;
      int h = child;
    if(h>=root->val){
        root->val= child;
    }else{
        if(root->left) root->left->val = root->val;
       else if(root->right) root->right->val= root->val;
    }

    childsu(root->left);
    childsu(root->right);

    int tot = 0;// coming back sum and assigned it back 
    if(root->left) tot+=root->left->val;
    if(root->right) tot+=root->right->val;
    if(root->left || root->right) root->val = tot;  // it ensure that it is not a leaf node
}

int main(){
    vector<int> arr = {40,10,20,2,5,40,30};

    Node *root = build_tree(arr, 0);
    
      childsu(root);
      printl(root);
    return 0;
}