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
void pre(Node* root){
    if(!root) return;
     
    cout<<root->val<<" ";
    pre(root->left);
    pre(root->right);

}
vector<int> getPreFromMoris(Node* root){
    if(!root) return {};
    vector<int> in;
    Node* cur= root;
    while(cur){
        if(!cur->left){
            in.push_back(cur->val);
            cur= cur->right;
        }else{
            Node *prv = cur->left;
            while(prv->right&&prv->right!=cur){
                prv = prv->right;
            }

            if(!prv->right){
                prv->right= cur;
                in.push_back(cur->val);
                cur= cur->left;
            }else{
                prv->right= nullptr;
                cur = cur->right;
            }
        }
    }
    return in;
}
vector<int> getInFromMoris(Node* root){
    if(!root) return {};
    vector<int> in;
    Node* cur= root;
    while(cur){
        if(!cur->left){
            in.push_back(cur->val);
            cur= cur->right;
        }else{
            Node *prv = cur->left;
            while(prv->right&&prv->right!=cur){
                prv = prv->right;
            }

            if(!prv->right){
                prv->right= cur;
                cur= cur->left;
            }else{
                prv->right= nullptr;
                in.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return in;
}
int main(){
    vector<int> arr = {1,2,3,4,5,-1,-1,-1,-1,6};

    Node *root = build_tree(arr, 0);
    vector<int>  inorder =getInFromMoris(root);
    //for(auto i: inorder)cout<<i<<" ";
    vector<int> preorder = getPreFromMoris(root);
    for(auto i: preorder) cout<<i<<" ";
    
    cout<<"\n ";
    pre(root);

    return 0;
}