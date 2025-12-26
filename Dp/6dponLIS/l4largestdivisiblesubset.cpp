#include<bits/stdc++.h>
using namespace std;
vector<int> lds(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n,0);
    vector<int> hash(n);
    int maxi = 1;
    int lastindex = 0;
    sort(arr.begin(),arr.end());
    for(int i = 0;i<n;i++){
        hash[i]= i;
        for(int previ= 0;previ<i;previ++){
            if(arr[i]%arr[previ] == 0 &&1+dp[previ]>dp[i]){
                dp[i]= dp[previ]+1;
                hash[i] = previ;
            }
        }
        if(dp[i]>maxi){
            maxi = dp[i];
            lastindex =i;
        }
    }
    vector<int> temp;

    temp.push_back(arr[lastindex]);
    while(hash[lastindex]!=lastindex){
        lastindex= hash[lastindex];
        temp.push_back(arr[lastindex]);
    }
    reverse(temp.begin(),temp.end());


    return temp;
}
int main(){
           vector<int> arr = {1,16,7,8,4};
           vector<int> ans = lds(arr);
           for(auto i : ans){
            cout<<i<<" ";
           }
           cout<<endl;
 return 0;
}