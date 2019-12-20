#include <bits/stdc++.h>
using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  sort(s1.begin(), s1.end());
  reverse(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  reverse(s2.begin(), s2.end());

  string::iterator it1 = s1.begin(), it2 = s2.begin();
  for (; it1 != s1.end(); it1++, it2++) {
    if (it2 == s2.end()) {
      cout << "First string is older" << endl;
      return 0;
    }
    if (*it1 > *it2) {
      cout << "First string is older" << endl;
      return 0;
    } else if (*it1 < *it2) {
      cout << "First string is younger" << endl;
      return 0;
    }
  }

  if (it2 != s2.end())
    cout << "First string is younger" << endl;
  else
    cout << "The two strings are the same age" << endl;

  return 0;
}