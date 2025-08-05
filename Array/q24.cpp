#include<bits/stdc++.h>
using namespace std;

void merg(vector<int> &arr,int low ,int mid,int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left<=mid&&right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        
            temp.push_back(arr[left]);
            left++;
        
    }
    while(right<=high){
        
            temp.push_back(arr[right]);
                right++;
           
        }
    
    for(int i =low;i<=high;i++){
        arr[i] = temp[i-low];
                   
    }
}
int countPairs(vector<int> &arr,int low ,int mid,int high){

    int right = mid + 1;
    int cnt = 0;
    for(int i = low; i<= mid;i++){
        while(right<=high&&arr[i]> 2*arr[right]) right ++;
        cnt+=(right- (mid+1));
    }
    return cnt;
}
int merge_sort(vector<int> &arr, int low , int high){
    int cnt = 0;
   // int n = arr.size();
   if(low >= high) return cnt;
    int mid = (low +high)/2;
   cnt+= merge_sort(arr,low ,mid);
   cnt+= merge_sort(arr,mid+1,high);
   cnt+= countPairs(arr,low ,mid,high);
    merg(arr,low,mid,high);
return cnt;
}
int main(){
    vector<int> a = {40,25,19,12,9,6,2};
  int n  = a.size();
   cout<<" the no. of reverse pairs is : " <<merge_sort(a, 0, n - 1);
   
    
 return 0;
}