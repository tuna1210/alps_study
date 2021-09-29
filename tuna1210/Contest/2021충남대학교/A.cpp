#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if(n == 1)
    {
        cout << "*";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
    cout << "\n";

    for (int i = 1; i < n / 2; i++)
    {
        cout << "*";
        for (int j = 0; j < i - 1; j++)
        {
            cout << " ";
        }
        cout << "*";
        for (int j = 0; j < (n - 2 * (i - 1) - 4); j++)
        {
            cout << " ";
        }
        cout << "*";
        for (int j = 0; j < i - 1; j++)
        {
            cout << " ";
        }
        cout << "*\n";
    }
    // cout << "\n";
    if(n % 2 == 1)
    {
        cout << "*";
        for (int i = 0; i < n / 2 - 1; i++)
        {
            cout << " ";
        }
        cout << "*";
        for (int i = 0; i < n / 2 - 1; i++)
        {
            cout << " ";
        }
        cout << "*\n";
    }
    // cout << "\n";
    for (int i = n / 2 - 1; i > 0; i--)
    {
        cout << "*";
        for (int j = 0; j < i - 1; j++)
        {
            cout << " ";
        }
        cout << "*";
        for (int j = 0; j < (n - 2 * (i - 1) - 4); j++)
        {
            cout << " ";
        }
        cout << "*";
        for (int j = 0; j < i - 1; j++)
        {
            cout << " ";
        }
        cout << "*\n";
    }
    
    
    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
    cout << "\n";
}