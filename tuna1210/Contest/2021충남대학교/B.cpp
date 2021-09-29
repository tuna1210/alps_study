#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<string>> form(11);

bool compare(string& a, string& b)
{
    if(a.length() == b.length()) return a < b;

    if(a.length() < b.length()) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;

    int c;
    string name;

    while(true)
    {
        cin >> c >> name;
        if(c == 0) break;

        if(form[c].size() == m) continue;
        form[c].push_back(name);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(form[i].begin(), form[i].end(), compare);
    }
    
    for (int i = 1; i <= n; i+=2)
    {
        for(const auto& n : form[i])
        {
            cout << i << " " << n << "\n";
        }
    }
    for (int i = 2; i <= n; i+=2)
    {
        for(const auto& n : form[i])
        {
            cout << i << " " << n << "\n";
        }
    }
}