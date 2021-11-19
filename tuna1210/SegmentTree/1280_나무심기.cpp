#include <iostream>
using namespace std;

#define MOD 1000000007

int n;
long long arr[200001];
long long psum[800004];
long long pmul[800004];

long long initSum(int start, int end, long long node)
{
    if(start == end) psum[node] = arr[start];
    else
    {
        int mid = (start + end) / 2;
        psum[node] = initSum(start, mid, node * 2) + initSum(mid + 1, end, node * 2 + 1);
    }
    return psum[node];
}

long long sum(int start, int end, long long node, int left, int right)
{
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return psum[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

long long getCost(int k)
{
    cout << sum(1, n, 1, 1, k - 1) << "\n";
    return (k - 1) * arr[k] - sum(1, n, 1, 1, k - 1);
}

long long initMul(int start, int end, int node)
{
    if(start == end)
    {
        pmul[node] = getCost(start);
        cout << "cost[" << start << "] = " << pmul[node] << "\n";
    }
    else
    {
        int mid = (start + end) / 2;
        pmul[node] = ((initMul(start, mid, node * 2) % MOD) * (initMul(mid + 1, end, node * 2 + 1) % MOD)) % MOD;
    }
    return pmul[node];
}

long long getMul(int start, int end, int node, const int& left, const int& right)
{
    if(right < start || end < left) return 1;
    if(left <= start && end <= right) return pmul[node];

    int mid = (start + end) / 2;
    return ((getMul(start, mid, node * 2, left, right) % MOD) * (getMul(mid + 1, end, node * 2 + 1, left, right) % MOD)) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    initSum(1, n, 1);
    for (int i = 1; i <= 4*n; i++)
    {
        cout << psum[i] << " ";
    }
    cout << "\n";
    
    initMul(2, n, 1);

    cout << getMul(2, n, 1, 2, 5) << "\n";

    return 0;
}