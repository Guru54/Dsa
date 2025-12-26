#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if(!(cin >> t)) return 0;
    while(t--){
        long long a, b, n;
        cin >> a >> b >> n;

        if (b >= a) {
            cout << 1 << '\n';
        } else if (n * b <= a) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
    return 0;
}
