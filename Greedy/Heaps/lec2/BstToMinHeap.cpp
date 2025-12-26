#include <bits/stdc++.h>
#include "Tree.h"

using namespace std;

void inorder(Node* root, vector<int> &arr) {
    if(root == NULL) {
        return;
    }

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

void fillPreorder(Node* root, int &index, vector<int> arr) {
    if(root == NULL) {
        return;
    }

    if(index < arr.size()) {
        root->data = arr[index++];
    }

    fillPreorder(root->left, index, arr);
    fillPreorder(root->right, index, arr);
}

void BST_Heap(Node* root) {
    vector<int> arr;
    inorder(root, arr);
    int i = 0;
    fillPreorder(root, i, arr);
}

int main() {
    Node* root = NULL;    
    takeinput(root);

    cout << "Before converion into haep, BST : " << endl;
    levelOrderTraversal(root);

    BST_Heap(root);

    cout << "After converion into haep, BST : " << endl;
    levelOrderTraversal(root);

    return 0;
}

// 4 2 6 1 3 5 7 -1
//Given a binary search tree which is also a complete binary tree. The problem is to convert the given BST into a Min Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied to all the nodes, in the resultant converted Min Heap. 