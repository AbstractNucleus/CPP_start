#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <random>

using namespace std;

#define SUIT_SIZE 13
#define DECK_SIZE 52 // multiples of 52 (not implemented)


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

public:
    Deck() {
        reset();
    };

    void shuffle() {
        Card temp_deck[DECK_SIZE];
        int indexes[DECK_SIZE];
        for (int i = i; i < DECK_SIZE; i++) {
            indexes[i] = -1;
        }

        random_device dev;
        mt19937 rng(dev());
        uniform_int_distribution<mt19937::result_type> dist_deck(0, DECK_SIZE - 1);
        int num;

        for (int i = 0; i < DECK_SIZE; i++) {
            num = dist_deck(rng);
            for (int j = 0; j < DECK_SIZE; j++) {
                if (num == indexes[j]) {
                    num = dist_deck(rng);
                    j = 0;
                }
            }
            indexes[i] = num;
        }

        for (int i = 0; i < DECK_SIZE; i++) {
            temp_deck[i].setRank(cards[i].getRank());
            temp_deck[i].setSuit(cards[i].getSuit());
        }

        for (int i = 0; i < DECK_SIZE; i++) {
            cards[indexes[i]].setRank(temp_deck[i].getRank());
            cards[indexes[i]].setSuit(temp_deck[i].getSuit());
        }
    };

    void reset() {

        // reset all suits
        for (int i = 0; i < SUIT_SIZE; i++) {
            cards[i + SUIT_SIZE * 0].setSuit('H');
            cards[i + SUIT_SIZE * 1].setSuit('D');
            cards[i + SUIT_SIZE * 2].setSuit('S');
            cards[i + SUIT_SIZE * 3].setSuit('C');
        }

        // reset all normal ranks
        for (int i = 0; i < SUIT_SIZE - 4; i++) {
            stringstream stream;
            string buffer;
            stream << i + 2;
            stream >> buffer;

            cards[i + SUIT_SIZE * 0].setRank(buffer);
            cards[i + SUIT_SIZE * 1].setRank(buffer);
            cards[i + SUIT_SIZE * 2].setRank(buffer);
            cards[i + SUIT_SIZE * 3].setRank(buffer);
        }

        // reset all royal ranks
        string royals[] = { "J", "Q", "K", "A" };
        for (int i = 0; i < 4; i++) {
            cards[i + SUIT_SIZE * 0 + 9].setRank(royals[i]);
            cards[i + SUIT_SIZE * 1 + 9].setRank(royals[i]);
            cards[i + SUIT_SIZE * 2 + 9].setRank(royals[i]);
            cards[i + SUIT_SIZE * 3 + 9].setRank(royals[i]);
        }

    };

    void show() {
        cout << "\n";
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < SUIT_SIZE; j++) {
                cout << cards[j + i * SUIT_SIZE].getSuit() << cards[j + i * SUIT_SIZE].getRank() << " ";
            }
            cout << "\n";
        }

    };

    Card getCard(int index) {
        return cards[index];
    };

    Card* getCards() {
        return cards;
    }
};

class Menu {
private:
    string menu_items[2] = { "New game", "Print all cards" };

    void printMenu() {
        cout << endl;
        for (int i = 0; i < sizeof(menu_items) / sizeof(string); i++) {
            cout << "\t[ " << i + 1 << " ]\t" << menu_items[i] << endl;
        }
        cout << "\n\t[ 0 ]\t" << "Exit";
        cout << endl;
    };

    void menuFunction(string response) {
        int choice;
        int starts_w_int = 0;
        int has_char = 0;
        int is_number;
        char ints[10] = { '1','2','3','4','5','6','7','8','9','0' };

        try {
            // firstly check if the first character in response is an in
            for (int i = 0; i < 10; i++) {
                if (response[0] == ints[i]) {
                    starts_w_int = 1;
                }
            }
            if (!starts_w_int) {
                throw(0);
            }

            // Check if there is something other than numbers in response
            for (int i = 0; i < response.length(); i++) {
                is_number = 0;
                for (int j = 0; j < 10; j++) {
                    if (response[i] == ints[j]) {
                        is_number = 1;
                    }
                    if ((j == 9) && (is_number == 0)) {
                        throw(0);
                    }
                }
            }
        }
        catch (...) {
            system("cls");
            cout << "Invalid input: " << response << endl;
            return;
        };

        stringstream temp;
        temp << response;
        temp >> choice;

        switch (choice) {
        case 0:
            system("cls");
            exit(0);
            break;
        case 1:
            system("cls");
            break;
        case 2:
            system("cls");
            cout << "All cards" << endl;
            break;
        default:
            system("cls");
            cout << "Invalid choice: " << choice << endl;
            break;
        }
    };

    string prompt() {
        string response;
        cout << "\n\t> ";
        cin >> response;
        cout << "\n";
        return response;
    };

public:
    Menu() {
        system("cls");
    };

    void startMenuLoop() {
        while (1) {
            printMenu();
            string response = prompt();
            menuFunction(response);
        }
    }


};
