#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Preorder Traversal (Root → Left → Right)
void preorder(Node *root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal (Left → Right → Root)
void postorder(Node *root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Inorder Traversal (Left → Root → Right)
void inorder(Node *root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Level Order Traversal
vector<vector<int>> level(Node *root) {  // Fixed function name
    vector<vector<int>> ans;
    if (root == nullptr) return ans;
    
    queue<Node *> q;
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        
        for (int i = 0; i < size; i++) {
            Node *node = q.front();
            q.pop();
            level.push_back(node->data);
            
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
        
        ans.push_back(level);
    }
    
    return ans;
}
vector<int> itpre(Node *root) {
    vector<int> pre;
    if (root == nullptr) return pre;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node *node = st.top();
        st.pop();  // Remove the current node
        pre.push_back(node->data);

        // Push right child first, so left is processed first
        if (node->right != nullptr) {
            st.push(node->right);
        }
        if (node->left != nullptr) {
            st.push(node->left);
        }
    }

    return pre;
}
vector<int> itin(Node *root){
    stack<Node*> st;
    Node* node = root;
    vector<int> inoreder;
    while(true){
     if(node!= nullptr){
        st.push(node);
         node = node->left;
     }else{
        if(st.empty()==true){
            break;
        }
        node = st.top();
        st.pop();
        inoreder.push_back(node->data);
        node = node->right;
     }


    }
    return inoreder;
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << "\nPostorder Traversal: ";
    postorder(root);
    cout << "\nInorder Traversal: ";
    inorder(root);
    cout << "\nLevel Order Traversal:\n";
    
    vector<vector<int>> ans = level(root);
    for (auto it : ans) {
        for (auto a : it) {
            cout << a << " ";
        }
        cout << endl;
    }
   vector<int> ans1 = itpre(root);
   cout<<"the preorder traversal by itrative approach is :";
   for(auto it: ans1){
    cout<<it<<" ";
   }
   cout<<endl;
   vector<int> ans2 = itin(root);
   cout<<"the inoreder traversal by itrative approach is :";
   for(auto it: ans2){
    cout<<it<<" ";
   }
    return 0;
}
