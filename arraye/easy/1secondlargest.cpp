#include<bits/stdc++.h>
using namespace std;
int secondlargest(vector<int> &arr){
    int n = arr.size();
    int largest = INT_MIN;
    int slargest = -1;
    for(int i = 0;i<n;i++){
         if(arr[i]>largest){
             slargest= largest;
              largest = arr[i];
         }else if(arr[i]<largest && arr[i]>slargest){
              slargest= arr[i];
         }
    }
    return slargest;
}
int main(){
  vector<int> arr = {2,3,3,4,5,3,5};
  cout<<secondlargest(arr)  <<endl;    
 return 0;
}

// burte sort than serach from back
// better find largest than slargest
// find slargest in one go 