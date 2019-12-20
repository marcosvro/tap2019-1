#include <bits/stdc++.h>
#define MAX 1002
using namespace std;
typedef vector<int> vi;

int main() {
  int n;
  cin >> n;
  vector<vi> mat(n);

  for (int i = 0; i < n; i++) {
    string myString;
    cin >> myString;

    for (string::iterator it = myString.begin(); it != myString.end(); it++) {
      int number = *it - '0';
      mat[i].push_back(number);
    }
  }

  bool hasVerticalError = false;
  bool hasHorizontalError = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (int)n / 2; j++) {
      if (mat[i][j] != mat[i][n - 1 - j])
        hasVerticalError = true;
      if (mat[j][i] != mat[n - 1 - j][i])
        hasHorizontalError = true;
    }
  }

  if (hasVerticalError && hasHorizontalError) {
    cout << "Useless" << endl;
  } else if (hasVerticalError) {
    cout << "Beautiful" << endl;
  } else if (hasHorizontalError) {
    cout << "Graceful" << endl;
  } else {
    cout << "Magnificent" << endl;
  }

  return 0;
}