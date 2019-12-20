#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi volume(20);

int main() {
  int n;
  int m;
  int c;
  int silences_count = 0;
  int min, min_idx;
  int max, max_idx;

  while (true) {
    cin >> n;
    if (cin.fail())
      break;

    cin >> m >> c;

    if (m == 0 || n == 0 || m > n) {
      cout << 0 << endl;
      return 0;
    }

    for (int i = 0; i < n; i++) {
      cin >> volume[i];
    }

    min = volume[0];
    max = volume[0];
    min_idx = 0;
    max_idx = 0;

    for (int i = 0; i < m; i++) {
      if (volume[i] > max) {
        max = volume[i];
        max_idx = i;
      } else if (volume[i] < min) {
        min = volume[i];
        min_idx = i;
      }
    }

    if (max - min <= c)
      silences_count++;

    for (int i = m; i < n; i++) {
      if (min_idx == i - m) {
        min_idx = i - m + 1;
        min = volume[min_idx];
        for (int j = i - m + 1; j < i; j++) {
          if (volume[j] < min) {
            min = volume[j];
            min_idx = j;
          }
        }
      }
      if (max_idx == i - m) {
        max_idx = i - m + 1;
        max = volume[max_idx];
        for (int j = i - m + 1; j < i; j++) {
          if (volume[j] > max) {
            max = volume[j];
            max_idx = j;
          }
        }
      }
      if (volume[i] > max) {
        max = volume[i];
        max_idx = i;
      } else if (volume[i] < min) {
        min = volume[i];
        min_idx = i;
      }
      if (max - min <= c)
        silences_count++;
    }
  }

  cout << silences_count << endl;

  return 0;
}