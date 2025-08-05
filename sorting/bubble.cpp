#include<bits/stdc++.h>
using namespace std;
int bubble_sort(vector<int> &arr){
  int n = arr.size(); 
  int cnt = 0;
int flag =0;
  for(int i =0;i<n-1;i++){
    cnt++;
    flag =0;
    for(int j = 0;j<n-i-1;j++) {
        cnt++;
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
            flag =1;
        }
    }  
    if(!flag) break;       
  }  
 return cnt; 
}
int main(){
       vector<int> arr= {2,4,1,8,4,31};
      cout<< bubble_sort(arr) <<endl;
       for(int i =0;i<6;i++){
           cout<<arr[i]<<" ";           
       }   
 return 0;
}