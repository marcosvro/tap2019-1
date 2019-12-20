#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

int main() {
  long int a, b, c = 0;
  cin >> a >> b;

  int acrt = cbrt(a);
  int bcrt = cbrt(b);

  for (int i = acrt; i <= bcrt; i++) {
    if (i * i * i >= a && i * i * i <= b) {
      int num = i * i * i;
      for (int k = 1; k <= num; k++) {
        if (k * k == num) {
          c++;
          break;
        }
        if (k * k > num)
          break;
      }
    }
  }

  cout << c << endl;

  return 0;
}