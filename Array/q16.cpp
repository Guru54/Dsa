// maximum product subarray
#include<bits/stdc++.h>
using namespace std;
int maximum(vector<int> &arr){
    int n = arr.size();
    int prod = 1;
    int maxprod = 1;
    for(int i =0;i<n;i++){
        for(int j =i;j<n;j++){
            int prod = 1;
            for(int k =j;k<n;k++){
                prod*=arr[k];           
                maxprod = max(maxprod,prod) ;          
            }
        }           
    }
    return maxprod;
}
int maximum1(vector<int> &arr){
    int n = arr.size();
   // int prod = 1;
    int maxprod = INT_MIN;
    for(int i =0;i<n;i++){
        int prod = 1;
        for(int j =i;j<n;j++){
            
                prod*=arr[j];           
                maxprod = max(maxprod,prod) ;          
            
            }           
    }
    return maxprod;
}
int maximum2(vector<int> &arr){
    int n = arr.size();
    int maxi = INT_MIN;
    int pre =1;
    int suff = 1;
    for(int i =0;i<n;i++){
        if(pre ==0) pre= 1;
        if(suff == 0) suff = 1;
        pre*=arr[i]  ;
        suff*=arr[n-i-1];
        maxi = max(maxi,max(pre,suff)) ;

    }
    return maxi;
}

int main(){
     vector<int> arr = {4,3,3,6,-6,2,4,2};
     cout<<maximum(arr);

 return 0;
}