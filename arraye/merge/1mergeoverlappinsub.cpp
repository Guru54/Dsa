#include <bits/stdc++.h>
using namespace std;

//
// =============================================================
//                  MERGE INTERVALS — ALL APPROACHES
// =============================================================
//

// ---------------- BRUTE FORCE (O(N^2)) ----------------
// Compare every interval with every other and merge if overlapping.
// Use a visited array to avoid repeating.
vector<vector<int>> mergeBrute(vector<vector<int>> arr) {
    int n = arr.size();
    vector<bool> vis(n, false);
    vector<vector<int>> ans;

    for(int i = 0; i < n; i++){
        if(vis[i]) continue;

        int start = arr[i][0];
        int end   = arr[i][1];

        for(int j = 0; j < n; j++){
            if(i == j) continue;

            // if overlapping
            if(!(arr[j][0] > end || arr[j][1] < start)){
                start = min(start, arr[j][0]);
                end   = max(end, arr[j][1]);
                vis[j] = true;
            }
        }

        ans.push_back({start, end});
    }

    // sort output for correct ordering
    sort(ans.begin(), ans.end());
    return ans;
}


// ---------------- BETTER APPROACH (O(N log N)) ----------------
// Sort + merge by extending intervals
vector<vector<int>> mergeBetter(vector<vector<int>> arr) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    ans.push_back(arr[0]);

    for(int i = 1; i < arr.size(); i++){
        if(arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    return ans;
}


// ---------------- OPTIMAL (Same as better, clean code) ----------------
vector<vector<int>> mergeOptimal(vector<vector<int>> arr) {

    if(arr.empty()) return {};

    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    int start = arr[0][0];
    int end   = arr[0][1];

    for(int i = 1; i < arr.size(); i++){

        if(arr[i][0] > end){
            ans.push_back({start, end});
            start = arr[i][0];
            end   = arr[i][1];
        }
        else{
            end = max(end, arr[i][1]);
        }
    }

    ans.push_back({start, end});
    return ans;
}


// =============================================================
//                           MAIN
// =============================================================

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    cout << "Brute:\n";
    auto a = mergeBrute(intervals);
    for(auto &v : a){ for(int x : v) cout << x << " "; cout << endl; }

    cout << "\nBetter:\n";
    auto b = mergeBetter(intervals);
    for(auto &v : b){ for(int x : v) cout << x << " "; cout << endl; }

    cout << "\nOptimal:\n";
    auto c = mergeOptimal(intervals);
    for(auto &v : c){ for(int x : v) cout << x << " "; cout << endl; }

    return 0;
}


// Problem Statement: Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Examples
// Input : intervals=[[1,3],[2,6],[8,10],[15,18]]
// Output : [[1,6],[8,10],[15,18]]
// Explanation : Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6] intervals.

// Input : [[1,4],[4,5]]
// Output :  [[1,5]]
// Explanation :  Since intervals [1,4] and [4,5] are overlapping we can merge them to form [1,5].