#include <bits/stdc++.h>
using namespace std;

int main()
{

    float n;
    cin >> n;
    char op;
    cin >> op;
    while (!cin.fail())
    {
        if (op == '@')
        {
            n *= 3;
        }
        else if (op == '#')
        {
            n -= 7;
        }
        else if (op == '%')
        {
            n += 5;
        }
        cin >> op;
    }

    cout << fixed;
    cout << setprecision(2);
    cout << n << endl;

    return 0;
}

/*

#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}
*/