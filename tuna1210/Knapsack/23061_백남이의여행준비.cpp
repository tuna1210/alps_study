#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int w[101], v[101];
int bag[101];
int dp[101][100001];

int solution(int i, int total)
{
    if(i == n) return 0;
    int& ret = dp[i][total];

    if(ret != -1) return ret;
    int take = 0;
    take = solution(i + 1, total - v[i]) + w[i];
    ret = max(take, solution(i + 1, total));
    return ret;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    
    cin >> n >> m;

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
        total += v[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> bag[i];
    }
    
    memset(dp, -1, sizeof(dp));
    solution(0, total);

    for (int j = 0; j < 72; j++)
    {
        printf("%3d", j);
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 72; j++)
        {
            // cout << dp[i][j] << " ";
            printf("%3d", dp[i][j]);
        }
        cout << "\n";
    }

    
    // cout << ans << "\n";
}