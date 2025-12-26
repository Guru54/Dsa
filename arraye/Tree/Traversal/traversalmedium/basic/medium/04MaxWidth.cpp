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
int maxwidth(Node* root){
    if(!root) return 0;

    long long ans = 0;
    queue<pair<Node*, long long>> q;
    q.push({root, 0});

    while(!q.empty()){
        int size = q.size();
        long long minIndex = q.front().second;
        long long first = 0, last = 0;

        for(int i = 0; i < size; i++){
            auto it = q.front();
            q.pop();

            Node* nd = it.first;
            long long curr_id = it.second - minIndex; // normalization

            if(i == 0) first = curr_id;
            if(i == size - 1) last = curr_id;

            if(nd->left)
                q.push({nd->left, curr_id * 2 + 1});

            if(nd->right)
                q.push({nd->right, curr_id * 2 + 2});
        }

        ans = max(ans, last - first + 1);
    }

    return ans;
}

int main(){
    vector<int> arr = {1,7,10,9,2,2,7,11,10,9,6,1,7,-1,10};

    Node *root = build_tree(arr, 0);
    
    cout<<maxwidth(root); 


    return 0;
}