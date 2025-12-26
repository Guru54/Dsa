#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
      cin.tie(nullptr);    
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    for(int i = 0;i<n;i++){
        if(arr[i]==-1)arr[i]=0;
    }
    int dif =0;
    for(int i = 1;i<n;i++){
         int s = arr[i]-arr[i-1];
         dif+=s;
    }
    cout<<dif<<endl;
    for(auto i: arr) cout<<i<<" ";
  }        
 return 0;
}