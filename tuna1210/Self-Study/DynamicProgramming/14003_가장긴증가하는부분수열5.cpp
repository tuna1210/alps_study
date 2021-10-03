#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> lis;
    int A[n + 1];

    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    
    int ans = 0;
    lis.push_back(-1e9 - 1);

    vector<pair<int, int>> tracker(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if(lis.back() < A[i])
        {
            tracker[i] = {lis.size(), A[i]};

            lis.push_back(A[i]);
            ans++;
        }
        else
        {
            auto chgPos = lower_bound(lis.begin(), lis.end(), A[i]);
            *chgPos = A[i];

            tracker[i] = {chgPos - lis.begin(), A[i]};
        }
    }

    cout << ans << "\n";

    stack<int> answer;
    int cur = ans;
    for (int i = n; i >= 1; i--)
    {
        if(tracker[i].first == cur)
        {
            answer.push(tracker[i].second);
            cur--;
        }
    }

    while(!answer.empty())
    {
        cout << answer.top() << " ";
        answer.pop();
    }
}