#include <bits/stdc++.h>
using namespace std;
vector<int> union1(vector<int> &arr, vector<int> &ar)
{
    set<int> st;
    int n1 = arr.size();
    int n2 = ar.size();

    for (int i = 0; i < n1; i++)
    {
        st.insert(arr[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        st.insert(ar[i]);
    }
    vector<int> ans;
    for(auto it : st){
        ans.push_back(it);
    }
    return ans;
}
vector<int> union2(vector<int> &arr, vector<int> &ar) {
    int n1 = arr.size();
    int n2 = ar.size();
    int i = 0, j = 0;
    vector<int> ans;

    while (i < n1 && j < n2) {
        if (arr[i] <= ar[j]) {
            if (ans.empty() || ans.back() != arr[i]) {
                ans.push_back(arr[i]);
            }
            i++;
        } else {
            if (ans.empty() || ans.back() != ar[j]) {
                ans.push_back(ar[j]);
            }
            j++;
        }
    }

    // Adding remaining elements from arr
    while (i < n1) {
        if (ans.empty() || ans.back() != arr[i]) {
            ans.push_back(arr[i]);
        }
        i++;
    }

    // Adding remaining elements from ar
    while (j < n2) {
        if (ans.empty() || ans.back() != ar[j]) {
            ans.push_back(ar[j]);
        }
        j++;
    }

    return ans;
}

int main(){
    vector<int> arr = {1, 2, 2, 3, 4};
    vector<int> ar = {2, 3, 5, 6};
    vector<int> unio = union2(arr,ar);
    for(auto it:unio ){
        cout<<it<<" ";
    }
    return 0;
}