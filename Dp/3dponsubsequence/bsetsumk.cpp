#include<bits/stdc++.h>
using namespace std;
bool f(int ind,int target,vector<int> &arr){
    if(target == 0) return true;
    if(ind == 0 ) {
        
            return arr[ind] == target;
        
    }

   bool take = false;
   
   if(arr[ind]<=target){
       take = f(ind-1,target-arr[ind],arr);
    }
    
    bool nottake = f(ind-1,target,arr);
   return (take || nottake);

}

bool isSubset(vector<int> &arr, int target){
    int n = arr.size();
    return f(n-1,target,arr);
}
int main(){
              vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    cout <<"hii i m the ans" << isSubset(arr, sum);
 return 0;
}