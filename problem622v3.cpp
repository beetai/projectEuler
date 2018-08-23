#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <stdint.h>
using namespace std;

// vector<int> deck;
int64_t indexOfTwo;
int64_t range;
int shuffles;

/*
 * A riffle shuffle is executed as follows: a deck of cards is split into two
 * equal halves, with the top half taken in the left hand and the bottom half
 * taken in the right hand. Next, the cards are interleaved exactly, with the
 * top card in the right half inserted just after the top card in the left half,
 * the 2nd card in the right half just after the 2nd card in the left half, etc.
 * (Note that this process preserves the location of the top and bottom card of the deck)
 */
void shuffle(int64_t deckSize) {
  indexOfTwo *= 2;
  indexOfTwo %= (deckSize - 1);
}

bool isInOrder() {
  return indexOfTwo == 1;
}

bool isSNInput(int64_t curr) {
  indexOfTwo = 1;
  bool trig = false;
  shuffle(curr);

  for (int j = 0; j < shuffles - 1; j++) {
    if (isInOrder()) {
      trig = true;
      break;
    }
    shuffle(curr);
  }

  return (isInOrder() && !trig);
}

// main method for sum calculation
int main(int argc, char** argv) {
  indexOfTwo = 1;
  range = pow(2, stoi(argv[1]));
  shuffles = stoi(argv[1]);

  int64_t sum = range;
  cout << range << endl;

// start from the largest number, halve it, iterate down until next true value, halve value again?
  // int64_t curr = range;
  // int64_t currNumerator = 1;
  // for (size_t i = 1; i < 10; i++) {
  //
  //
  //
  //
  //   curr = ceil(curr / (double)(3+(2*i)) * (double)(1+(2*i)));
  //   cout << curr << endl;
  //   indexOfTwo = 1;
  //   trig = false;
  // }

  // double perc = range;

  // for (int64_t i = range; i >= 2; i -= 2) {
  //   if (isSNInput(i)) {
  //     cout << i << " (" << ((double) i / perc) << ")" << endl;
  //     sum += i;
  //
  //     perc = i;
  //   }
  // }

  // ******************************

  int64_t curr = range;
  int64_t temp;
  double currNumerator = 1;
  double currDenominator = 3;

  while (curr > 760966768) {
    temp = curr;
    curr = ceil(curr / currDenominator * currNumerator);
    while (!isSNInput(curr)) {
      currDenominator += 2;
      curr = ceil(temp / currDenominator * currNumerator);
    }
    cout << curr;
    // cout << " (" << currNumerator << "/" << currDenominator << ")";
    cout << endl;
    sum += curr;
    currNumerator = currDenominator;
    currDenominator = currNumerator + 2;
  }
  cout << "!" << endl;

  // while (curr > 100000) {
  //   curr = ceil(range / currDenominator);
  //   if (isSNInput(curr)) {
  //     cout << curr << " (1/" << currDenominator << ")" << endl;
  //     sum += curr;
  //   }
  //   currDenominator += 2;
  // }

  for (int i = curr - 2; i > 1; i -= 2) {
    if (isSNInput(i)) {
      cout << i << endl;
      sum += i;
    }
  }

  cout << "\n";
  cout << sum << endl;
  return 0;
}
