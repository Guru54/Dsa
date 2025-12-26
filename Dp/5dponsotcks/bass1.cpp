#include<bits/stdc++.h>
using namespace std;
int buy(vector<int> &arr){

    int maxi = 0;
    int mini = arr[0];
    for(int i = 1;i<arr.size();i++){
          int profit = arr[i]-mini;
          maxi = max(maxi,profit);
          mini = min(mini,arr[i]);
    }
    return maxi;
}
int main(){
      vector<int> price = {7,1,5,3,6,4};
      cout<<buy(price);     
 return 0;
}