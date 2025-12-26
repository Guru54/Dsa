#include <bits/stdc++.h>
using namespace std;

// ---------------- BRUTE FORCE ----------------
// Time: O(n²) | Space: O(1)
vector<int> brute(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        int cnt = 0;

        // Count frequency of arr[i]
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) cnt++;
        }

        // If more than n/3 and not already added
        if (cnt > n/3 && find(ans.begin(), ans.end(), arr[i]) == ans.end()) {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

// ---------------- BETTER (MAP) ----------------
// Time: O(n log n) | Space: O(n)
vector<int> better(vector<int> &arr) {
    int n = arr.size();
    map<int,int> mpp;
    vector<int> ans;

    for (auto &x : arr) mpp[x]++;

    for (auto &it : mpp) {
        if (it.second > n/3) {
            ans.push_back(it.first);
        }
    }
    return ans;
}

// ---------------- OPTIMAL (BOYER–MOORE n/3) ----------------
// Time: O(n) | Space: O(1)
vector<int> optimal(vector<int> &nums) {
    int c1 = 0, c2 = 0; 
    int vote1 = 0, vote2 = 0;

    // Step 1: Find candidates
    for (int x : nums) {
        if (x == c1) vote1++;
        else if (x == c2) vote2++;
        else if (vote1 == 0) {
            c1 = x;
            vote1 = 1;
        }
        else if (vote2 == 0) {
            c2 = x;
            vote2 = 1;
        }
        else {
            vote1--;
            vote2--;
        }
    }

    // Step 2: Count actual occurrences
    int cnt1 = 0, cnt2 = 0;
    for (int x : nums) {
        if (x == c1) cnt1++;
        if (x == c2) cnt2++;
    }

    // Step 3: Collect valid answers
    vector<int> ans;
    int n = nums.size();

    if (cnt1 > n/3) ans.push_back(c1);
    if (cnt2 > n/3 && c2 != c1) ans.push_back(c2);

    return ans;
}

// ---------------- MAIN ----------------
int main() {
    vector<int> nums = {3,2,3,2,2,1,1,1};

    cout << "Brute: ";
    for (int x : brute(nums)) cout << x << " ";
    cout << "\n";

    cout << "Better: ";
    for (int x : better(nums)) cout << x << " ";
    cout << "\n";

    cout << "Optimal: ";
    for (int x : optimal(nums)) cout << x << " ";
    cout << "\n";

    return 0;
}
