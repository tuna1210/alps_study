#include <iostream>
using namespace std;

#define MOD 1000000007

long long arr[1000001];
long long tree[4000004];

long long init(int start, int end, int node)
{
    if(start == end) tree[node] = arr[start];
    else
    {
        int mid = (start + end) / 2;
        tree[node] = ((init(start, mid, node * 2) % MOD) * (init(mid + 1, end, node * 2 + 1) % MOD)) % MOD;
    }
    return tree[node];
}

long long getMul(int start, int end, int node, const int& left, const int& right)
{
    if(right < start || end < left) return 1;
    if(left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return ((getMul(start, mid, node * 2, left, right) % MOD) * (getMul(mid + 1, end, node * 2 + 1, left, right) % MOD)) % MOD;
}

long long update(int start, int end, int node, const int& idx, const int& mulVal, const int& divVal)
{
    if(idx < start || end < idx) return tree[node];
    if(start == end) tree[node] = mulVal;
    else
    {
        int mid = (start + end) / 2;
        long long l = update(start, mid, node * 2, idx, mulVal, divVal) % MOD;
        long long r = update(mid + 1, end, node * 2 + 1, idx, mulVal, divVal) % MOD;
        tree[node] = (l * r) % MOD;
    }

    return tree[node];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    
    init(1, n, 1);

    // for (int i = 0; i <= 4 * n; i++)
    //     {
    //         cout << tree[i] << " ";
    //     }cout << "\n";
    int opc = m + k;
    for (int i = 0; i < opc; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if(a == 1)
        {
            update(1, n, 1, b, c, arr[b]);
            arr[b] = c;
        }
        else
        {
            cout << getMul(1, n, 1, b, c) << "\n";
        }
        // for (int i = 0; i <= 4 * n; i++)
        // {
        //     cout << tree[i] << " ";
        // }cout << "\n";
        
    }
    
    return 0;
}