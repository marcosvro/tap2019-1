#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

int main() {
  long int x, m;
  cin >> x >> m;

  for (int i = 1; i < m; i++) {
    if ((x * i) % m == 1) {
      cout << i << endl;
      return 0;
    }
  }

  cout << "Nao existe este tipo de inteiro." << endl;

  return 0;
}