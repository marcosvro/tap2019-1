#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
  int n;

  cin >> n;
  vi seq;

  if (n < 3) {
    cout << "0 0" << endl;
    return 0;
  }

  for (int i = 0; i < n; i++) {
    int inp;
    cin >> inp;
    seq.push_back(inp);
  }

  int picos = 0;
  int depre = 0;

  for (int i = 1; i < n - 1; i++) {
    int menor_esq = 0;
    int menor_dir = 0;
    int maior_esq = 0;
    int maior_dir = 0;
    // search left
    for (int j = 0; j < i; j++) {
      if (seq[i] > seq[j])
        menor_esq++;
      else if (seq[i] < seq[j])
        maior_esq++;
    }
    // search right
    for (int j = i + 1; j < n; j++) {
      if (seq[i] > seq[j])
        menor_dir++;
      else if (seq[i] < seq[j])
        maior_dir++;
    }
    picos += (menor_esq * menor_dir);
    depre += (maior_esq * maior_dir);
  }

  cout << picos << ' ' << depre << endl;

  return 0;
}