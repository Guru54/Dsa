#include<bits/stdc++.h>
using namespace std;


int main(){
      ios::sync_with_stdio(false);
      cin.tie(nullptr);
  int t;
  cin>>t;
  while(t--) {
    int n;
    cin>>n;
    int config =0;
    if(n&1) config = 0;
    else{
        config = floor(n/4)+1;
    }

    cout<<config<<endl;
  }     
 return 0;
}
