#include <bits/stdc++.h>
using namespace std;

//
// =============================================================
//                      4 SUM ALL APPROACHES
// =============================================================
//

// ---------------- BRUTE FORCE 4 SUM (O(N^4)) ----------------
vector<vector<int>> fourSumBrute(vector<int> &arr, int target) {
    int n = arr.size();
    set<vector<int>> st;

    for (int a = 0; a < n; a++) {
        for (int b = a + 1; b < n; b++) {
            for (int c = b + 1; c < n; c++) {
                for (int d = c + 1; d < n; d++) {

                    if (arr[a] + arr[b] + arr[c] + arr[d] == target) {
                        vector<int> temp = {arr[a], arr[b], arr[c], arr[d]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
}

// ---------------- BETTER (Fix 2 + Two Sum HashSet) ----------------
// Complexity: O(N^3)
vector<vector<int>> fourSumBetter(vector<int> &arr, int target) {
    int n = arr.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            unordered_set<int> hashset;

            for (int k = j + 1; k < n; k++) {

                int fourth = target - (arr[i] + arr[j] + arr[k]);

                if (hashset.count(fourth)) {
                    vector<int> temp = {arr[i], arr[j], arr[k], fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }

                hashset.insert(arr[k]);
            }
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
}

// ---------------- OPTIMAL 4 SUM (Sorting + Two Pointers) ----------------
// Complexity: O(N^3)
vector<vector<int>> fourSumOptimal(vector<int> &nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n; i++) {

        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < n; j++) {

            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            int left = j + 1, right = n - 1;

            while (left < right) {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum < target)
                    left++;
                else if (sum > target)
                    right--;
                else {

                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++; right--;

                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }
    }

    return res;
}

//
// =============================================================
//                           MAIN
// =============================================================
//

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    cout << "Brute 4-Sum:\n";
    auto a = fourSumBrute(nums, target);
    for (auto &v : a) { for (int x : v) cout << x << " "; cout << endl; }

    cout << "\nBetter 4-Sum:\n";
    auto b = fourSumBetter(nums, target);
    for (auto &v : b) { for (int x : v) cout << x << " "; cout << endl; }

    cout << "\nOptimal 4-Sum:\n";
    auto c = fourSumOptimal(nums, target);
    for (auto &v : c) { for (int x : v) cout << x << " "; cout << endl; }

    return 0;
}
//problem link: https://leetcode.com/problems/4sum/
//problem statement: Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//pre-requisite: 2 Sum Problem, 3 Sum Problem