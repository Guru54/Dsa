#include<bits/stdc++.h>
using namespace std;
int maxfreq(vector<int> &arr) {
    unordered_map<int,int> freq;
    int maxf = 0;

    for(int x : arr){
        maxf = max(maxf, ++freq[x]);
    }
    return maxf;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        int cnt = 0;
        while(maxfreq(arr)>k){
            cnt++;
            multiset<int> st;
            for(int i = 0;i<n;i++){
                st.insert(arr[i]);
                if(st.count(arr[i])>1) arr[i]+=1;
            }
        
        }
        cout<<cnt<<endl;
    }
               
 return 0;
}