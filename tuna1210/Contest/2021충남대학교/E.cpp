#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int n;
map<string, vector<string>> G;
set<string> item;
set<string> S;
map<string, int> cost;

void khan()
{
    queue<string> q;
    for(const auto& i : item)
    {
        if(cost[i] == 0) q.push(i);
    }
    
    queue<string> answer;
    while(!q.empty())
    {
        int qsize = q.size();
        vector<string> wait;
        for(int qs = 0; qs < qsize; qs++)
        {
            string cur = q.front();
            q.pop();

            wait.push_back(cur);
            
            for(const auto& next : G[cur])
            {
                cost[next]--;
                if(cost[next] == 0) q.push(next);
            }
        }

        sort(wait.begin(), wait.end());

        for(const auto& i : wait)
        {
            answer.push(i);
        }
    }

    if(answer.size() < item.size()) cout << -1;
    else
    {
        while(!answer.empty())
        {
            cout << answer.front() << "\n";
            answer.pop();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;

        item.insert(a);
        item.insert(b);

        cost[b]++;

        G[a].push_back(b);
    }

    khan();

    return 0;   
}