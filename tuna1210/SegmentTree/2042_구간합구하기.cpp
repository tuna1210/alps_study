#include <iostream>
using namespace std;

long long arr[1000001];
long long tree[4000004];

long long init(int start, int end, long long node)
{
    if(start == end) tree[node] = arr[start];
    else
    {
        int mid = (start + end) / 2;
        tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
    }
    return tree[node];
}

long long sum(int start, int end, long long node, int left, int right)
{
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, long long node, int idx, long long diff)
{
    if(idx < start || end < idx) return;
    tree[node] += diff;

    if(start == end) return;

    int mid = (start + end) / 2;
    update(start, mid, node * 2, idx, diff);
    update(mid + 1, end, node * 2 + 1, idx, diff);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    init(0, n - 1, 1);

    long long opc = m + k;
    for (int i = 0; i < opc; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        b--;

        if(a == 1)
        {
            update(0, n - 1, 1, b, c - arr[b]);
            arr[b] = c;
        }
        else
        {
            c--;
            cout << sum(0, n - 1, 1, b, c) << "\n";
        }
    }

    return 0;
}