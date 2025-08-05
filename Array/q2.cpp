//unique elements 

#include<bits/stdc++.h>
using namespace std;

int remover(vector<int> & arr){

    int n= arr.size();
    int j=0;
    for(int i=1;i<n;i++){
     if(arr[i]!=arr[j]){
         j++;
         arr[j] =arr[i];

     }
    }
    return j+1;
}
int main(){  
  vector<int> arr = { 2,2,4,4,3,3};

 cout<< remover(arr);
  cout<<endl;
       for(int i =0;i<arr.size();i++){
        cout<<arr[i]<<" ";
       }
 return 0;
}