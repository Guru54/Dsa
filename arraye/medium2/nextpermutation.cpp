#include<bits/stdc++.h>
using namespace std;
vector<int> nextp(vector<int> &a){
    int n = a.size();
    int idx = -1;
    for(int i = n-2;i>=0;i--){
        if(a[i]<a[i+1]){
            idx = i;
            break;
        }
    }
    // return revrse of a
    if(idx ==-1) return a;
    for(int i= n-1;i>=idx;i--){
        if(a[i]>a[idx]){
            swap(a[i],a[idx]);
        }else{
            break;
        }
    }
    reverse(a.begin()+idx+1,a.end());
    return a;

}
int main(){
        vector<int> arr = {3,1,2};
        vector<int> ans = nextp(arr);
        for(auto it: ans){
            cout<<it<<" ";
        }
        cout<<endl;
     
   
 return 0;
}