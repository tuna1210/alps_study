#include <iostream>
using namespace std;

long long arr[1000001];
long long tree[4000004];

long long take(int start, int end, long long node, int rank)
{
    if(rank > tree[node] || tree[node] == 0) return 0;
    if(start == end) return start;

    int mid = (start + end) / 2;
    if(rank <= tree[node * 2]) return take(start, mid, node * 2, rank);
    else return take(mid + 1, end, node * 2 + 1, rank - tree[node * 2]);
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
    
    long long n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long long a, b, c;
        cin >> a;

        if(a == 1)
        {
            cin >> b;
            int taste = take(1, 1000000, 1, b);
            cout << taste << "\n";

            update(1, 1000000, 1, taste, -1);
            arr[taste] -= 1;
        }
        else
        {
            cin >> b >> c;
            update(1, 1000000, 1, b, c);
            arr[b] += c;
        }
    }

    return 0;
}