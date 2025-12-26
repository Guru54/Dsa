#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    ll value;
    Node* left;
    Node* right;
    bool deleted;
    Node(ll v) : value(v), left(nullptr), right(nullptr), deleted(false) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }
        if (n == 2) {
            cout << max(a[0], a[1]) << '\n';
            continue;
        }
        
        vector<Node*> nodes;
        for (ll val : a) {
            nodes.push_back(new Node(val));
        }
        
        for (int i = 0; i < n; i++) {
            nodes[i]->left = nodes[(i - 1 + n) % n];
            nodes[i]->right = nodes[(i + 1) % n];
        }
        
        using Tuple = tuple<ll, Node*, Node*>;
        auto cmp = [](const Tuple& a, const Tuple& b) {
            return get<0>(a) > get<0>(b);
        };
        priority_queue<Tuple, vector<Tuple>, decltype(cmp)> pq(cmp);
        
        for (int i = 0; i < n; i++) {
            Node* node = nodes[i];
            Node* right = node->right;
            ll cost = max(node->value, right->value);
            pq.push({cost, node, right});
        }
        
        ll total_cost = 0;
        int remaining = n;
        
        while (remaining > 1) {
            Tuple top = pq.top();
            pq.pop();
            ll cost = get<0>(top);
            Node* node1 = get<1>(top);
            Node* node2 = get<2>(top);
            if (node1->deleted || node2->deleted) {
                continue;
            }
            total_cost += cost;
            ll new_value = max(node1->value, node2->value);
            Node* newNode = new Node(new_value);
            newNode->left = node1->left;
            newNode->right = node2->right;
            node1->left->right = newNode;
            node2->right->left = newNode;
            node1->deleted = true;
            node2->deleted = true;
            remaining--;
            
            if (newNode->left != newNode) {
                ll cost_left = max(newNode->value, newNode->left->value);
                pq.push({cost_left, newNode->left, newNode});
            }
            if (newNode->right != newNode) {
                ll cost_right = max(newNode->value, newNode->right->value);
                pq.push({cost_right, newNode, newNode->right});
            }
        }
        
        cout << total_cost << '\n';
        
        for (Node* node : nodes) {
            delete node;
        }
    }
    
    return 0;
}