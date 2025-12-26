#include<bits/stdc++.h>
using namespace std;
bool ls(vector<int> &arr,int el){
    for(int i = 0;i<arr.size();i++){
        if(arr[i]==el){
            return true;
        }
    }
    return false;
}
// brute
int longestcon(vector<int> &arr){
    //sort(arr.begin(),arr.end());
    int maxi = -1;
    for(int i = 0;i<arr.size();i++){
        int x = arr[i];
        int cnt = 1;
        while(ls(arr,x+1)){
            x= x+1;
            cnt++;
        }
        maxi= max(maxi,cnt);
    }
    return maxi;
}
// optimal 
int longest(vector<int> &arr){
    set<int> st;

}
int main(){
  vector<int> arr = {102,4,100,1,101,3,2,1,1};

 cout<< longest(arr);
        
 return 0;
}