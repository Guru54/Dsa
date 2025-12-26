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
Node* build(int i,int sin,int ein,vector<int> &in,vector<int>&post){
    if(i<0||sin>ein) return nullptr;
    cout<<i<<" "<<sin<<" "<<ein<<endl;
    int ind = -1;
    for(int j = sin;j<=ein;j++){
        if(in[j]==post[i]){
            ind = j;
            break;
        }
    }
    Node *root = new Node(post[i]);
   
    root->right= build(i-1,ind+1,ein,in,post);
    root->left= build(i-(ein-ind+1),sin,ind-1,in,post);
}
int main(){
    vector<int> in = {40,20,50,10,60,30};
    vector<int> post = {40,50,20,60,30,10};

    Node *root = build(post.size()-1,0,in.size()-1,in, post);
    
    
   printl(root);
    return 0;
}