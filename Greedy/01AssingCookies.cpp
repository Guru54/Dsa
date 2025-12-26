#include <bits/stdc++.h>
using namespace std;
int as(vector<int> &greed, vector<int> &s)
{
    int n = greed.size(), m = s.size();
    sort(greed.begin(), greed.end());
    sort(s.begin(), s.end());
    int l = 0, r = 0;
    while (l < n && r < m)
    {
        if (s[r] >= greed[l])
        {
            l++;
        }
        r++;
    }
    return l;
}
int main()
{
    vector<int> greed = {1, 5, 3, 3, 4};
    vector<int> s = {4, 2, 1, 2, 1, 3};
    int ans = as(greed, s);
    cout << "the maximum no of cookies i can assing is : " << ans << endl;
    return 0;
}