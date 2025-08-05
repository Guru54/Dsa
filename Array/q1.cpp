//check if array is sorted or rotated


#include<bits/stdc++.h>
using namespace std;
bool checksorted(vector<int> &arr){
    int n = arr.size();
    int cnt = 0;

    for(int i = 0;i<n;i++){
        if(arr[i]>arr[(i+1)%n]){
            cnt++;
        }
    }
return cnt<=1;
}
int main(){
      vector<int> arr = {3,4,5,1,2};
      vector<int> arr1 ={2,1,3,4};
    cout<<checksorted(arr);//true
    cout<<endl<<checksorted(arr1);//false 
    return 0;
}