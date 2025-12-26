#include<bits/stdc++.h>
using namespace std;
int robLinear(vector<int>& nums) {
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    
    for(int i = 1; i < n; i++){
        int take = nums[i];
        if(i > 1) take += prev2;
        int notTake = prev;
        int curr = max(notTake, take);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    
    vector<int> firstPart(nums.begin(), nums.end() - 1);
    vector<int> secondPart(nums.begin() + 1, nums.end());
    
    return max(robLinear(firstPart), robLinear(secondPart));
}
int main(){
  vector<int> nums = {2,7,9,3,1};
    cout << rob(nums) << endl; // Output: 11
    


 return 0;
}