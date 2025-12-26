#include<bits/stdc++.h>
using namespace std;
int f(int ind,int buy,int cap,vector<int> &arr){
    if(cap == 0) return 0;
    if(ind == arr.size()) return 0;
    int profit = 0;
    if(buy){
        profit = max(-arr[ind] + f(ind+1,0,cap,arr), 0 + f(ind+1,1,cap,arr));
    }
    else{
        profit = max(arr[ind] + f(ind+1,1,cap-1,arr), 0 + f(ind+1,0,cap,arr));
    }
    return profit;
}
int buy(vector<int> &arr){
    return f(0,1,2,arr);

}
int tbuy(vector<int> &arr){
    int n = arr.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    for(int ind = n-1;ind>=0;ind--){
        for(int buy = 0;buy<=1;buy++){
            for(int cap = 1;cap<=2;cap++){
                int profit = 0;
                if(buy){
                    profit = max(-arr[ind] + dp[ind+1][0][cap], 0 + dp[ind+1][1][cap]);
                }
                else{
                    profit = max(arr[ind] + dp[ind+1][1][cap-1], 0 + dp[ind+1][0][cap]);
                }
                dp[ind][buy][cap] = profit;
            }
        }
    }
    return dp[0][1][2];
}
int sbuy(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>> ahead(2,vector<int>(3,0));
    vector<vector<int>> curr(2,vector<int>(3,0));
    for(int ind = n-1;ind>=0;ind--){
        for(int buy = 0;buy<=1;buy++){
            for(int cap = 1;cap<=2;cap++){
                int profit = 0;
                if(buy){
                    profit = max(-arr[ind] + ahead[0][cap], 0 + ahead[1][cap]);
                }
                else{
                    profit = max(arr[ind] + ahead[1][cap-1], 0 + ahead[0][cap]);
                }
                curr[buy][cap] = profit;
            }
        }
        ahead = curr;
    }
    return ahead[1][2];
}
int main(){
       vector<int> price = {7,1,5,3,6,4};
       cout<<sbuy(price);
       cout<<endl;
       cout<<tbuy(price);
 return 0;
}