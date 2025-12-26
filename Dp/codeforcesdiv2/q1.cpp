// An array is called balanced if every integer x
//  that occurs at least once, occurs exactly x
//  times in the array. For example, [1,4,2,4,4,4,2]
//  is balanced, but [2]
//  and [2,2,2]
//  are not.

// You are given an array a
//  of n
//  elements, [a1,a2,…,an]
// . The array may not be balanced currently, and you can delete some elements to make it balanced. What is the minimum number of elements you need to delete to make the array balanced?

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤500
// ). The description of the test cases follows.

// The first line of each test case contains an integer n
//  (1≤n≤100
// ) — the size of the array a
// .

// The second line of each test case contains n
//  integers a1,a2,…,an
//  (0≤ai≤n
// ) — the elements of the array a
// .

// Note that there are no constraints on the sum of n
//  over all test cases.

// Output
// For each test case, output a single line containing an integer: the minimum number of elements you should remove from the array to make it balanced.
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        map<int,int> freq;
        for(int i=0;i<n;i++){
            freq[a[i]]++;
        }
        int ans=n;
        for(int x=1;x<=n;x++){
            int curr_del=0;
            for(auto it:freq){
                if(it.first<x){
                    curr_del+=it.second;
                }
                else if(it.first==x){
                    curr_del+=abs(it.second - x);
                }
                else{
                    curr_del+=it.second;
                }
            }
            ans=min(ans,curr_del);
        }
        cout<<ans<<endl;
    }
    return 0;
}