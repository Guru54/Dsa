#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

long long modpow(long long a,long long b){
    long long r=1;
    while(b){
        if(b&1) r=r*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return r;
}

long long fact[5005], invfact[5005];

long long nCr(int n,int r){
    if(r<0 || r>n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0]=1;
    for(int i=1;i<=5000;i++) fact[i]=fact[i-1]*i%MOD;
    invfact[5000]=modpow(fact[5000], MOD-2);
    for(int i=4999;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%MOD;

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];

        sort(a.begin(),a.end());

        vector<int> freq;
        for(int i=0;i<n;){
            int j=i;
            while(j<n && a[j]==a[i]) j++;
            freq.push_back(j-i);
            i=j;
        }

        sort(freq.begin(),freq.end());
        int mx = freq.back();

        int cnt_mx = 0;
        for(int f: freq)
            if(f == mx) cnt_mx++;

        long long prod=1;
        for(int f:freq){
            prod = prod * (f+1) % MOD;
        }

        if(cnt_mx >= 2){
            cout << prod << "\n";
        } else {
            int sec = freq[freq.size()-2];
            long long bad = nCr(mx, sec);
            long long ans = (prod - bad + MOD) % MOD;
            cout << ans << "\n";
        }
    }
}
    