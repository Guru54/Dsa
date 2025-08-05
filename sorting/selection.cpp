#include<bits/stdc++.h>
using namespace std;
void  selection(vector<int> &arr){
    int n = arr.size();
    for(int i =0;i<n-1;i++){
        int mini = i;
        for(int j=i+1;j<n;j++){
            if(arr[mini]>arr[j]){
                mini = j;
            
            }
                       
        }   
        swap(arr[mini],arr[i]);      
    }
}
int main(){
    vector<int> arr= {5,2,32,3,23};
    selection(arr);

     for(int i =0;i<5;i++){
         cout<<arr[i]<<" ";           
     }    
 return 0;
}