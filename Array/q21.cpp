// merge two sorted arrays without using any extra space 
#include<bits/stdc++.h>
using namespace std;
//brute force approach  = make an arr3 compare arr1 and arr2 and return the arr3
//optimal is given below 
void connect(vector<int> &arr1,vector<int> &arr2){
int n = arr1.size();
int m = arr2.size();
int left = n-1;
int right = 0;
while(left>=0&&right <m){
    if(arr1[left]>arr2[right]){
        swap(arr1[left],arr2[right]);
        left--;
        right++;
    }else{
        break;
    }

}
sort(arr1.begin(),arr1.end());
sort(arr2.begin(),arr2.end());
}
void print(vector<int> &arr){
    int n = arr.size();
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" " ;         
    }
    cout<<endl;
}
int main(){
  vector<int> arr1 = {1,3,5,7};
  vector<int> arr2 = {0,2,6,8,9};
  connect(arr1,arr2); 
  print(arr1);
  print(arr2);

 return 0;
}