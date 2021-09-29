#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int n;
map<string, vector<string>> G;
set<string> income;
set<string> items;
set<string> visited;
stack<string> s;

void dfs(string a)
{
    cout << "cur : " << a << "\n";
    for(const auto& i : G[a])
    {
        if(!visited.insert(i).second) continue;
        flag = true;
        dfs(i);
    }
    s.push(a);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    string a, b;
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        G[a].push_back(b);
        items.insert(a);
        items.insert(b);
        income.insert(b);
    }
    
    for(const auto& i : items)
    {
        if(find(income.begin(), income.end(), i) == income.end())
        {
            cout << i << "\n";
            dfs(i);
        }
    }
    cout << "\n";
    while(!s.empty())
    {
        cout << s.top() << "\n";
        s.pop();
    }
}