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
void markparents(Node* root,unordered_map<Node*,Node*> &parent){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr->left){
            parent[curr->left] =curr;
            q.push(curr->left);
        }
        if(curr->right){
            parent[curr->right] =curr;
            q.push(curr->right); 
        }
    }
}
vector<int> distancek(Node* root,Node* target,int k){
    unordered_map<Node* ,Node*> parent;
    markparents(root,parent);
    unordered_map<Node*,bool> visited;
    visited[target] = true;
    queue<Node*> q;
    q.push(target);
    int currlevel = 0;
    while(!q.empty()){
        int size = q.size();
        if(currlevel++ ==k) break;
        for(int i =0;i<size;i++){
            Node* current = q.front(); 
            q.pop();
            if(current->left&&!visited[current->left]){
                q.push(current->left);
                visited[current->left] = true;
            }
            if(current->right&&!visited[current->right]){
                q.push(current->right);
                visited[current->right] = true;
            }
            if(parent[current]&&!visited[parent[current]]){
                q.push(parent[current]);
                visited[parent[current]]= true;
            }


       }

    }
    vector<int> res;
    while(!q.empty()){
        Node *curr = q.front(); q.pop();
        res.push_back(curr->val);
    }
    return res;
    
}
int main(){
    vector<int> arr = {3,5,1,6,2,0,8,-1,-1,7,4};

    Node *root = build_tree(arr, 0);
    Node* target = root->left;
    int k = 2;
    
    vector<int> ans = distancek(root,target,k);
    for(auto i: ans)cout<<i<<" ";

    return 0;
}