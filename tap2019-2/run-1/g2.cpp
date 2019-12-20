#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
  string n1, c;
  int count = 0;
  cin >> n1;

  while (true) {
    c = n1;
    while (next_permutation(c.begin(), c.end()))
      ;

    int min = stoi(c);
    prev_permutation(c.begin(), c.end());
    int max = stoi(c);
    int n4 = max - min;
    count++;
    if (n4 == 6174)
      break;
    n1 = to_string(n4);
  }
  cout << count << endl;

  return 0;
}