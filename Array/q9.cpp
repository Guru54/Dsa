// next permutation
#include<bits/stdc++.h>
using namespace std;


void next(vector<int> &arr){
    int n = arr.size();
    int idx = -1;
    for(int i = n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            idx = i;
            break;
        }

    }
    if(idx==-1){
        reverse(arr.begin(),arr.end());
        return ;
    }
    for(int i = n- 1;i>=0;i--){

       if(arr[i]>arr[idx]){

       
        swap(arr[i],arr[idx]);
        break;
       }
    }
    reverse(arr.begin()+idx+1,arr.end());
    return ;
}
int main(){
  vector<int> arr = {3,1,2};   
  next(arr)  ; 
for(int i =0;i<3;i++){
    cout<<arr[i]<<" ";
}
 return 0;
}