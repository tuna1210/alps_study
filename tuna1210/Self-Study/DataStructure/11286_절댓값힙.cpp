#include <iostream>
#include <queue>
using namespace std;

typedef struct _compare
{
    bool operator()(int& a, int& b)
    {
        int ab = abs(a), bb = abs(b);
        if(ab != bb) return ab > bb;
        else return a > b;
    }
} compare;

priority_queue<int, vector<int>, compare> pq;

int main()
{
    int n;
    cin >> n;

    while(n--)
    {
        int op;
        cin >> op;

        if(op != 0) pq.push(op);
        else
        {
            if(pq.size() == 0) cout << 0 << "\n";
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
}