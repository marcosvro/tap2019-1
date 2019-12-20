#include <bits/stdc++.h>
#include <algorithm>  // std::next_permutation, std::sort
#include <string>

using namespace std;

typedef vector<int> vi;

int main() {
  string inp;
  string jesus;

  cin >> inp;
  jesus = inp;

  next_permutation(jesus.begin(), jesus.end());

  if (stoi(jesus) > stoi(inp)) {
    cout << jesus << endl;
    return 0;
  }

  cout << "USELESS" << endl;
  return 0;
}