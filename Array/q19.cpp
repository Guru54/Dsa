// longest consequetive sequence 
#include<bits/stdc++.h>
using namespace std;
//optimal
int longest(vector<int> &arr){
    int n = arr.size();
    if (n== 0)return 0;

    int longest =1;
    unordered_set<int> st;
    for(int i =0;i<n;i++){
        st.insert(arr[i]);          
    }
    for(auto it : st){
         
        if(st.find(it-1) == st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x+1)!= st.end()){
                x = x+1;
                cnt = cnt+1;
            }
            longest = max(longest,cnt);

        }
                   
    }
    return longest;
//     Time Complexity: O(N) + O(2*N) ~ O(3*N), where N = size of the array.
// Reason: O(N) for putting all the elements into the set data structure. After that for every starting element, we are finding the consecutive elements. Though we are using nested loops, the set will be traversed at most twice in the worst case. So, the time complexity is O(2*N) instead of O(N2).

// Space Complexity: O(N), as we are using the set data structure to solve this problem.

// Note: The time complexity is computed under the assumption that we are using unordered_set and it is taking O(1) for the set operations. 

// If we consider the worst case the set operations will take O(N) in that case and the total time complexity will be approximately O(N2). 
// And if we use the set instead of unordered_set, the time complexity for the set operations will be O(logN) and the total time complexity will be O(NlogN).
}
//brute approach : traverse the array and use linear search to search the element 
//better 
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;

    //sort the array:
    sort(a.begin(), a.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    //find longest sequence:
    for (int i = 0; i < n; i++) {
        if (a[i] - 1 == lastSmaller) {
            //a[i] is the next element of the
            //current sequence.
            cnt += 1;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller) {
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;

}
int main(){
  vector<int> arr = { 102,4,100,1,101,3,2,1,1} ;  
  cout<<"the longest consequitive sequence : = "<<longest(arr) ;

 return 0;
}