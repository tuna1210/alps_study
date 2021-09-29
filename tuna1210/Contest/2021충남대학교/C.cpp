#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

int n, m;
int arr[21];
unordered_set<int> visited;

void dfs(int u, int path)
{
    if(u == n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if((path & (1 << i)) == (1 << i))
            {
                sum += arr[i];
            }
        }
        if(sum >= 1 && visited.insert(sum).second)
        {
            m--;
        }
        return;
    }

    dfs(u + 1, (path | 1 << u));
    dfs(u + 1, path);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        m += arr[i];
    }

    dfs(0, 0);
    dfs(0, 1 << 0);

    cout << m << "\n";
}