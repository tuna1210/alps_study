#include <iostream>
using namespace std;

long long A[100001];
long long tree[400004];

long long Init(int start, int end, int node)
{
    if(start == end) tree[node] = A[start];
    else
    {
        int mid = (start + end) / 2;
        tree[node] = min(Init(start, mid, node * 2), Init(mid + 1, end, node * 2 + 1));
    }
    return tree[node];
}

long long FindMinVal(int start, int end, int node, const int& left, const int& right)
{
    if(right < start || end < left) return 1e9;
    if(left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return min(FindMinVal(start, mid, node * 2, left, right), FindMinVal(mid + 1, end, node * 2 + 1, left, right));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }

    Init(1, n, 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        cout << FindMinVal(1, n, 1, a, b) << "\n";
    }
    
    return 0;
}