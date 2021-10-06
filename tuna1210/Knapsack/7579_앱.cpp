#include <iostream>
#include <cstring>
using namespace std;

int n, m, sum;
int w[101], v[101];
int dp[101][10001];

int bottomup()
{
    for (int j = v[1]; j <= sum; j++)
    {
        dp[1][j] = w[1];
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            dp[i][j] = max(dp[i - 1][j], (j >= v[i] ? (dp[i - 1][j - v[i]] + w[i]) : 0));
        }
    }
    int i;
    for (i = 0; i <= sum; i++)
    {
        if(dp[n][i] >= m) break;
    }
    return i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    
    cout << bottomup() << "\n";

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j < 50; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    return 0;
}