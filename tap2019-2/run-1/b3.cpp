#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

int main() {
  int n;
  cin >> n;
  vpi factors;
  bool is_unpleasant = false;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i * j == n)
        factors.push_back(make_pair(i, j));
      if (i * j > n)
        break;
    }
  }

  for (vpi::iterator it = factors.begin();
       it != factors.end() && !is_unpleasant; it++) {
    for (vpi::iterator jt = factors.begin(); jt != factors.end(); jt++) {
      if ((*it).first - (*it).second == (*jt).first + (*jt).second) {
        is_unpleasant = true;
        break;
      }
    }
  }

  if (is_unpleasant)
    cout << n << " eh desagradavel." << endl;
  else
    cout << n << " nao eh desagradavel." << endl;

  return 0;
}