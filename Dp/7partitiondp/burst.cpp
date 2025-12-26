#include<bits/stdc++.h>
using namespace std;
#define print(v) for(auto i: v) cout<<i<<" ";

int f(int i,int j,vector<int> &nums,vector<vector<int>> dp){
    if(j<i) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int maxcost = INT_MIN;
    for(int ind = i;ind<=j;ind++){
        int cost = nums[i-1] * nums[ind]* nums[j+1] + f(i,ind-1,nums,dp) + f(ind+1,j,nums,dp);
        maxcost = max(maxcost,cost);
    }
    
 return dp[i][j]= maxcost;
}
int maxcoins(vector<int> &nums){
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(),1);
    vector<vector<int>> dp(nums.size()+1,vector<int> (nums.size()+1,-1));
    return f(1, n,nums,dp);

}
int maxcoinst(vector<int> &nums){
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(),1);
    vector<vector<int>> dp(nums.size()+1,vector<int> (nums.size()+1,0));
    for(int i = n;i>=1;i--){
        for(int j =i;j<=n;j++){
            int maxcost = INT_MIN;
            for(int ind = i;ind<=j;ind++){
              int cost = nums[i-1] * nums[ind]* nums[j+1] + dp[i][ind-1] + dp[ind+1][j];
               maxcost = max(maxcost,cost);
            }
            dp[i][j] = maxcost;
        }
    }
    return dp[1][n];
}
int main(){
  vector<int> arr = {3,1,5,8};  
 cout<< maxcoinst(arr);
 return 0;
}