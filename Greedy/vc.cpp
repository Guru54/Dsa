#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;


    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);
        }

       
        vector<int> seen;
        long long ans = 0;

        for (int i = 0; i <= n; i++) {
    
            int smaller = lower_bound(seen.begin(), seen.end(), prefix[i]) - seen.begin();
            ans += smaller;

          
            seen.insert(lower_bound(seen.begin(), seen.end(), prefix[i]), prefix[i]);
        }

        return ans;
    }
    int longestNonDecreasingSubarray(vector<int>& nums) {

        if (nums.size() <= 2) return nums.size();

        int maxLen= 1;
        int curr= 1;
        int prev= -1; 

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= nums[i - 1]) {
                curr++;
            } else {
            
                if (prev == -1 || nums[i] >= nums[prev - 1]) {
                    curr = i - prev;
                } else {
                    curr = 1;
                }
                prev = i;
            }
            maxLen = max(maxLen, curr);
        }

        return maxLen;
    }



int main(){
   
    vector<int> nums = {1,2,2,3};
    int target = 2;
    cout << countMajoritySubarrays(nums, target) << endl;
    return 0;
}