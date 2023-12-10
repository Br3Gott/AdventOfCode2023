#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

int main() {

    ifstream fs{"input.txt"};
    ifstream fs1{"test.txt"};

    vector<char> valid{'A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2'};

    map<int, vector<string>> order;
    unordered_map<string, int> handScore;
    int hands{};

    string line;
    while (getline(fs, line)) {
        stringstream ss{line};
        string hand;
        int score;
        ss >> hand >> score;

        handScore[hand] = score;
        hands++;

        unordered_map<char, int> letters;
        for (auto c : hand) {
            if (letters.contains(c)) {
                letters[c]++;
            } else {
                letters[c] = 1;
            }
        }

        bool isFiveOfAKind{false};
        bool isFourOfAKind{false};
        bool isThreeOfAKind{false};
        bool isTwoPair{false};
        bool isOnePair{false};

        for (auto l : letters) {
            if (l.second == 5) {
               isFiveOfAKind = true; 
            }
            if (l.second == 4) {
                isFourOfAKind = true;
            }
            if (l.second == 3) {
                isThreeOfAKind = true;
            }
            if (l.second == 2) {
                if (isOnePair == true) {
                    isTwoPair = true;
                } else {
                    isOnePair = true;
                }
            }
        }

        if (isFiveOfAKind == true) {
            order[6].push_back(hand);
        } else if (isFourOfAKind == true) {
            order[5].push_back(hand);
        } else if (isThreeOfAKind == true && isOnePair == true) {
            order[4].push_back(hand);
        } else if (isThreeOfAKind == true) {
            order[3].push_back(hand);
        } else if (isTwoPair == true) {
            order[2].push_back(hand);
        } else if (isOnePair == true) {
            order[1].push_back(hand);
        } else {
            order[0].push_back(hand);
        }
    }

    int total{0};
    
    for (auto it = order.rbegin(); it != order.rend(); it++) {

        sort(begin((*it).second), end((*it).second), [valid](string a, string b) {
            string::iterator it1=begin(a);
            string::iterator it2=begin(b);
            while (*it1 == *it2 && it1 != end(a)) {
                it1++;
                it2++;
            };

            auto itr1 = find(begin(valid), end(valid), (*it1));
	        auto val1{distance(begin(valid), itr1)};
            auto itr2 = find(begin(valid), end(valid), (*it2));
	        auto val2{distance(begin(valid), itr2)};

            return val1 < val2;

        });

        for (auto i : (*it).second) {
            total += handScore[i] * hands--;
        }
    }
    cout << "Total: " << total << endl;
}
