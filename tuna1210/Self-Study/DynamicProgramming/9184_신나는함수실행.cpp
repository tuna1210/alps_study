#include <iostream>
using namespace std;

int dp[21][21][21];

int w(int a, int b, int c)
{
    if (a <= 0 or b <= 0 or c <= 0) return 1;
    else if (a > 20 or b > 20 or c > 20) return w(20, 20, 20);

    int& ret = dp[a][b][c];
    if(ret != 0) return ret;

    if (a < b and b < c)
        ret = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);

    else
        ret = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);

    return ret;
}

int main()
{
    while(true)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        if(a == -1 && b == -1 && c == -1) break;

        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }

    return 0;
}