#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
vector<int> G[32001];
int prevCount[32001];
vector<int> result;

void khan()
{
    priority_queue<int, vector<int>, greater<int>> q;

    for(int i = 1; i <= n; i++)
    {
        if(prevCount[i] == 0) q.push(i);
    }

    while(!q.empty())
    {
        int cur = q.top();
        q.pop();

        result.push_back(cur);

        sort(G[cur].begin(), G[cur].end(), greater<int>());

        for(const auto& next : G[cur])
        {
            prevCount[next]--;

            if(prevCount[next] == 0)
                q.push(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        prevCount[v]++;
    }
    
    khan();
    
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
}