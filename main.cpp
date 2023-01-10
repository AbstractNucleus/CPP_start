#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <random>
using namespace std;

#define SUIT_SIZE 13
#define DECK_SIZE 208 // multiples of 52


class Card {
private:
    string rank;
    char suit;

public:
    void setRank(string val) {
        rank = val;
    };

    string getRank() {
        return rank;
    };

    void setSuit(char val) {
        suit = val;
    };

    char getSuit() {
        return suit;
    };
};

class Deck
{
private:
    Card cards[DECK_SIZE];
    int n_decks;

public:
    Deck() {
        get_n_decks();
        reset();
    };

    void shuffle() {

    };

    void get_n_decks() {
        // Get the number of decks defined
        int temp = DECK_SIZE;
        n_decks = 0;
        while ((temp != 0) && (temp % 52 == 0)) {
            temp -= 52;
            n_decks += 1;
        }
    }

    void reset() {
        for (int k = 0; k < n_decks; k++) {
            // reset all suits
            for (int i = 0; i < SUIT_SIZE; i++) {
                cards[i + SUIT_SIZE * 0 + k * 0].setSuit('H');
                cards[i + SUIT_SIZE * 1 + k * 1].setSuit('D');
                cards[i + SUIT_SIZE * 2 + k * 2].setSuit('S');
                cards[i + SUIT_SIZE * 3 + k * 3].setSuit('C');
            }

            // reset all normal ranks
            for (int i = 0; i < SUIT_SIZE - 4; i++) {
                stringstream stream;
                string buffer;
                stream << i + 2;
                stream >> buffer;

                cards[i + SUIT_SIZE * 0 + k * 0].setRank(buffer);
                cards[i + SUIT_SIZE * 1 + k * 1].setRank(buffer);
                cards[i + SUIT_SIZE * 2 + k * 2].setRank(buffer);
                cards[i + SUIT_SIZE * 3 + k * 3].setRank(buffer);
            }

            // reset all royal ranks
            string royals[] = { "J", "Q", "K", "A" };
            for (int i = 0; i < 4; i++) {
                cards[i + SUIT_SIZE * 0 + 9 + k * 0].setRank(royals[i]);
                cards[i + SUIT_SIZE * 1 + 9 + k * 1].setRank(royals[i]);
                cards[i + SUIT_SIZE * 2 + 9 + k * 2].setRank(royals[i]);
                cards[i + SUIT_SIZE * 3 + 9 + k * 3].setRank(royals[i]);
            }
        }
    };

    void show() {
        for (int k = 0; k < n_decks; k++) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < SUIT_SIZE; j++) {
                    cout << cards[j + i * SUIT_SIZE + i * k].getSuit() << cards[j + i * SUIT_SIZE + i * k].getRank() << " ";
                }
                cout << "\n";
            }
        }
    };
};





int main()
{
    Deck deck;
    deck.show();

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(0, 51); // distribution in range [1, 6]

    cout << dist6(rng) << endl;

    return 0;
}