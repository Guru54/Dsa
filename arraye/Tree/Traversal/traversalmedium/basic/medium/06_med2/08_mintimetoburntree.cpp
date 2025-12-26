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
Node* markparents(Node* root,unordered_map<Node*,Node*> &parent,int start){
    queue<Node*> q;
    q.push(root);
    Node* target;
    while(!q.empty()){
        int size = q.size();

        Node* curr = q.front();
        if(curr->val ==start) target = curr;
        q.pop();
        if(curr->left){
            parent[curr->left] = curr;
           q.push(curr->left);
        }
        if(curr->right){
            parent[curr->right] = curr;
            q.push(curr->right);
        }
    }
    return target;
}
int mintimetoburn(Node* root,int start){
    unordered_map<Node*,Node*> parent;
    Node* target = markparents(root,parent,start);
    unordered_map<Node*,bool> vis;
    queue<Node*> q;
    q.push(target);
    vis[target] = true;
    int maxi = 0;
    while(!q.empty()){
        int size = q.size();
        int fl = 0;
        for(int i = 0;i<size;i++){
            auto node = q.front();
            q.pop();
            if(node->left&&!vis[node->left]){
                fl=1;
                vis[node->left] = true;
                q.push(node->left);

            }
            if(node->right&&!vis[node->right]){
                fl=1;
                vis[node->right] = true;
                q.push(node->right);
            }
            if(parent[node]&&!vis[parent[node]]){
                fl=1;
                vis[parent[node]] = true;
                q.push(parent[node]);
            }
        }

        if(fl)maxi++;
        
    }
    return maxi;
}
int main(){
    vector<int> arr = {1,2,3,4,-1,5,6,-1,7};

    Node *root = build_tree(arr, 0);
    
    int mintime = mintimetoburn(root,2);
    cout<<mintime<<endl;

    return 0;
}