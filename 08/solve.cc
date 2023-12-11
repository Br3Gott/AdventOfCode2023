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
    ifstream fs2{"test2.txt"};

    unordered_map<string, pair<string, string>> network;

    string instructions;

    getline(fs, instructions);

    string line;
    while (getline(fs, line)) {
        if (line.size() > 0) {
            string location{line.substr(0, 3)};
            string left{line.substr(7, 3)};
            string right{line.substr(12, 3)};
            network[location] = make_pair(left, right);
        }
    }

    string current{"AAA"};
    int count{};
    while (current != "ZZZ") {
        for (auto c : instructions) {
            if (c == 'L') {
                current = network[current].first;
            } else {
                current = network[current].second;
            }
            count++;
            if (current == "ZZZ") {
                break;
            }
        }
    }
    
    cout << "Found ZZZ after: " << count << endl;
}
