//left rotate an array by d places
#include<bits/stdc++.h>
using namespace std;
void lefte(vector<int> &arr,int k){
    int n = arr.size();
  reverse(arr.begin(),arr.begin()+k);
  reverse(arr.begin()+k,arr.end());
  reverse(arr.begin(),arr.end());  
}
int main(){
  vector<int> arr = {1,2,3,4,5,6,7};
  lefte(arr,3);
  for(int i =0;i<7;i++){
        cout<<arr[i]<<" ";
  }      
 return 0;
}