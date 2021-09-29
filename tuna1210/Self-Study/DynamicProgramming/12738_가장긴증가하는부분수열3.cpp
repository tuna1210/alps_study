#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> lis;
    
    int ans = 0;
    lis.push_back(-1e9 - 1);
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if(lis.back() < a)
        {
            lis.push_back(a);
            ans++;
        }
        else
        {
            auto chgPos = lower_bound(lis.begin(), lis.end(), a);
            *chgPos = a;
        }
    }
    cout << ans << "\n";
}