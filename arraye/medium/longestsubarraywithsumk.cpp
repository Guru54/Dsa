#include<bits/stdc++.h>
using namespace std;
// bruteforce
vector<int> longestSubarrayBrute(vector<int> &arr, int k) {
    int n = arr.size();
    int maxlen = 0;
    int startIndex = -1, endIndex = -1;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum == k && (j - i + 1) > maxlen) {
                maxlen = j - i + 1;
                startIndex = i;
                endIndex = j;
            }
        }
    }

    if (startIndex == -1) return {}; // no subarray found
    return vector<int>(arr.begin() + startIndex, arr.begin() + endIndex + 1);
}

    // Function to get the length of longest subarray with sum equal to k
    int getLongestSubarray(vector<int>& a, int k) {
        int n = a.size();
        map<int, int> preSumMap; // prefixSum -> earliest index
        int sum = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            sum += a[i]; // compute running prefix sum

            // Case 1: If the entire sum from 0 to i is equal to k
            if (sum == k) {
                maxLen = max(maxLen, i + 1);
            }

            // Case 2: If (sum - k) is seen before, a valid subarray exists
            int rem = sum - k;
            if (preSumMap.find(rem) != preSumMap.end()) {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }

            // Only store the first occurrence of each prefix sum
            if (preSumMap.find(sum) == preSumMap.end()) {
                preSumMap[sum] = i;
            }
        }

        return maxLen;
    }

    //sliding window works only for positive
    int longestSubarraySliding(vector<int> &arr, int k) {
    int n = arr.size();
    int left = 0;
    int sum = 0;
    int maxlen = 0;

    for (int right = 0; right < n; right++) {
        sum += arr[right];

        // shrink window if sum exceeds k
        while (sum > k && left <= right) {
            sum -= arr[left];
            left++;
        }

        // check if sum is exactly k
        if (sum == k) {
            maxlen = max(maxlen, right - left + 1);
        }
    }

    return maxlen;
}

    int main(){
           vector<int> arr = {10, 5, 2, 7, 1, 9};
           int k = 15;
           cout<<getLongestSubarray(arr,k);
 return 0;
}




// Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

// Examples
// Example 1:
// Input Format: N = 3, k = 5, array[] = {2,3,5}
// Result: 2
// Explanation: The longest subarray with sum 5 is {2, 3}. And its length is 2.

// Example 2:
// Input Format: N = 3, k = 1, array[] = {-1, 1, 1}
// Result: 3
// Explanation: The longest subarray with sum 1 is {-1, 1, 1}. And its length is 3.