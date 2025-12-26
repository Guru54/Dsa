#include<bits/stdc++.h>
using namespace std;
void movezersoend(vector<int> &arr){
    int n = arr.size();
    int ind = -1;
    for(int i = 0;i<arr.size();i++){
        if(arr[i]==0){
            ind = i;
            break;
        }
    }
    if(ind== -1)return;
    for(int i = ind+1;i<arr.size();i++){
        if(arr[i]!=0){
            swap(arr[i],arr[ind]);
            ind++;
        }
    }
}
int main(){
           
 return 0;
}