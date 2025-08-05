//majority element n/2
#include<bits/stdc++.h>
using namespace std;
int maj1(vector<int> &arr){
    int n = arr.size();
    int cnt = 1;
    int el = arr[0];

    for(int i =1;i<n;i++){
        if(cnt ==0)  {
            cnt =1;
            el = arr[i];
        }else if(el==arr[i]) {
            cnt++;


        }  else {
            cnt--;
        }     
    }
    return el;
}
vector<int> major(vector<int> &arr){
    int n = arr.size();
    int cnt1 = 0;
    int cnt2 = 0;
    int el1;
    int el2;
    for(int i =0;i<n-1;i++){
       if(cnt1==0&&arr[i]!=el2) {
        cnt1 = 1;
        el1 = arr[i];

       } else if(cnt2==0&&arr[i]!=el1){
        cnt2 = 1;
        el2 = arr[i];
       }else if (el1==arr[i])cnt1++;
       else if(el2==arr[i])  cnt2++;
       else{
        cnt1--;
        cnt2--;
       }    
    }
    vector<int> ls; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == el1) cnt1++;
        if (arr[i] == el2) cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini) ls.push_back(el1);
    if (cnt2 >= mini) ls.push_back(el2);

    // Uncomment the following line
    // if it is told to sort the answer array:
    // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);

    return ls;
}
int main(){
  vector<int> arr = {1,1,1,1,1,1,2,2,3,3,24};
cout<<maj1(arr)<<endl;
vector<int> arr1 = {11, 33, 33, 11, 33, 11};
vector<int> ans = major(arr1);
cout << "The majority elements are: ";
for (auto it : ans)
    cout << it << " ";
cout << "\n";
 return 0;
}