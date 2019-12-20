#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    char c;
    cin >> n >> c;

    for (int i = 1; i <= n; i++)
    {
        if (c == 91)
        {
            c = 'A';
        }
        for (int j = 0; j < i; j++)
        {
            cout << c;
        }
        c++;
        cout << endl;
    }
    return 0;
}