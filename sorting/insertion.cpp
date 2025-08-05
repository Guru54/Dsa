#include<bits/stdc++.h>
using namespace std;
void insertion(vector<int>& arr){
    int n = arr.size();
    for(int i =1;i<n;i++){
      int j =i;
      while(j>0&&arr[j-1]>arr[j]){
        swap(arr[j],arr[j-1]);
        j--;
      }      
    }
}
void reverseArray(vector<int>& arr) {
  int n = arr.size();
  for (int i = 0; i < n / 2; i++) {
    swap(arr[i], arr[n - i - 1]);
  }
}
int main(){
    vector<int> arr= {5,2,32,3,23};
    insertion(arr);

     for(int i =0;i<5;i++){
         cout<<arr[i]<<" ";           
     }   
 return 0;
}
