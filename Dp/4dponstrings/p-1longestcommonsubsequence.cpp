#include<bits/stdc++.h>
using namespace std;
int f(int i ,int j ,string &s,string &t,vector<vector<int>> &dp){

    if(i<0 ||j<0) return dp[i][j] =  0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans1 = 0;
    if(s[i]==t[j]){
        ans1 = 1+f(i-1,j-1,s,t,dp);
    }else{
        ans1 =  max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
    }
    return  dp[i][j] = ans1;

}
int lcs(string &s,string &t){ // memoization
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n,vector<int> (m,-1));
    int ans =  f(n-1,m-1,s,t,dp);
   
    for(auto it: dp){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return ans;
}
int tlcs(string &s,string &t){
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<m+1;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1+ dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int slcs(string &s,string &t){
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    vector<int> prev(m+1,0),curr(m+1,0);
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<m+1;j++){
            if(s[i-1]==t[j-1]){
                curr[j] = 1+ prev[j-1];
            }else{
                curr[j] = max(prev[j],curr[j-1]);
            }
        }
        prev = curr;
    }
    return prev[m];
}
int main(){
     string text1 = "abcde", text2 = "ace";
   // cout << lcs(text1, text2); 
      cout<<slcs(text1,text2);

 return 0;
}