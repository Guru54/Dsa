#include<bits/stdc++.h>
using namespace std;
int f(int ind,vector<int>&heights,vector<int>&dp,int k){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int left = INT_MAX;
   // int right = INT_MAX;
    for(int i = 1;i<=k;i++){

    if(ind - i >= 0){
     int jump =f(ind-i,heights,dp,k)+abs(heights[ind]-heights[ind-i]);
    
    left = min(left,jump);
    }
    }
    return dp[ind]=left;
}
int frogJump(int n, vector<int> &heights, int k)
{
    vector<int>dp(n,-1);
    return f(n-1,heights,dp,k);
}
int main(){
         vector<int>heights={10,30,40,20};
         int k=2;
            int n=heights.size();
            cout<<frogJump(n,heights,k);  
 return 0;
}