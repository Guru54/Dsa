#include<bits/stdc++.h>
using namespace std;
int f(int ind,int w,vector<int> &val,vector<int> &wt,vector<vector<int>> &dp){

    if(ind == 0){
        if(w>=wt[ind]) return dp[ind][w] = val[ind];
        else   return dp[ind][w] =  0;
    }
    if(dp[ind][w]!= -1) return dp[ind][w];
    int nottake =  val[ind] + f(ind-1, w,val,wt,dp);
    int take = INT_MIN;
    if(w>=wt[ind]){
        take = val[ind] +  f(ind-1,w-wt[ind],val,wt,dp);
    }
    return dp[ind][w] =  max(nottake,take);
}
int knapsack(int maxweight,vector<int> &val,vector<int> &weight){ // memoization
    int n = val.size();  
    vector<vector<int>> dp(n+1,vector<int> (maxweight+1,-1));
    return f(n-1,maxweight,val,weight,dp);

}
int tknapsack(int w,vector<int> &val,vector<int> &wt){ //tabulization
    int n = val.size();
    vector<vector<int>> dp(n,vector<int> (w,0));
    for(int i = wt[0];i<=w;i++) dp[0][i] =val[0];

    for(int i = 1;i<n;i++){
        for(int j = 0;j<=w;j++){
             int nottake =  val[i] + dp[i-1][j];
             int take = INT_MIN;
             if(wt[i]<j){
                take = val[i] + dp[i-1][j-wt[i]];
             }
             dp[i][j] = max(nottake,take);
        }
    }

  return dp[n-1][w];
}


int main(){
       vector<int> val = {1, 2, 3};

       vector<int> wt= {4, 5, 1};
       int w = 4;

     cout << tknapsack(w, val, wt);     
 return 0;
}