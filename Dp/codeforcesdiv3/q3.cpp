#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if(!(cin >> t)) return 0;
    while(t--) {
        int n; cin >> n;
        vector<ll> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        // decide endpoints
        if(a[0] == -1 && a[n-1] == -1) {
            a[0] = 0;
            a[n-1] = 0;
        } else if(a[0] == -1 && a[n-1] != -1) {
            a[0] = a[n-1];
        } else if(a[0] != -1 && a[n-1] == -1) {
            a[n-1] = a[0];
        }
        // fill other -1 with 0
        for(int i=0;i<n;i++){
            if(a[i] == -1) a[i] = 0;
        }
        ll ans = llabs(a[n-1] - a[0]);
        cout << ans << '\n';
        for(int i=0;i<n;i++){
            if(i) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
    return 0;
}
