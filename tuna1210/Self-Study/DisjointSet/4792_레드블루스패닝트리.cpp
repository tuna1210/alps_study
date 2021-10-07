#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int uf[1001];

int find(int u)
{
    if(uf[u] < 0) return u;
    uf[u] = find(uf[u]);
    return uf[u];
}

bool merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u == v) return false;
    if(uf[u] < uf[v])
    {
        uf[u] += uf[v];
        uf[v] = u;
    }
    else
    {
        uf[v] += uf[u];
        uf[u] = v;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(true)
    {
        int n, m, k;
        cin >> n >> m >> k;
        if(n == 0 && m == 0 && k == 0) break;

        vector<pair<int, int>> RE, BE;
        for (int i = 0; i < m; i++)
        {
            char type;
            int u, v;
            cin >> type >> u >> v;
            if(type == 'R') RE.push_back({u, v});
            if(type == 'B') BE.push_back({u, v});
        }
        
        memset(uf, -1, sizeof(uf));

        int maxBlue = 0, minBlue = 0;
        for(const auto& edge : BE)
        {
            if(merge(edge.first, edge.second)) maxBlue++;
        }
        
        memset(uf, -1, sizeof(uf));
        for(const auto& edge : RE)
        {
            merge(edge.first, edge.second);
        }
        for(const auto& edge : BE)
        {
            if(merge(edge.first, edge.second)) minBlue++;
            if(abs(uf[find(edge.first)]) == n) break;
        }

        if(maxBlue >= k && minBlue <= k) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}