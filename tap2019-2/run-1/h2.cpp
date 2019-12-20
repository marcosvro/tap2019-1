#include <bits/stdc++.h>
#define MAX 1002
using namespace std;
typedef vector<int> vi;
int num_navios = 0;
vi navios;
int m, n, p;
vector<vi> tab(MAX, vi(MAX, 0));

void _print_map()
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << tab[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{

    cin >> m >> n;
    navios.push_back(1);

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char cr;
            cin >> cr;
            if (cr == '*')
            {
                if (tab[i - 1][j] != 0)
                {
                    navios[tab[i - 1][j]]++;
                    tab[i][j] = tab[i - 1][j];
                }
                else if (tab[i][j - 1] != 0)
                {
                    navios[tab[i][j - 1]]++;
                    tab[i][j] = tab[i][j - 1];
                }
                else
                {
                    num_navios++;
                    navios.push_back(1);
                    tab[i][j] = num_navios;
                }
            }
            // if (cr == '*' && tab[i-1][j] == 0 && tab[i][j-1] == 0) {
            //     num_navios++;
            // }
        }
    }

    //_print_map();
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        int l, c;
        cin >> l >> c;
        l++;
        c++;
        if (tab[l][c] != 0)
        {
            //acertou
            if (navios[tab[l][c]] > 0)
            {
                navios[tab[l][c]]--;
                if (navios[tab[l][c]] == 0)
                    num_navios--;
            }
            tab[l][c] = 0;
        }
        cout << num_navios << endl;
    }
    return 0;
}