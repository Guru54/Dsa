#include<bits/stdc++.h>
using namespace std;



    long long maxScore(vector<int>& nums, string s) {
        int n = nums.size();
        vector<int> ones; 
        
  
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ones.push_back(i);
            }
        }
        
        if (ones.empty()) return 0;
        
        long long score = 0;
        set<pair<int, int>> available; 
        

        int prevBoundary = -1;
        
        for (int onePos : ones) {

            for (int i = prevBoundary + 1; i <= onePos; i++) {
                available.insert({nums[i], i});
            }
            
  
            auto it = available.rbegin(); 
            score += it->first;
            

            available.erase(prev(available.end()));
            
            prevBoundary = onePos;
        }
        
        return score;
    }



int main(){
  string  m = "my string ";

   vector<int> nums  = {8,8,5,3,2,9,8,1,5,6};
   string s = "1100100101";
   cout<<maxScore(nums,s);
 
   
 return 0;
}