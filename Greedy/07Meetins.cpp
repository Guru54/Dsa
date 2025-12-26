#include <bits/stdc++.h>
using namespace std;
class Data
{
public:
    int start, end, pos;
};

int findmeetings(vector<int> &start, vector<int> &end)
{
    Data arr[start.size()];
    for (int i = 0; i < start.size(); i++)
    {
        arr[i].start = start[i];
        arr[i].end = end[i];
        arr[i].pos = i + 1;
    }
    auto comparator = [](Data val1, Data val2)
    {
        return val1.end < val2.end;
    };
    sort(arr, arr + start.size(), comparator);
    int freetime = arr[0].end;
    vector<int> ans = {arr[0].pos};
    for (int i = 1; i < start.size(); i++)
    {
        if (arr[i].start > freetime)
        {

            freetime = arr[i].end;
            ans.push_back(arr[i].pos);
        }
    }
    int s = ans.size();
    return s;
}
int main()
{
    vector<int> start = {0, 3, 1, 5, 5, 8};
    vector<int> end = {5, 4, 2, 9, 7, 9};
    int ans = findmeetings(start, end);
    cout << "the max no of meeting possible is " << ans << endl;
    return 0;
}