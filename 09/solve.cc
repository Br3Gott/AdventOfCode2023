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
    
    string line;
    int total{};
    int totalStart{};

    while (getline(fs, line)) {
        map<int, vector<int>> layers;
        stringstream ss{line};
        int num;
        while (ss >> num) {
            layers[0].push_back(num);
        }

        int currentLayer{};
        int zeroes{};

        while (zeroes < layers[currentLayer].size()) {
            zeroes = 0;
            for (int i{}; i < layers[currentLayer].size(); i++) {
                if (i != layers[currentLayer].size() - 1) {
                    int current{layers[currentLayer][i]};
                    int next{layers[currentLayer][i + 1] };
                    layers[currentLayer+1].push_back((next - current));
                }
                if (layers[currentLayer][i] == 0) {
                    zeroes++;
                }
            }
            currentLayer++;
        }

        for (int c{currentLayer-2}; c >= 0; c--) {
            layers[c].push_back(layers[c+1][layers[c+1].size()-1]+layers[c][layers[c].size()-1]);
            layers[c].insert(begin(layers[c]), layers[c][0]-layers[c+1][0]);
        }

        total += layers[0][layers[0].size()-1];
        totalStart += layers[0][0];
    }

    cout << "Total: " << total << endl;
    cout << "TotalStart: " << totalStart << endl;
}