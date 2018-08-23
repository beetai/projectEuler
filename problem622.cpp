#include <iostream>
#include <vector>
#include <numeric>
#include <stdint.h>
using namespace std;

vector<int> deck;

/*
 * A riffle shuffle is executed as follows: a deck of cards is split into two
 * equal halves, with the top half taken in the left hand and the bottom half
 * taken in the right hand. Next, the cards are interleaved exactly, with the
 * top card in the right half inserted just after the top card in the left half,
 * the 2nd card in the right half just after the 2nd card in the left half, etc.
 * (Note that this process preserves the location of the top and bottom card of the deck)
 */
void shuffle() {
  vector<int> result, top, bottom;
  int mid = deck.size() / 2;
  // for (size_t i = 0; i < deck.size(); i++) {
  //   if (i < mid)
  //     top.push_back(deck[i]);
  //   else
  //     bottom.push_back(deck[i]);
  // }
  // for (size_t i = 0; i < mid; i++) {
  //   result.push_back(top[i]);
  //   result.push_back(bottom[i]);
  // }

  for (size_t i = 0; i < mid; i++) {
    result.push_back(deck[i]);
    result.push_back(deck[i+mid]);
  }
  deck = result;
}

// prints the state of the deck
void printDeck() {
  for (std::vector<int>::iterator it = deck.begin(); it != deck.end(); ++it)
    std::cout << *it << ' ';
  std::cout << '\n';
}

bool isInOrder() {
  return is_sorted(deck.begin(), deck.end());
}

// main method for single case shuffling
int main (int argc, char** argv) {
  for (int i = 1; i <= stoi(argv[1]); i++)
    deck.push_back(i);

  printDeck();
  cout << endl;

  for (int i = 0; i < stoi(argv[2]); i++) {
    shuffle();
    printDeck();
    cout << endl;
  }

  // printDeck();

  cout << boolalpha << isInOrder() << endl;

  return 0;
}

// main method for inefficient sum calculation
// int main(int argc, char** argv) {
//   int sum = 0;
//   bool trig = false;
//   for (size_t i = 2; i <= 17000; i += 2) {
//     deck.clear();
//     deck.resize(i);
//     iota(deck.begin(), deck.end(), 0);
//
//     shuffle();
//     for (int j = 0; j < stoi(argv[1]) - 1; j++) {
//       if (isInOrder()) trig = true;
//       shuffle();
//     }
//
//
//     if (isInOrder() && !trig) {
//       cout << i << endl;
//       sum += i;
//     }
//
//     trig = false;
//   }
//
//   cout << sum << endl;
//   return 0;
// }
