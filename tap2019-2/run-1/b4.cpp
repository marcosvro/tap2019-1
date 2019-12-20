#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
  int n, c = 0;
  cin >> n;

  while (n > 0) {
    int fat = 1, i;
    for (i = 1; fat * i <= n; i++)
      fat *= i;
    n -= fat;
    c++;
  }

  cout << c << endl;

  return 0;
}