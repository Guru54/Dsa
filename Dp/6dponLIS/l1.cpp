#include<bits/stdc++.h>
using namespace std;
int f(int ind,int previ,vector<int> &arr,vector<vector<int>> &dp){
    if(ind == arr.size()) return 0;
    if(dp[ind][previ+1]!=-1) return dp[ind][previ+1];
   int len = f(ind+1,previ,arr,dp);

   if(previ ==-1 || arr[ind]>arr[previ]) {
    len = max(len,1+f(ind+1,ind,arr,dp));
   }
    return dp[ind][previ+1] = len;
}
int lenoflis(vector<int> &arr){ // memoization
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int> (n+1,-1));
    return f(0,-1,arr,dp);
}

int tablenoflis(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>> dp(arr.size()+1,vector<int> (arr.size()+1,0));

    for(int ind = n-1;ind>=0;ind-- ){
        for(int previ = ind-1;previ>= -1;previ--){
            int len = 0+dp[ind+1][previ+1];
            if(previ == -1|| arr[ind]>arr[previ+1]){

            
            len = max(len,1+dp[ind+1][ind+1]);
            }
            dp[ind][previ+1]=len;
        }
    }
    return dp[0][0];
}
int spalenoflis(vector<int> &arr){
    int n = arr.size();
    vector<int> prev(n+1,0),curr(n+1,0);
        for(int ind = n-1;ind>=0;ind-- ){
           for(int previ = ind-1;previ>= -1;previ--){
            int len = prev[previ+1];
            if(previ == -1|| arr[ind]>arr[previ+1]){

            
            len = max(len,1+prev[ind+1]);
            }
            curr[previ+1]=len;
        }
       prev =curr;
    }
    return prev[0];
    
}


int main(){
       vector<int> arr = {5,4,11,1,16,8};
       cout<<lenoflis(arr);
       cout<<endl<<tablenoflis(arr);
       cout<<endl<<spalenoflis(arr);
 return 0;
}