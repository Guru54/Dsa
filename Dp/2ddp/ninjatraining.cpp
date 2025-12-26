#include<bits/stdc++.h>
using namespace std;
int f(int day,int last,vector<vector<int>>&points){
    if(day == 0){
        int maxi = INT_MIN;
        for(int task = 0;task<3;task++){
            if(task!=last){
                maxi = max(points[0][task],maxi);
            }
        }
        return maxi;
    }
    int maxi = 0;
    for(int i = 0;i<3;i++){
        if(i!=last){
            int point = points[day][i] + f(day-1,i,points);
            maxi=max(point,maxi);
        }
    }
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points){
    return f(n-1,3,points);
}

int ninjaT(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n,vector<int>(4,0));
    // for(int last = 0; last < 4; ++last){
    //     dp[0][last] = 0;
    //     for(int task = 0; task < 3; ++task){
    //         if(task != last) dp[0][last] = max(dp[0][last], points[0][task]);
    //     }
    // }
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]); 
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    for(int day = 1; day < n; ++day){
        for(int last = 0; last < 4; ++last){
            dp[day][last] = 0;
            for(int task = 0; task < 3; ++task){
                if(task != last){
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[n-1][3];
}
int ninja(int n,vector<vector<int>>&points){
    vector<int> prev(4,0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]); 
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
    for(int day = 1; day < n; ++day){
        vector<int> curr(4,0);
        for(int last = 0; last < 4; ++last){
            curr[last] = 0;
            for(int task = 0; task < 3; ++task){
                if(task != last){
                    int point = points[day][task] + prev[task];
                    curr[last] = max(curr[last], point);
                }
            }
        }
        prev = curr;
    }
    return prev[3];
}
int main(){
          vector<vector<int>> points = {{1,2,5},{3,1,1},{3,3,3}};
          cout << ninjaTraining(3,points) << endl; // Output: 11 
 return 0;
}
// writing the problem statement
/* Ninja Training Problem Statement:
You are given a number of days 'n' and a 2D vector 'points' where points[i][j] represents the points you can earn by performing task 'j' on day 'i'. There are three tasks (0, 1, and 2) available each day. However, you cannot perform the same task on two consecutive days.
Your goal is to maximize the total points earned over 'n' days by choosing tasks such that no two consecutive days have the same task.
Your task is to implement a function 'ninjaTraining' that takes the number of days 'n' and the 2D vector 'points' as input and returns the maximum points that can be earned by following the above rules.
Time Complexity: O(n*4*3) = O(n)
Space Complexity: O(n*4) for the dp table, O(1) for the optimized version.  
example:
Input:  n = 3
        points = [[1,2,5],
                  [3,1,1],
                  [3,3,3]] 
Output: 11
Explanation:
Day 0: Choose task 2 (5 points)
Day 1: Choose task 0 (3 points) 
Day 2: Choose task 1 (3 points)
Total points = 5 + 3 + 3 = 11

*/