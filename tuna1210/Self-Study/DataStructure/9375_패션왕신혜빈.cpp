#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        unordered_map<string, int> closet;
        
        for (int i = 0; i < n; i++)
        {
            string trash, type;
            cin >> trash >> type;
            closet[type]++;
        }

        if(n == 0)
        {
            cout << 0 << "\n";
            continue;
        }
        
        unsigned int ans = 1;
        for(const auto& wear : closet)
        {
            ans *= wear.second + 1;
        }
        cout << --ans << "\n";
    }

    return 0;
}