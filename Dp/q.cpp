#include<bits/stdc++.h>
using namespace std;
int f(int ind,int cap,vector<int> &amount,int maxi){
    if(cap==0) {
         return maxi;
    }
  
    if(ind == amount.size()) return 0;

    int pick = f(ind+1,cap-1,amount,max(maxi,amount[ind]));

    int notpick = f(ind+1,cap,amount,maxi);

    return pick+notpick;
}
long long magicland(vector<int> &amount,int n,int m){

    return f(0,m,amount,0);
}
int main(){
        vector<int> amount = {2,4,2,3,1};
        int m = 3;
        int n = 5;
        cout<<magicland(amount,n,m);
 return 0;
}