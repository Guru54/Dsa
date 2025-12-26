#include <bits/stdc++.h>
using namespace std;

int x[20]; // x[i] = column position of queen in row i

bool Place(int i, int j)
{
    for (int k = 1; k < i; k++)
    {
        if (x[k] == j || abs(i - k) == abs(x[k] - j))
        {
            return false; // same column or diagonal clash
        }
    }
    return true;
}

void NQ(int i, int N)
{
    for (int j = 1; j <= N; j++)
    {
        if (Place(i, j))
        {
            x[i] = j;
            if (i == N)
            {
                // print solution
                for (int row = 1; row <= N; row++)
                {
                    for (int col = 1; col <= N; col++)
                    {
                        if (x[row] == col)
                            cout << "Q ";
                        else
                            cout << ". ";
                    }
                    cout << endl;
                }
                cout << "---------------\n";
            }
            else
            {
                NQ(i + 1, N); // next row
            }
        }
    }
}

int main()
{
    int N = 4;
    NQ(1, N);
    return 0;
}
