//move zeros to the end
#include<bits/stdc++.h>
using namespace std;
vector<int> moved(vector<int> arr){
    int n = arr.size();
    int j = -1;
    //place the pointer j:
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            j = i;
            break;
        }
    }

    
    if (j == -1) return arr;
    for(int i =j+1;i<n;i++){
       if(arr[i]!=0){
       swap(arr[i],arr[j]);
       j++;
       }    
    }
    return arr;
}
int main(){
  vector<int> arr = {0,2,0,3,20,0,2,0,4,5,6,7};
  vector<int> ans = moved( arr);
  for (auto &it : ans) {
      cout << it << " ";
  }     
 return 0;
}