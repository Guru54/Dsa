#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

void mergeTwo(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int l = low, r = mid + 1;

    while(l <= mid && r <= high) {
        if(arr[l] <= arr[r]) {
            temp.push_back(arr[l++]);
        } else {
            cnt += (mid - l + 1);
            temp.push_back(arr[r++]);
        }
    }

    while(l <= mid) temp.push_back(arr[l++]);
    while(r <= high) temp.push_back(arr[r++]);

    for(int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if(low >= high) return;

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    mergeTwo(arr, low, mid, high);
}

int main() {
    vector<int> arr = {3,1,2,4,1,5,2,6,4};

    mergeSort(arr, 0, arr.size() - 1);

    cout << cnt;
    return 0;
}
