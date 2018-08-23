#include <iostream>
using namespace std;

int main () {
  int temp;
  int val = 0;
  int prev = 1;
  int curr = 1;
  while (curr < 4000000) {
    if (curr % 2 == 0) {
      val += curr;
      cout << curr << endl;
    }
    temp = curr;
    curr = prev + curr;
    prev = temp;
  }
  cout << val << endl;
  return 0;
}
