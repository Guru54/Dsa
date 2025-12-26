#include<bits/stdc++.h>
using namespace std;
int lcs(string &s,string &t){
   int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    int maxi = INT_MIN;
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<m+1;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1+ dp[i-1][j-1];
                maxi = max(maxi,dp[i][j]);
            }
        }
    }
 

    return maxi;
}
int longestSubstring(string &s,string &t){
  return lcs(s,t);
}
int main(){
    string s = "ABCDGH", t = "ACDGHR";

    cout<<longestSubstring(s,t);

 return 0;
}