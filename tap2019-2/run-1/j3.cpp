#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
  int a1, a2;
  cin >> a1 >> a2;
  for (int i = 0; i <= (a2 - a1); i++) {
    if (i % 2 == 0 && i % 3 == 0 && i % 4 == 0 && i % 5 == 0)
      cout << "Todas as posicoes mudam no ano " << a1 + i << "." << endl;
  }
  return 0;
}