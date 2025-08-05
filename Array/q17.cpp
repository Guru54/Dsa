//maximum sum subarray 
#include<bits/stdc++.h>
using namespace std;
int maxsum(vector<int> &arr){
    int n = arr.size();
    int sum = 0;
    int maxi = INT_MIN;
    for(int i =0;i<n;i++){
        sum+=arr[i];  
        maxi = max(maxi,sum);

        if(sum<0){
            sum = 0;
        }
    }
    return maxi;
}
int main(){
  vector<int> arr = {12,32,42,-122,103};
cout<<maxsum(arr);
 return 0;
}