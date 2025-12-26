#include <bits/stdc++.h>
using namespace std;
int f(int ind, int buy, int cap, vector<int> &arr, vector<vector<vector<int>>> &dp)
{
    if (cap == 0)
        return 0;
    if (ind == arr.size())
        return 0;

    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];

    int profit = 0;

    if (buy)
    {
        profit = max(
            -arr[ind] + f(ind + 1, 0, cap, arr, dp),
            0 + f(ind + 1, 1, cap, arr, dp));
    }
    else
    {
        profit = max(
            arr[ind] + f(ind + 1, 1, cap - 1, arr, dp),
            0 + f(ind + 1, 0, cap, arr, dp));
    }

    return dp[ind][buy][cap] = profit;
}

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    return f(0, 1, k, prices, dp);
}

int maxProfitTab(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= k; cap++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(
                        -prices[ind] + dp[ind + 1][0][cap],
                        0 + dp[ind + 1][1][cap]);
                }
                else
                {
                    profit = max(
                        prices[ind] + dp[ind + 1][1][cap - 1],
                        0 + dp[ind + 1][0][cap]);
                }
                dp[ind][buy][cap] = profit;
            }
        }
    }

    return dp[0][1][k];
}
int maxProfitSpaceOpt(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
    vector<vector<int>> curr(2, vector<int>(k + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= k; cap++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(
                        -prices[ind] + ahead[0][cap],
                        0 + ahead[1][cap]);
                }
                else
                {
                    profit = max(
                        prices[ind] + ahead[1][cap - 1],
                        0 + ahead[0][cap]);
                }
                curr[buy][cap] = profit;
            }
        }
        ahead = curr;
    }

    return ahead[1][k];
}
// n*4k space
int maxProfitSpaceOpt(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<int> ahead(2 * k + 1, 0);
    vector<int> curr(2 * k + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= k; cap++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(
                        -prices[ind] + ahead[0 * k + cap],
                        0 + ahead[1 * k + cap]);
                }
                else
                {
                    profit = max(
                        prices[ind] + ahead[1 * k + (cap - 1)],
                        0 + ahead[0 * k + cap]);
                }
                curr[buy * k + cap] = profit;
            }
        }
        ahead = curr;
    }
    return ahead[1 * k + k];
}
int main()
{
    vector<int> price = {7, 1, 5, 3, 6, 4};
    int k = 2;
    cout << maxProfit(k, price);
}