#include <bits/stdc++.h>
using namespace std;

// int KthLargestSumOfSubarrays(vector<int> arr, int K) {
//     vector<int> sumStore;
//     int size = arr.size();

//     for(int i=0; i<size; i++) {
//         int temp = 0;
//         for(int j=i; j<size; j++) {
//             temp += arr[j];
//             sumStore.push_back(temp);
//         }
//     }

//     sort(sumStore.begin(), sumStore.end());
//     return sumStore[sumStore.size() - K];
// }

int KthLargestSumOfSubarrays(vector<int> arr, int K) {
    priority_queue<int, vector<int>, greater<int> > sumStore;
    int size = arr.size();

    for(int i=0; i<size; i++) {
        int temp = 0;
        for(int j=i; j<size; j++) {
            temp += arr[j];
            
            if(sumStore.size() < K) {
                sumStore.push(temp);
            } else {
                if(temp > sumStore.top()) {
                    sumStore.pop();
                    sumStore.push(temp);
                }
            }
        }
    }

    return sumStore.top();
}

int main() {
    vector<int> arr;

    cout << "Enter the elements of array (-1 to stop) : ";
    int temp;
    cin >> temp;
    do {
        arr.push_back(temp);
        cin >> temp;
    } while(temp != -1);

    int K;
    cout << "Enter the value of K : ";
    cin >> K;

    int largestSum = KthLargestSumOfSubarrays(arr, K);

    cout << "The kth largest sum of subarrays : " << largestSum;

    return 0;
}


// Given an array arr[] of size n, find the sum of the K-th largest sum among all contiguous subarrays. In other words, identify the K-th largest sum from all possible subarrays and return it.

// Examples:

// Input: arr[] = [3, 2, 1], k = 2 
// Output: 5
// Explanation: The different subarray sums we can get from the array are = [6, 5, 3, 2, 1]. Where 5 is the 2nd largest.
// Input: arr[] = [2, 6, 4, 1], k = 3
// Output: 11
// Explanation: The different subarray sums we can get from the arrayare = [13, 12, 11, 10, 8, 6, 5, 4, 2, 1]. Where 11 is the 3rd largest.
// Constraints:
// 1 <= arr.size() <= 1000
// 1 <= k <= (n*(n+1))/2
// -105 <= arr[i] <= 105

