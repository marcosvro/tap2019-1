#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
  int n, sum = 0;
  cin >> n;

  for (int i = 1; i < n; i++) {
    if (n % i == 0)
      sum += i;
    if (sum > n) {
      cout << n << " eh um numero abundante." << endl;
      return 0;
    }
  }

  if (sum == n) {
    cout << n << " eh um numero perfeito." << endl;
  } else {
    cout << n << " eh um numero deficiente." << endl;
  }

  return 0;
}