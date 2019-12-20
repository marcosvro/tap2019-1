#include <bits/stdc++.h>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

void _print_map(vvc vector, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << vector[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vvc vetor(n, vc(n, 'J'));

    for (int i = 0; i < n; i++)
    {
        vetor[i][0] = '#';
        vetor[0][i] = '#';
        vetor[i][n - 1] = '#';
        vetor[n - 1][i] = '#';
    }
    _print_map(vetor, n);
}