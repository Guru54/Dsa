#include<bits/stdc++.h>
using namespace std;
void printdp(vector<vector<int>> &dp){
        for(auto it: dp){
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    

}
int f(int i,int j,vector<int> &arr,vector<vector<int>> &dp){
    if(i==j) return 0;
    int mini = 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int k =i;k<j;k++){
        int steps = arr[i-1] * arr[k] *arr[j]+ f(i,k,arr,dp) + f(k+1,j,arr,dp);
        mini = min(mini,steps);

    }
    return dp[i][j] =  mini;
}
int matrixMultiplication(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int> (n,-1));
    return f(1,n-1,arr,dp);
}
int tabmcm(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int> (n,0));
    int mini = 1e9;
    for(int i = n-1;i>=1;i--){
        for(int j = i+1;j<n;j++){ // because i should less than j 
            for(int k = i;k<j;k++){
                int steps = arr[i-1] * arr[k] *arr[j]+ dp[i][k] + dp[k+1][j];
               mini = min(mini,steps);
              
            }
            dp[i][j] = mini;
            printdp(dp);
        }
    }
     printdp(dp);
  return dp[1][n-1];
}

int main(){
          vector<int> arr = {10,20,30,40,50};
        //  cout<<matrixMultiplication(arr);
        tabmcm(arr);
 return 0;
}