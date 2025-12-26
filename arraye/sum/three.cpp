#include <bits/stdc++.h>
using namespace std;

//
// ---------------- BRUTE FORCE (O(N^3)) ----------------
//
vector<vector<int>> threeSumBrute(vector<int> &arr) {
    int n = arr.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {

                if (arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
}

//
// ---------------- BETTER (O(N^2) using Hash Set) ----------------
//
vector<vector<int>> threeSumBetter(vector<int> &arr) {
    int n = arr.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        unordered_set<int> hashset;

        for (int j = i + 1; j < n; j++) {

            int third = -(arr[i] + arr[j]);

            if (hashset.count(third)) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }

            hashset.insert(arr[j]);
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
}

//
// ---------------- OPTIMAL (Two Pointer - O(N^2)) ----------------
//
vector<vector<int>> threeSumOptimal(vector<int> &nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right) {

            int sum = nums[i] + nums[left] + nums[right];

            if (sum < 0)
                left++;
            else if (sum > 0)
                right--;
            else {
                ans.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1])
                    left++;
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }
        }
    }

    return ans;
}

//
// ---------------- MAIN FUNCTION ----------------
//
int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    cout << "Brute Force Approach:\n";
    auto bruteAns = threeSumBrute(nums);
    for (auto &v : bruteAns) {
        for (int x : v) cout << x << " ";
        cout << endl;
    }

    cout << "\nBetter Approach:\n";
    auto betterAns = threeSumBetter(nums);
    for (auto &v : betterAns) {
        for (int x : v) cout << x << " ";
        cout << endl;
    }

    cout << "\nOptimal Approach:\n";
    auto optimalAns = threeSumOptimal(nums);
    for (auto &v : optimalAns) {
        for (int x : v) cout << x << " ";
        cout << endl;
    }

    return 0;
}
//Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

// Pre-requisite: 2 Sum Problem

// Examples

// Example 1: 
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: Out of all possible unique triplets possible, [-1,-1,2] and [-1,0,1] satisfy the condition of summing up to zero with i!=j!=k


// Example 2:
// Input: nums=[-1,0,1,0]
// Output: Output: [[-1,0,1],[-1,1,0]]
// Explanation: Out of all possible unique triplets possible, [-1,0,1] and [-1,1,0] satisfy the condition of summing up to zero with i!=j!=k