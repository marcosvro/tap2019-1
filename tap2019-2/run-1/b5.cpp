#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

int main() {
  long int N, maior, votos_carlos;
  bool ganhou = false;
  cin >> N >> votos_carlos;

  maior = votos_carlos;

  for (int i = 0; i < N - 1; i++) {
    int aux;
    cin >> aux;
    if (aux > maior)
      maior = aux;
  }

  if (maior == votos_carlos)
    cout << "S" << endl;
  else
    cout << "N" << endl;

  return 0;
}