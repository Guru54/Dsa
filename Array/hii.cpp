#include <bits/stdc++.h>
using namespace std;
void printallsub(vector<int> & arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum =0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
                cout<<arr[k]<<" ";
            }
            cout<<" sum = "<<sum<<endl;
        }
    }
}
int countsub(vector<int> &arr, int k)
{
    int n = arr.size();
    map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];
        int remove = preSum - k;
        cnt += mpp[remove];

        mpp[preSum]++;
    }
    return cnt;
}
int main()
{
    vector<int> arr = {3, -3, 1, 1, 1};
    int k = 3;
    printallsub(arr);
    cout << "the number of subarrays with sum as k is : " << countsub(arr, k);
    return 0;
}