#include<bits/stdc++.h>
using namespace std;
int f(int i,int j,vector<vector<int>>&dp){
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;

    if(dp[i][j] != 0) return dp[i][j];

    int up = f(i-1,j,dp);
    int left = f(i,j-1,dp);

    return dp[i][j] = up + left;
}
int uniquePaths(int m, int n) { // memoization
    vector<vector<int>> dp(m,vector<int>(n,0));
    return f(m-1,n-1,dp);
}
int uniquepp(int m,int n){ // tabulation
    vector<vector<int>> dp(m,vector<int>(n,0));
     for(int i = 0;i<m;i++){ 
        for(int j= 0;j<n;j++){
            if(i == 0 && j == 0) dp[i][j] = 1;
            else {
                int left = 0;
                int up = 0;
                if(i>0)  left = dp[i-1][j];
                if(j>0)  up = dp[i][j-1];
                dp[i][j]= left+ up;
            }
        }
    }
  return dp[m-1][n-1];
}
int uniqueps(int m,int n){// space optimization
    vector<int> prev(n,0);
     for(int i = 0;i<m;i++){ 
        vector<int> temp(n,0);
        for(int j= 0;j<n;j++){
            if(i == 0 && j == 0) temp[j] = 1;
            else {
                int left = 0;
                int up = 0;
                if(i>0)  up = prev[j];
                if(j>0)  left = temp[j-1];
                temp[j]= left+ up;
            }
        }
        prev = temp;
    }
  return prev[n-1];
}

int main(){
    int n =7;
    int m = 3;
    cout<<uniqueps(m,n) <<endl;
 return 0;
}