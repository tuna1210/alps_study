#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    string input;
    cin >> input;

    int ans = 0, last = input.length();
    for (int i = 0; i < last; i++)
    {
        int cnt = 0;
        if(input[i] == 'I')
        {
            for (int j = i + 1;; j += 2)
            {
                if(j + 1 >= last || input[j] != 'O' || input[j + 1] != 'I') break;
                cnt++;
            }
            if(cnt >= n) ans += cnt - n + 1;
        }
        if(cnt != 0) i += cnt * 2;
    }
    
    cout << ans << "\n";

    return 0;
}