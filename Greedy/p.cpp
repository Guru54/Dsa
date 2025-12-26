#include <bits/stdc++.h>
using namespace std;

long long makeSimilar(vector<int>& nums, vector<int>& target) {
    // Sort with custom comparator - odds first, then evens, both sorted internally
    auto comparator = [](int a, int b) {
        if (a % 2 == b % 2) return a < b;
        return a % 2 > b % 2; // odds come first (1 > 0 for %2)
    };
    
    sort(nums.begin(), nums.end(), comparator);
    sort(target.begin(), target.end(), comparator);
    
    long long ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        ans += abs(nums[i] - target[i]) / 2;
    }
    return ans / 2;
}
int getLeastFrequentDigit(int n) {
        int c =n;
      vector<int> hash(10,0);
        while(n){
            int digit = n%10;
            hash[digit]++;
            n/=10;
        }
        int ans = -1;
        int minFreq = INT_MAX;
        for(int i = 0; i < hash.size(); i++){
            if(hash[i] > 0 && hash[i] < minFreq){
                minFreq = hash[i];
                ans = i;
            }
        }
        
        return ans;
    }
int main() {
    // vector<int> nums = {1, 2, 5};
    // vector<int> target = {4, 1, 3};
    // cout << "minimum operation to make array similar is : " << makeSimilar(nums, target) << endl;
    int n = 723344511;
    
    cout<<endl<<getLeastFrequentDigit(n)<<endl;
    return 0;
}