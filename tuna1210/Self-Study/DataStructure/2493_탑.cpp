#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    stack<pair<int, int>> s;

    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    s.push({0, 1e9});
    
    int i = 1;
    int ans[n + 1];
    memset(ans, 0, sizeof(ans));
    while(i <= n)
    {
        auto sTop = s.top();
        if(sTop.second > a[i] || sTop.second == 1e9)
        {
            ans[i] = sTop.first;
            s.push({i, a[i]});
            i++;
        }
        else
        {
            s.pop();
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    
}