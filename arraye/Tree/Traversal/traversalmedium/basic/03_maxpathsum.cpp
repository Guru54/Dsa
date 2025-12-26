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

int maxpath(Node* root, int &maxi) {
    if(!root) return 0;
    int leftsum  = max(0, maxpath(root->left, maxi));
    int rightsum = max(0, maxpath(root->right, maxi));
    maxi = max(maxi, root->val + leftsum + rightsum);
    return root->val + max(leftsum, rightsum);
}

int maxPathSum(Node* root){
    int maxi = INT_MIN;
    maxpath(root,maxi);
    return maxi;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7};

    Node *root = build_tree(arr, 0);
   cout<<maxPathSum(root);
 // printl(root);

    return 0;
}
