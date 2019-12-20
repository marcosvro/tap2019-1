#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
  int n, m;
  string s, t;
  cin >> m >> n;

  if (n > m) {
    cout << "NAO" << endl;
    return 0;
  }

  cin >> s >> t;

  string::iterator t_it = t.begin();

  for (string::iterator s_it = s.begin(); s_it != s.end(); s_it++) {
    if (*t_it == *s_it) {
      t_it++;
      if (t_it == t.end()) {
        cout << "SIM" << endl;
        return 0;
      }
    }
  }
  cout << "NAO" << endl;
  return 0;
}