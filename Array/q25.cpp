// sort an arrays of 0 1 and 2
#include<bits/stdc++.h>
using namespace std;
void sort(vector<int>&arr){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int mid = 0;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }else if(arr[mid]==1){
            mid++;
        }else{
            swap(arr[high],arr[mid]);
            high--;
        
        }
    }
}
int main(){
  vector<int> arr = { 0,2,1,2,1,2,1,0,2,1}   ;  
  sort(arr);
  int n = arr.size();
  for(int i =0;i<n;i++){
      cout<<arr[i]<<" ";           
  }
 return 0;
}