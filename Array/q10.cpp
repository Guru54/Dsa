// pascal triangle 
#include<bits/stdc++.h>
using namespace std;
int ncr(int n, int r){
    int res = 1;
    for(int i =0;i<r;i++){
        res = res*(n-i);
        res = res/(i+1);
    }
    return res;
                   
   
}
void printrow(int n){
    
    
    int ans =1;
    cout<<ans<<" ";
    for(int i =1;i<n;i++){
        ans = ans *(n-i);
        ans = ans / i;
        cout<<ans<<" ";
    }

}
vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //Store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        vector<int> tempLst; // temporary list
        for (int col = 1; col <= row; col++) {
            tempLst.push_back(ncr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}

int main(){
       cout<<ncr(5,3)<<endl;  
       int n = 5;
       vector<vector<int>> ans = pascalTriangle(n);
       for (auto it : ans) {
           for (auto ele : it) {
               cout << ele << " ";
           }
           cout << "\n";
       }
 return 0;
}