#include <bits/stdc++.h>
using namespace std;

// ================================================
// 1️⃣ REMOVE DUPLICATES (SORTED ARRAY) - TWO POINTERS
// ================================================
int removedup_sorted(vector<int> &arr){
    int n = arr.size();
    int j = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] != arr[j]){
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1;
}

// ================================================
// 2️⃣ REMOVE DUPLICATES (UNSORTED ARRAY)
// Using unordered_set to keep only unique elements
// ================================================
int removedup_unsorted(vector<int> &arr){
    unordered_set<int> st;
    vector<int> temp;

    for(int x : arr){
        if(st.find(x) == st.end()){
            st.insert(x);
            temp.push_back(x);
        }
    }

    // Copy back
    for(int i = 0; i < temp.size(); i++) arr[i] = temp[i];

    return temp.size();
}

// ================================================
// 3️⃣ REMOVE DUPLICATES USING STL unique() FUNCTION
// Works only for sorted array
// ================================================
int removedup_stl(vector<int> &arr){
    auto it = unique(arr.begin(), arr.end());
    return it - arr.begin();
}

// ================================================
// MAIN FUNCTION WITH EXAMPLES
// ================================================
int main(){
    // Example for sorted array
    vector<int> arr1 = {1,1,2,2,2,3,3};
    int k1 = removedup_sorted(arr1);

    cout << "Sorted Array Result: ";
    for(int i = 0; i < k1; i++) cout << arr1[i] << " ";
    cout << " | k = " << k1 << "\n";

    // Example for unsorted array
    vector<int> arr2 = {3,1,2,3,4,1,2,5};
    int k2 = removedup_unsorted(arr2);

    cout << "Unsorted Array Result: ";
    for(int i = 0; i < k2; i++) cout << arr2[i] << " ";
    cout << " | k = " << k2 << "\n";

    // Example using STL unique()
    vector<int> arr3 = {1,1,2,2,3,3,3,4};
    int k3 = removedup_stl(arr3);

    cout << "STL unique() Result: ";
    for(int i = 0; i < k3; i++) cout << arr3[i] << " ";
    cout << " | k = " << k3 << "\n";

    return 0;
}
// Problem Statement: Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. The relative order of the elements should be kept the same.

// If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. It does not matter what you leave beyond the first k elements.

// Examples
// Input: arr[]=[1,1,2,2,2,3,3]
// Output: [1,2,3,_,_,_,_]
// Explanation: Total number of unique elements are 3, i.e[1,2,3] and Therefore return 3 after assigning [1,2,3] in the beginning of the array.

// Input: arr[]=[1,1,1,2,2,3,3,3,3,4,4]
// Output: [1,2,3,4,_,_,_,_,_,_,_]
// Explanation: Total number of unique elements are 4, i.e[1,2,3,4] and Therefore return 4 after assigning [1,2,3,4] in the beginning of the array.