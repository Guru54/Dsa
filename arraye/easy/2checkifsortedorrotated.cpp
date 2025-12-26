#include<bits/stdc++.h>
using namespace std;
bool issorted(vector<int> &arr){
    int cnt = 0;
    for(int i = 0;i<arr.size();i++){
        // if arr[i]<= arr[i+1] continue
        if(arr[i]>arr[(i+1)%arr.size()])cnt++;
    }
    return cnt<=1;
}
int main(){
       vector<int> arr = {5,4,3,1,2};  
 return 0;
}