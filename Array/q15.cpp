#include<bits/stdc++.h>
using namespace std;
int longest(vector<int>&arr,int k ){
    int n= arr.size();
    map<long long,int> mpp;
    long long sum = 0;
   int maxlen = 0;
 //  mpp[0] =1;
    for(int i =0;i<n;i++){
        sum+=arr[i];
        if(sum==k){
            maxlen = max(maxlen,i+1);
           
        }
        int rem = sum-k;
        if(mpp.find(rem)!=mpp.end()){
            int len = i-mpp[rem];
            maxlen = max(maxlen,len);
            
        }
        if(mpp.find(rem)==mpp.end()){
          
            mpp[sum] = i;
            
        }
        
    }
    return maxlen;

}
int main(){
       vector<int> arr= {1,2,3,1,1,1,1,4,2,3};
       cout<<"the lengt of the longest subarray with sum k is :" <<longest(arr,3);    
 return 0;
}