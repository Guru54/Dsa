//leaders in an array    : leader = everything in the right should be greater 
#include<bits/stdc++.h>
using namespace std;
vector<int> leader(vector<int> &arr){
    int n= arr.size();
    vector<int> ans;
    for(int i =0;i<n;i++){
        bool leader = true;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                leader = false;
                break;
            } 

        }       
        if(leader==true)   ans.push_back(arr[i]);
    }
    return ans;
}
vector<int> leader1(vector<int> &arr){
    int n= arr.size();
    vector<int> ans;
    int maxi = INT_MIN;

    for(int i =n-1;i>=0;i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(maxi,arr[i]);           
    }
    sort(ans.begin(),ans.begin());
    return ans;
}
int main(){
  vector<int> arr = {10,22,12,3,0,6};
  vector<int> ans = leader1(arr);
  for(auto it : ans){
    cout<<it<<" ";
  }
 return 0;
}

