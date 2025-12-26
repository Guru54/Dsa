#include<bits/stdc++.h>
using namespace std;
int noflis(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n,1),cnt(n,1);
   int maxi = 1;
    for(int i= 0;i<n;i++){
        for(int previ = 0;previ<i;previ++){
            if(arr[i]>arr[previ] && 1+dp[previ]>dp[i]){
                dp[i]= 1+dp[previ];
                cnt[i] = cnt[previ];
            }else if(arr[i]>arr[previ] && 1+dp[previ]==dp[i]){
                cnt[i]+= cnt[previ];
            }
        }
        maxi = max(maxi,dp[i]);
    }
    int nos = 0;
    for(int i = 0;i<dp.size();i++){
        if(maxi == dp[i])nos+=cnt[i];
    }
    return nos;
}
int main(){
           
 return 0;
}