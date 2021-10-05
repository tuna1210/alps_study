#include <iostream>
#include <cstring>
using namespace std;

int n, k;
int w[101], v[101];
int dp[101][100001];

int solution(int i, int sum)
{
    if(i == n) return 0;

    int& ret = dp[i][sum];
    if(ret != 0) return ret;

    int take = 0, pass;
    if(sum + w[i] <= k) 
    {
        take = solution(i + 1, sum + w[i]) + v[i];
    }
    pass = solution(i + 1, sum);

    ret = max(take, pass);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    
    cout << solution(0, 0);
}