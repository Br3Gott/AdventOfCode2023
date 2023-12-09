#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {

    ifstream fs{"input.txt"};
    ifstream fs1{"test.txt"};

    long raceTime;
    long raceDistance;

    //read time
    string line;
    getline(fs, line);

    stringstream ss{line};

    string trash;
    size_t value;

    ss >> trash;

    stringstream temp;
    while (ss >> value) {
        temp << value;
    }
    raceTime = stoi(temp.str());

    //read distance
    getline(fs, line);

    stringstream ss1{line};

    ss1 >> trash;

    stringstream temp1;
    while (ss1 >> value) {
        temp1 << value;
    }
    raceDistance = stol(temp1.str());

    // calculate all times    
    size_t waysToWin{};
    long time{raceTime};
    for (long u{}; u < time; u++) {
        long rest{time - u};
        long distance{u*rest};
        if (distance > raceDistance) {
            waysToWin++;
        }
    }

    cout << "Ways to win: " << waysToWin << endl;

    return 0;
}