#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;

struct compare {
  bool operator()(const std::string& first, const std::string& second) {
    return first.size() < second.size();
  }
};

int main() {
  int n;
  char c;
  cin >> n;

  vs roubo;
  vs nao_roubo;

  for (int i = 0; i < n; i++) {
    char cmd;
    cin >> cmd;

    string inp;
    cin >> inp;
    if (cmd == 'V') {
      roubo.push_back(inp);
    } else {
      nao_roubo.push_back(inp);
    }
  }

  sort(roubo.begin(), roubo.end(), compare());

  string menor_roubo = roubo[0];
  int max_sub = menor_roubo.size();

  // for each sizes i = (max_sub, .., 1)
  for (int i = max_sub; i > 0; i--) {
    for (int start = 0; start + i - 1 < max_sub; start++) {
      string sub_str = menor_roubo.substr(start, i);
      bool hasError = false;
      for (int it = 0; it < roubo.size(); it++) {
        size_t found = roubo[it].find(sub_str);
        if (found == string::npos) {
          // not found
          hasError = true;
          break;
        }
      }
      if (!hasError) {
        for (int it = 0; it < nao_roubo.size(); it++) {
          size_t found = nao_roubo[it].find(sub_str);
          if (found != string::npos) {
            // not found
            hasError = true;
            break;
          }
        }
      }
      if (!hasError) {
        cout << sub_str << endl;
        return 0;
      }
    }
  }

  cout << "Menor string: " << (roubo[0]) << endl;

  cout << "Maior string: " << roubo[roubo.size() - 1] << endl;

  return 0;
}