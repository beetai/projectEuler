#include <iostream>
using namespace std;

int main () {
  int val = 0;
  for (int i = 1; i < 1000; i++) {
    if ((i % 3 == 0) || (i % 5 == 0)) {
      val += i;
      cout << i << endl;
    }
  }
  cout << val << endl;
  return 0;
}
