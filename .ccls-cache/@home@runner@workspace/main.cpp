#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
typedef unsigned long long ull;
ull range;
double result[4] = {0, 0, 0, 0};
ull initializer[4] = {0, 0, 0, 0};
string range_string;
volatile void stress1(ull range) {
  for (; initializer[0] <= range; initializer[0]++) {
    result[0] = cos(sin(tan(initializer[0]))) / sin(initializer[0]);
    return;
  }
}
int main() {
  range = 1e7;
  stress1(range);
  cout << "[PROGRAMED FINISHED]\n";
  return 0;
}