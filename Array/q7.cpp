// missing number from 1 to n
#include<bits/stdc++.h>
using namespace std;
int missing1(vector<int> &arr){
    int n = arr.size();

    int N = n+1;
    cout<<n<<" "<<N<<endl;
    for(int i = 1;i<=N;i++){
        int flag =0;
        for(int j = 0;j<n;j++){
          if(arr[j]==i){ flag = 1;
          break;
          }
        }
        if(flag == 0) return i;
    }
return -1;
}
int missing2(vector<int> &arr){
    int n = arr.size();
    int hash[n+1] = {0};
    for(int i = 0;i<n;i++){
        hash[arr[i]]++;
    }
    for(int i = 1;i<n;i++){
        if(hash[i]==0) return i;
    }

}
//optimal 1 use xor
// optimal 2 use maths formula n*(n-1)/2;
int main(){
  vector<int> arr = {1,2,3,4,5,7,8,9};
  cout<<missing2(arr);         
 return 0;
}