#include <bits/stdc++.h>
using namespace std;

// Class containing the solution functions
class Solution {
public:

    // Function to calculate largest rectangle area in a histogram
    int largestRectangleArea(vector<int>& heights) {

        // Stack to store indices of histogram bars
        stack<int> st;

        // Variable to store the max area
        int maxArea = 0;

        // Add a sentinel zero height at the end
        heights.push_back(0);

        // Iterate through all bars
        for (int i = 0; i < heights.size(); i++) {

            // While current bar is smaller than the bar at stack top
            while (!st.empty() && heights[i] < heights[st.top()]) {

                // Pop the top height
                int height = heights[st.top()];
                st.pop();

                // Calculate width
                int width = st.empty() ? i : i - st.top() - 1;

                // Update max area
                maxArea = max(maxArea, height * width);
            }

            // Push current index
            st.push(i);
        }

        return maxArea;
    }

    // Function to find maximal rectangle in binary matrix
    int maximalRectangle(vector<vector<char>>& matrix) {

        // Return 0 if matrix is empty
        if (matrix.empty()) return 0;

        // Get number of columns
        int m = matrix[0].size();

        // Height array to build histogram row-wise
        vector<int> height(m, 0);

        // Variable to track max rectangle area
        int maxArea = 0;

        // Traverse each row of the matrix
        for (auto& row : matrix) {

            // Update histogram based on current row
            for (int i = 0; i < m; i++) {
                if (row[i] == '1') height[i]++;
                else height[i] = 0;
            }

            // Compute area for this histogram
            maxArea = max(maxArea, largestRectangleArea(height));
        }

        return maxArea;
    }
};

// Main driver function
int main() {

    // Sample matrix input
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    Solution sol;

    // Call the function and print result
    cout << sol.maximalRectangle(matrix) << endl;

    return 0;
}




// Maximum Rectangle Area with all 1's | DP on Rectangles: DP 55

// Mark as Completed

// 28


// Problem Statement: Given a m x n binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// Examples
// Input: matrix = [[1,0,1,0,0],[1,0,1,1,1],[1,1,1,1,1],[1,0,0,1,0]]


// Output: 6
// Explanation: The highlighted part depicts the rectangle with the largest area i.e. 6


// Input:  matrix = [[1]]
// Output: 1
// Explanation: In this case, there is only one rectangle with area 1.