#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    int arr[n];
    for(auto& i : arr)
    {
        cin >> i;
    }
    
    int x;
    cin >> x;

    sort(arr, arr + n);
    
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        auto range = equal_range(arr + i + 1, arr + n, x - arr[i]);
        ans += range.second - range.first;
    }

    cout << ans << "\n";

    return 0;
}