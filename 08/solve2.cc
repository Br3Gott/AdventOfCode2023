#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <numeric>

using namespace std;

int main() {

    ifstream fs{"input.txt"};
    ifstream fs1{"test.txt"};
    ifstream fs2{"test2.txt"};
    ifstream fs3{"test3.txt"};

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

    vector<string> currentNodes;


    for (auto n : network) {
        if ((n.first).substr(2, 1) == "A") {
            currentNodes.push_back(n.first);
        }
    }

    long long count{};
    int  found{};
    map<string, long long> requiredSteps;
    while (requiredSteps.size() != currentNodes.size()) {
        for (auto c : instructions) {
            count++;
            for (auto& current : currentNodes) {
                if (c == 'L') {
                    current = network[current].first;
                } else {
                    current = network[current].second;
                }
                if (current.substr(2, 1) == "Z") {
                    found++;
                    if (! requiredSteps.contains(current)) {
                        requiredSteps[current] = count;
                    }
                }
            }
            
        }
    }

    long long total{-1};
    for (auto c : requiredSteps) {
        if (total == -1) {
            total = c.second;
        }
        total = lcm(total, c.second);
    }

    cout << "Found all with Z after: " << total << endl;
}
