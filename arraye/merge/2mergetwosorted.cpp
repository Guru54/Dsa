#include <bits/stdc++.h>
using namespace std;

//
// =============================================================
//                 MERGE SORTED ARRAY — ALL 3 APPROACHES
// =============================================================
//

// ---------------- BRUTE FORCE (O((m+n) log(m+n))) ----------------
// Copy all elements to temp array → sort → copy back
void mergeBrute(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> temp;

    // push nums1 valid elements
    for(int i = 0; i < m; i++)
        temp.push_back(nums1[i]);

    // push nums2 elements
    for(int i = 0; i < n; i++)
        temp.push_back(nums2[i]);

    sort(temp.begin(), temp.end());

    // copy back into nums1
    for(int i = 0; i < m + n; i++)
        nums1[i] = temp[i];
}


// ---------------- BETTER (O(m+n) , extra space) ----------------
// Standard merge procedure using a temp vector (Merge Sort style)
void mergeBetter(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> temp;
    int i = 0, j = 0;

    while(i < m && j < n) {
        if(nums1[i] < nums2[j])
            temp.push_back(nums1[i++]);
        else
            temp.push_back(nums2[j++]);
    }

    while(i < m)
        temp.push_back(nums1[i++]);

    while(j < n)
        temp.push_back(nums2[j++]);

    // copy back
    for(int k = 0; k < m + n; k++)
        nums1[k] = temp[k];
}


// ---------------- OPTIMAL (O(m+n), O(1) space) ----------------
// Merge from the back of nums1, in-place
void mergeOptimal(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;           // pointer at end of nums1’s valid part
    int j = n - 1;           // pointer at end of nums2
    int k = m + n - 1;       // final position in nums1

    while(i >= 0 && j >= 0) {
        if(nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }

    // if nums2 still has elements remaining
    while(j >= 0)
        nums1[k--] = nums2[j--];
}


// =============================================================
//                           MAIN
// =============================================================

int main() {

    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3, n = 3;


    cout << "Brute:\n";
    vector<int> a = nums1;
    mergeBrute(a, m, nums2, n);
    for(int x : a) cout << x << " ";
    cout << "\n\n";


    cout << "Better:\n";
    vector<int> b = nums1;
    mergeBetter(b, m, nums2, n);
    for(int x : b) cout << x << " ";
    cout << "\n\n";


    cout << "Optimal:\n";
    vector<int> c = nums1;
    mergeOptimal(c, m, nums2, n);
    for(int x : c) cout << x << " ";
    cout << "\n";

    return 0;
}
