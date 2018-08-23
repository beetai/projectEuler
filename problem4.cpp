#include <iostream>
using namespace std;

int reverse(int num) {
  int retVal = 0;
  while (num != 0) {
    retVal *= 10;
    retVal += num % 10;
    num /= 10;
  }
  return retVal;
}

bool isPalindrome(int num) {
  return num == reverse(num);
}

int main() {
  int val = 0;
  for (int i = 100; i < 1000; i++) {
    for (int j = 100; j < 1000; j++) {
      int product = i*j;
      if (isPalindrome(product) && (product > val)) {
        val = product;
      }
    }
  }
  std::cout << val << std::endl;
  return 0;
}
