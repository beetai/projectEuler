#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <stdint.h>
using namespace std;

// vector<int> deck;
int64_t indexOfTwo;

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

// main method for sum calculation
// int main(int argc, char** argv) {
//   int64_t sum = 0;
//   bool trig = false;
//   indexOfTwo = 1;
//   int64_t range = pow(2, stoi(argv[1]));
//
//   double perc = range;
//
//   for (int64_t i = range; i >= 2; i -= 2) {
//     shuffle(i);
//     for (int j = 0; j < stoi(argv[1]) - 1; j++) {
//       if (isInOrder()) {
//         trig = true;
//         break;
//       }
//       shuffle(i);
//     }
//
//     if (isInOrder() && !trig) {
//       cout << i << " (" << ((double) i / perc) << ")" << endl;
//       sum += i;
//
//       perc = i;
//     }
//
//     indexOfTwo = 1;
//     trig = false;
//   }
//
//
// // start from the largest number, halve it, iterate down until next true value, halve value again?
//   // int64_t curr = 384307168202282326;
//   // for (size_t i = 1; i < 10; i++) {
//   //   shuffle(curr);
//   //   for (int j = 0; j < stoi(argv[1]) - 1; j++) {
//   //     if (isInOrder()) {
//   //       trig = true;
//   //       break;
//   //     }
//   //     shuffle(curr);
//   //   }
//   //
//   //   if (isInOrder() && !trig) {
//   //     cout << curr << " (" << ((double) curr / perc) << ")" << endl;
//   //     sum += curr;
//   //
//   //     perc = curr;
//   //   }
//   //
//   //   curr = ceil(curr / (double)(3+(2*i)) * (double)(1+(2*i)));
//   //   cout << curr << endl;
//   //   indexOfTwo = 1;
//   //   trig = false;
//   // }
//
//
//   cout << "\n";
//   cout << sum << endl;
//   return 0;
// }

/*
 * code for finding s(n) for testing purposes
 * note: cannot take numbers larger than the integar value limit
 */
int s(int64_t n) {
  indexOfTwo = 1;
  int retVal = 1;
  shuffle(n);
  while (!isInOrder()) {
    shuffle(n);
    retVal++;
  }
  return retVal;
}

//main method for calculating s(n)
int main(int argc, char const *argv[]) {
  cout << s(strtoull(argv[1], nullptr, 10)) << endl;
  // for (size_t i = 4; i <= 1024; i += 2) {
  //   cout << i << ": " << s(i);
  //   // if (i != pow(2, s(i))) {cout << " (" << (i - s(i)) << ")";}
  //   cout << endl;
  // }
  return 0;
}
