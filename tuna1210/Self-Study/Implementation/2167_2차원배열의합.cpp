#include <iostream>
using namespace std;

int arr[301][301];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    int k;
    cin >> k;

    for (int t = 0; t < k; t++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        long long sum = 0;

        for (int i = a; i <= c; i++)
        {
            for (int j = b; j <= d; j++)
            {
                sum += arr[i][j];
            }
        }
        
        cout << sum << "\n";
    }
    
    return 0;
}