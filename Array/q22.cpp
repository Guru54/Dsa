// merge overlapping sub intervals 
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>  sub(vector<vector<int>> &arr){
  sort(arr.begin(),arr.end());
  int n =arr.size();
  vector<vector<int>> ans;
  for(int i =0;i<n;i++){
      int start = arr[i][0];
      int end = arr[i][1] ;
      if(!ans.empty() && end<=ans.back()[1]){
        continue;
      }    
      for(int j=i+1;j<n;j++){
        if(arr[j][0]<=end){
          end= max(end,arr[j][1]);

        }else{ 
          break;
        }
                     
      } 
      ans.push_back({start,end});
  }
  return ans;
}
vector<vector<int>> sub1(vector<vector<int>> &arr){
  sort(arr.begin(),arr.end());
  int n =arr.size();
  vector<vector<int>> ans;
  for(int i =0;i<n;i++){
      if(ans.empty()|| ans.back()[1]<arr[i][0]){
     
      ans.push_back(arr[i]);
      }else{
        ans.back()[1] = max(ans.back()[1],arr[i][1]);
       // cout<<" hello ";
      } 
       
  }
  return ans;
}
int main(){
  vector<vector<int>> arr ={{1,3},{2,6},{8,9},{9,11},{8,10},{2,4},{15,18},{16,17}};  
  vector<vector<int>> ans = sub1(arr);
  cout<<"the merged intervals are : "<<endl;
  for(auto it: ans){
    cout<<" ["<<it[0]<<","<<it[1]<<"] ";
  }
 return 0;
}