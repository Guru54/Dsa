// intersection of two sorted arrays 
#include<bits/stdc++.h>
using namespace std;
vector<int> inters1(vector<int> &arr,vector<int> &ar){
    int n1 = arr.size();
    int n2 = ar.size();
    vector<int> ans;
    int vs[n2] = {0};
    for(int i =0;i<n1;i++){
        for(int j =0;j<n2;j++){
              if(arr[i]==ar[j]&&vs[j]==0) {
                ans.push_back(arr[i]);
                vs[j] =1;
                break;
              }  
              if(ar[j]>arr[i])     break; 
        }       
    }
    return ans;
}
vector<int> inters2(vector<int> &arr,vector<int> &ar){
    int n1 = arr.size();
    int n2 = ar.size();
    vector<int> ans;
    int i=0,j = 0;
    while(i<n1&&j<n2){
        if(arr[i]<ar[j]){
            i++;
        }else if(ar[j]<arr[i]){
            j++;
        }else{
            ans.push_back(arr[i]);
            i++;
            j++;
        }
    }
    return ans;
}
int main(){
   vector<int> arr = {1,2,2,3,3,4,5,6};
   vector<int> ar = {2,3,3,5,6,6,7};
   vector<int> inter = inters2(arr,ar) ;  
   for(auto it : inter){
    cout<<it<<" ";
   }
 return 0;
}