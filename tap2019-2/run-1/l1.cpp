#include <bits/stdc++.h>
#define MAX 1002
using namespace std;
typedef vector<int> vi;

int main() {
  int n;
  cin >> n;

  // constexpr std::size_t MAX_BITS = std::numeric_limits<unsigned int>::digits;
  // const std::bitset<MAX_BITS> bits(num);

  // std::cout << "The no of 1's in " << bits << " is " << bits.count() << '\n';
  // std::cout << "The no of 0's in " << bits << " is "
  //           << bits.size() - bits.count() << '\n';

  unsigned mask = 1 << (std::numeric_limits<unsigned>::digits - 1);

  unsigned count[2] = {0};

  // skip leading 0's:
  while (mask && !(mask & n))
    mask >>= 1;

  while (mask) {
    unsigned digit = (mask & n) != 0;
    ++count[digit];
    mask >>= 1;
  }

  if (count[0] > count[1])
    cout << "left" << endl;
  else if (count[0] < count[1])
    cout << "right" << endl;
  else
    cout << "straight" << endl;

  return 0;
}