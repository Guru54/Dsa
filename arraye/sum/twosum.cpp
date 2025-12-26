#include<bits/stdc++.h>
using namespace std;

// ---------------- BRUTE FORCE ----------------
vector<int> twosum(vector<int> &arr, int target) {
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[i] + arr[j] == target) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

// ---------------- BETTER (Hash Map) ----------------
vector<int> two(vector<int> &arr, int target) {
    map<int,int> mpp;

    for(int i = 0; i < arr.size(); i++) {

        int rem = target - arr[i];
        
        if(mpp.find(rem) != mpp.end()) {
            return {mpp[rem], i};
        }

        mpp[arr[i]] = i;
    }
    return {-1, -1};
}

// ---------------- OPTIMAL (Two Pointer) ----------------
vector<int> twos(vector<int> &arr, int target) {
    vector<pair<int,int>> v(arr.size());

    for(int i = 0; i < arr.size(); i++) {
        v[i] = {arr[i], i};
    }

    sort(v.begin(), v.end());

    int left = 0, right = arr.size() - 1;

    while(left < right) {
        int sum = v[left].first + v[right].first;

        if(sum == target) {
            return {v[left].second, v[right].second};
        }
        else if(sum < target) left++;
        else right--;
    }

    return {-1, -1};
}

int main() {
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;

    vector<int> ans = twos(arr, target);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}

// question - 
// Problem Statement: Given an array of integers arr[] and an integer target.

// 1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.

// 2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

// Examples

// Input: N = 5, arr[] = {2,6,5,8,11}, target = 14
// Output : YES
// Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for first variant for second variant output will be : [1,3].

// Input: N = 5, arr[] = {2,6,5,8,11}, target = 15
// Output : NO.
// Explanation: There exist no such two numbers whose sum is equal to the target. 