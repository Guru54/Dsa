#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        char target = s[n-1];
        int ans = 0;

        for(int i = 0; i < n - 1; i++) {
            if(s[i] != target) ans++;
        }

        cout << ans << endl;
    }   
 return 0;
}

// You are given a string s
//  of length n
// , consisting of lowercase letters.

// In one operation, you can select an integer i
//  such that 1≤i<n
//  and change si
//  into si+1
// .

// What is the minimum number of operations needed to make every character the same? It can be proved that this is always possible.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤20
// ). The description of the test cases follows.

// The first line of each test case contains an integer n
//  (2≤n≤100
// ) — the length of the string.

// The following line contains a string s
//  of length n
// , consisting of lowercase letters.

// It is guaranteed that the sum of n
//  over all test cases does not exceed 100
// .

// Output
// For each test case, output a single integer — the minimum number of operations needed to make every character the same.

// Example
// InputCopy
// 5
// 3
// qwq
// 2
// aa
// 4
// test
// 5
// abbac
// 6
// abcabc
// OutputCopy
// 1
// 0
// 2
// 4
// 4
// Note
// In the first test case, you can change s2
//  to s3
//  using 1
//  operation to reach the goal.

// In the third test case, you can change s3
//  to s4
//  and then change s2
//  to s3
// , using 2
//  operations in total. It can be proved that the answer is not less than 2
// .



