// rearange the elememts by sign 
#include<bits/stdc++.h>
using namespace std;
void re1(vector<int> &arr){
    int n= arr.size();
    int pos = 0;
    int neg = 1;
    int nums[n];
    for(int i =0;i<n;i++){
        if(arr[i]<0)  {
            nums[neg]= arr[i];
            neg+=2;
        } else{
            nums[pos] = arr[i];
            pos+=2;
        }        
    }
    for(int i =0;i<n;i++){
        cout<<nums[i]<<" "  ;     
    }        
}
int main(){
  vector<int> arr= { 3,1,-2,-5,2,-4}; 
  int n = arr.size();
  re1(arr);
 return 0;
}