#include <bits/stdc++.h>
using namespace std;

// ---------------------- Memoization ----------------------
int f(int i, int j, vector<vector<int>> &arr, int n, vector<vector<int>> &dp) {
    if (i == n - 1) return arr[i][j];
    if (dp[i][j] != -1) return dp[i][j];

    int b = arr[i][j] + f(i + 1, j, arr, n, dp);     // bottom
    int d = arr[i][j] + f(i + 1, j + 1, arr, n, dp); // diagonal

    return dp[i][j] = min(b, d);
}

int minimumTotal(vector<vector<int>> &triangle) { // memoization call
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f(0, 0, triangle, n, dp);
}

// ---------------------- Tabulation ----------------------
int minimum(vector<vector<int>> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 1e9));

    // base case → last row same as triangle’s last row
    for (int j = 0; j < arr[n - 1].size(); j++) {
        dp[n - 1][j] = arr[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < arr[i].size(); j++) {
            int b = arr[i][j] + dp[i + 1][j];
            int d = arr[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(b, d);
        }
    }

    return dp[0][0];
}

// ---------------------- Space Optimization ----------------------
int mini(vector<vector<int>> &arr) {
    int n = arr.size();
    vector<int> prev = arr[n - 1]; // last row

    for (int i = n - 2; i >= 0; i--) {
        vector<int> curr(arr[i].size(), 0);
        for (int j = 0; j < arr[i].size(); j++) {
            int b = arr[i][j] + prev[j];
            int d = arr[i][j] + prev[j + 1];
            curr[j] = min(b, d);
        }
        prev = curr;
    }

    return prev[0];
}

// ---------------------- Main ----------------------
int main() {
    vector<vector<int>> arr = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    cout << "Memoization: " << minimumTotal(arr) << endl;
    cout << "Tabulation: " << minimum(arr) << endl;
    cout << "Space Optimized: " << mini(arr) << endl;

    return 0;
}
