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
Node* insertt(Node* root,int val){
    Node* t= root;
        while(true){
           if(root->val<=val){
            if(root->left){
                root= root->left;
            }else{
                root->left= new Node(val);
                break;
            }
           }else{
            if(root->right){
                root = root->right;
            }else{
                root->right= new Node(val);
                break;
            }
           }
       
         }
      
         return t;
}
int main(){
    vector<int> arr = {4,2,7,1,3};

    Node *root = build_tree(arr, 0);
    
     Node *ans = insertt(root,5);
     printl(ans);

    return 0;
}