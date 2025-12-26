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
Node* first,*pvr,*middle,*last;
void inorder(Node *root){
    if(!root) return;
    
    inorder(root->left);
   if(pvr && root->val < pvr->val){

        if(!first){
            first = pvr;
            middle = root;
        }else{
            last = root;
        }

    }
    pvr = root;
    inorder(root->right);

}
void recovertree(Node* root){
   first = middle = last= nullptr;
   pvr = nullptr;
   inorder(root);
   if(first&&last){
    swap(first->val,last->val);
   }else if(first&&middle){
    swap(first->val,middle->val);
   }

}

int main(){
     Node* root = new Node(6);
    root->left = new Node(10);
    root->right = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(7);
    root->right->right = new Node(12);

    cout << "Before recovery: ";
    printl(root);

    recovertree(root);

    cout << "\nAfter recovery: ";
    printl(root);

    return 0;
}