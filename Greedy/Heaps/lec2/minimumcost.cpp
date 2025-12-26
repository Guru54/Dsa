#include <bits/stdc++.h>
using namespace std;

int minimumCost(vector<int> arr)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int cost = 0;

    for (auto i : arr)
    {
        minHeap.push(i);
    }

    while (minHeap.size() > 1)
    {
        int a = minHeap.top();
        minHeap.pop();

        int b = minHeap.top();
        minHeap.pop();

        int sum = a + b;
        cost += sum;
        minHeap.push(sum);
    }

    return cost;
}

int main()
{
    vector<int> arr;

    cout << "Enter the elements of array (-1 to stop) : ";
    int temp;
    cin >> temp;
    while (temp != -1)
    {
        arr.push_back(temp);
        cin >> temp;
    }

    int cost = minimumCost(arr);

    cout << "Minimum cost to join all ropes = " << cost << endl;

    return 0;
}
//4 3 2 6 
// // ans = 29
// Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths. 

// Examples:

// Input: arr[] = [4, 3, 2, 6]
// Output: 29
// // Explanation: First connect 2 and 3 to get [4, 5, 6] with a cost of 5, then connect 4 and 5 to get [9, 6] with a cost of 9, and finally connect 9 and 6 to get one rope with a cost of 15, giving a total minimum cost of 29. Any other order, such as connecting 4 and 6 first, results in a higher total cost of 38.