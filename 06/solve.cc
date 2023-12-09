#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {

    ifstream fs{"input.txt"};
    ifstream fs1{"test.txt"};

    vector<size_t> raceTimes;
    vector<size_t> raceDistances;

    //read times
    string line;
    getline(fs, line);

    stringstream ss{line};

    string trash;
    size_t value;

    ss >> trash;

    while (ss >> value) {
        raceTimes.push_back(value);
    }

    //read distances
    getline(fs, line);

    stringstream ss1{line};

    ss1 >> trash;

    while (ss1 >> value) {
        raceDistances.push_back(value);
    }

    // calculate all times
    size_t result{1};
    for (size_t i{}; i < raceTimes.size(); i++ ) {
        size_t waysToWin{};
        size_t time{raceTimes[i]};
        for (size_t u{}; u < time; u++) {
            size_t rest{time - u};
            size_t distance{u*rest};
            if (distance > raceDistances[i]) {
                waysToWin++;
            }
        }
        result *= waysToWin;
    }

    cout << "Ways to win result: " << result << endl;

    return 0;
}