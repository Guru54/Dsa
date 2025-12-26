#include<bits/stdc++.h>
using namespace std;
int f(int ind,int buy,vector<int> &arr, vector<vector<int>> &dp){
    if(ind == arr.size()) return 0;
    int profit = 0;
    if(dp[ind][buy]!= -1) return dp[ind][buy];
    if(buy){
        profit = max(-arr[ind] + f(ind+1,0,arr,dp), 0 + f(ind+1,1,arr,dp));
    }
    else{
        profit = max(arr[ind] + f(ind+1,1,arr,dp), 0 + f(ind+1,0,arr,dp));
    }
    return dp[ind][buy] = profit;
}

int buy(vector<int> &arr){
    vector<vector<int>> dp(arr.size(),vector<int>(2,-1));   
    return f(0,1,arr,dp);
}
int tbuy(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    for(int ind = n-1;ind>=0;ind--){
        for(int buy = 0;buy<=1;buy++){
            int profit = 0;
            if(buy){
                profit = max(-arr[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
            }
            else{
                profit = max(arr[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}
int sbuy(vector<int> &arr){
    int n = arr.size();
    vector<int> ahead(2,0);
    vector<int> curr(2,0);
    for(int ind = n-1;ind>=0;ind--){
        for(int buy = 0;buy<=1;buy++){
            int profit = 0;
            if(buy){
                profit = max(-arr[ind] + ahead[0], 0 + ahead[1]);
            }
            else{
                profit = max(arr[ind] + ahead[1], 0 + ahead[0]);
            }
            curr[buy] = profit;
        }
        ahead = curr;
    }
    return ahead[1];
}
int main(){
        vector<int> price = {7,1,5,3,6,4};
       cout<<sbuy(price);
       cout<<endl;
       cout<<tbuy(price);
 return 0;
}