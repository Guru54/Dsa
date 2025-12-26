#include<bits/stdc++.h>
using namespace std;
int lcs(string &s,string &t){
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1+  dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    for(auto it: dp){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    int i  = n;
    int j = m;
    string w = "";
    while(i>0&&j>0){
        if(s[i-1] == t[j-1]){
           w+=s[i-1];
           i--,j--;
        }else {
             if (dp[i - 1][j] > dp[i][j - 1])
                i = i - 1;
            else
                j = j - 1;
        }
    }
    cout<<s;
    return dp[n][m];
 
}
int main(){
        string text1 = "abcde", text2 = "ace";
        //cout<<lcs(text1,text2);
 return 0;
}