#include <iostream>
using namespace std;

long long A[100001];
long long minTree[400004];
long long maxTree[400004];

long long InitMin(int start, int end, int node)
{
    if(start == end) minTree[node] = A[start];
    else
    {
        int mid = (start + end) / 2;
        minTree[node] = min(InitMin(start, mid, node * 2), InitMin(mid + 1, end, node * 2 + 1));
    }
    return minTree[node];
}

long long FindMinVal(int start, int end, int node, const int& left, const int& right)
{
    if(right < start || end < left) return 1e9;
    if(left <= start && end <= right) return minTree[node];

    int mid = (start + end) / 2;
    return min(FindMinVal(start, mid, node * 2, left, right), FindMinVal(mid + 1, end, node * 2 + 1, left, right));
}

long long InitMax(int start, int end, int node)
{
    if(start == end) maxTree[node] = A[start];
    else
    {
        int mid = (start + end) / 2;
        maxTree[node] = max(InitMax(start, mid, node * 2), InitMax(mid + 1, end, node * 2 + 1));
    }
    return maxTree[node];
}

long long FindMaxVal(int start, int end, int node, const int& left, const int& right)
{
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return maxTree[node];

    int mid = (start + end) / 2;
    return max(FindMaxVal(start, mid, node * 2, left, right), FindMaxVal(mid + 1, end, node * 2 + 1, left, right));
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

    InitMin(1, n, 1);
    InitMax(1, n, 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        cout << FindMinVal(1, n, 1, a, b) << " " << FindMaxVal(1, n, 1, a, b) << "\n";
    }
    
    return 0;
}