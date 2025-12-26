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
int mincost(vector<int> &cuts, int n){
  cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    
    int m = cuts.size();
    vector<vector<int>> dp(m, vector<int>(m, 0));
    int c = m - 2; // number of cuts

    int mini  = 1e9;
    for(int i = c;i>=1;i--){
        for(int j = i;j<=c;j++){ 
            
           for(int ind = i;ind<=j;ind++){

               int cost = cuts[j+1]-cuts[i-1] + dp[i][ind-1]+dp[ind+1][j];
               mini = min(mini,cost);
           }
           dp[i][j]= mini;
            printdp(dp);
        }
    }
     printdp(dp);
  return dp[1][c];
}     

int main(){
     vector<int> cuts = {1,2,5,6,10};  
     int c = 10;
     cout<<mincost(cuts,c);    
 return 0;
}