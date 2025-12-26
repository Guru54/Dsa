#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int v) : data(v), left(NULL), right(NULL) {}
};


    vector<vector<int>> verticalTraversal(Node* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<Node*, pair<int,int>>> q;

        q.push({root, {0, 0}});

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();

            Node* node = cur.first;
            int x = cur.second.first;
            int y = cur.second.second;

            mp[x][y].insert(node->data);

            if(node->left)
                q.push({node->left, {x - 1, y + 1}});
            if(node->right)
                q.push({node->right, {x + 1, y + 1}});
        }

        vector<vector<int>> ans;

        for(auto &p : mp) {
            vector<int> col;
            for(auto &q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right->left = new Node(9);
    root->right->right = new Node(10);

    Solution s;
    vector<vector<int>> res = s.verticalTraversal(root);

    for(auto &v : res) {
        for(int x : v) cout << x << " ";
        cout << endl;
    }

    return 0;
}
