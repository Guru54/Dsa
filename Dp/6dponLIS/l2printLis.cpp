#include<bits/stdc++.h>
using namespace std;
int printLis(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n, 1);
    int maxi = 1;

    for(int i = 0; i < n; i++){
        for(int prev = 0; prev < i; prev++){
            if(arr[i] > arr[prev]){
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}
int printLis1(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n,1);
    vector<int> hash(n);
    int maxi = 1;
    int lastindex = 0;
    for(int i = 0;i<n;i++){
        hash[i]= i;
        for(int previ= 0;previ<i;previ++){
            if(arr[previ]<arr[i]&&1+dp[previ]>dp[i]){
                dp[i]= dp[previ]+1;
                hash[i] = previ;
            }
        }
        if(dp[i]>maxi){
            maxi = dp[i];
            lastindex =i;
        }
    }
    vector<int> temp;

    temp.push_back(arr[lastindex]);
    while(hash[lastindex]!=lastindex){
        lastindex= hash[lastindex];
        temp.push_back(arr[lastindex]);
    }
    reverse(temp.begin(),temp.end());
    for(auto it : temp) cout<<it<<" ";

    cout<<endl;

    return temp.size();
}
int main(){
       vector<int> arr = {5,4,11,1,16,8};
       cout<<printLis1(arr);
 return 0;
}