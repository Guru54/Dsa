#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

void mergeTwo(vector<int>& arr, int low, int mid, int high) {
    int j = mid + 1;


    for(int i = low; i <= mid; i++) {
        while(j <= high && arr[i] > 2LL * arr[j]) {
            j++;
        }
        cnt += (j - (mid + 1));
    }

    // normal merge
    vector<int> temp;
    int l = low, r = mid + 1;

    while(l <= mid && r <= high) {
        if(arr[l] <= arr[r]) temp.push_back(arr[l++]);
        else temp.push_back(arr[r++]);
    }

    while(l <= mid) temp.push_back(arr[l++]);
    while(r <= high) temp.push_back(arr[r++]);

    for(int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int>& arr, int low, int high) {
    if(low >= high) return;

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    mergeTwo(arr, low, mid, high);
}

int reversePairs(vector<int>& nums) {
    cnt = 0;
    mergeSort(nums, 0, nums.size() - 1);
    return cnt;
}
int main() {
    vector<int> arr = {1,3,2,3,1};

    int result = reversePairs(arr);

    cout << result;
    return 0;
}