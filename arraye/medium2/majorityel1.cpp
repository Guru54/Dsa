#include<bits/stdc++.h>
using namespace std;
//brute 
int cntw1(vector<int> &arr){
    int n = arr.size()/2;
    for(int i = 0;i<arr.size();i++){
        int cnt = 0;
        for(int j = 0;j<arr.size();j++){
            if(arr[i]==arr[j])cnt++;
        }
        if(cnt>n) return arr[i];
    }
    return -1;
}
//better
int cnt(vector<int> &arr){
    int n = arr.size();
    map<int,int> mpp;
    for(int i =0;i<arr.size();i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]]>n/2) return arr[i];
    }
    return -1;
}
int optimal(vector<int> &arr){
    int n = arr.size();
    int candidate = arr[0];
    int cnt = 1;
    for(int i = 1;i<arr.size();i++){
     
       if(candidate==arr[i]) cnt++;
       else cnt--;

       if(cnt ==0) {
        candidate = arr[i];
        cnt = 1;
       }
    }
    return candidate;
}
int main(){
      vector<int> nums = {2,2,1,1,1,2,2};
        cout<<optimal(nums)<<endl;
        cout<<cnt(nums)<<endl;
        cout<<cntw1(nums)<<endl;
 return 0;
}