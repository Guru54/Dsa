#include<bits/stdc++.h>
using namespace std;
//get r,cell value in pascal triangle
int ncr(int n,int r){
    long long ans = 1;
    for(int i = 1;i<=r;i++){
        ans = ans * (n - i + 1) / i;
    }
    return (int)ans;
}
int pascalTriangle(int row, int col){
    return ncr(row - 1,min(col - 1, row - col));
}

//get nth row of pascal triangle
vector<int> getRow(int rowIndex) {
    vector<int> ansrow;
    //brute
    // for(int i = 0;i<=rowIndex;i++){
    //     ans.push_back(ncr(rowIndex,i));
    // }

    //optimal
    long long ans = 1;
    ansrow.push_back(1); // first element is always 1
    for(int col = 1; col <= rowIndex; col++){
        ans = ans * (rowIndex - col + 1) / (col);
        ansrow.push_back((int)ans);
        ansrow.push_back((int)ans);
        ansrow.push_back((int)ans);
    }
    return ansrow;
}

int main(){
              
 return 0;
}