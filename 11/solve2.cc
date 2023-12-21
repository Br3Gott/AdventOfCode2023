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

    vector<vector<string>> space;

    string line;
    int galaxyCount{};
    while (getline(fs, line)) {
        vector<string> vLine;
        for (char c : line) {
            if (c == '#') {
                vLine.push_back(to_string(galaxyCount++));
            } else {
                string temp{c};
                vLine.push_back(temp);
            }
        }
        space.push_back(vLine);
    }

    // expand universe
    // each row
    vector<int> toAddRow;
    for (int i{}; i < space.size(); i++) {
        size_t rowLength{space[i].size()};
        size_t dotCount{};
        for (auto s : space[i]) {
            if(s == "." || s == "*") {
                dotCount++;
            }
        }
        if (dotCount == rowLength) {
            toAddRow.push_back(i);
        }
    }
    for (auto it = rbegin(toAddRow); it != rend(toAddRow); it++) {
        vector<string> temp;
        for (int i{}; i < space[*it].size(); i++) {
            temp.push_back("*");
        }
        space.insert(begin(space) + *it, temp);
    }

    // each column
    vector<int> toAddCol;
    size_t rowLength{space.size()};
    for (int u{}; u < space[0].size() - 1; u++) {
        size_t dotCount{};
        for (int i{}; i < space.size(); i++) {
            if(space[i][u] == "." || space[i][u] == "*") {
                dotCount++;
            }
        }
        if (dotCount == rowLength) {
            toAddCol.push_back(u);
        }
    }
    for (auto it = rbegin(toAddCol); it != rend(toAddCol); it++) {
        for (int i{}; i < space.size(); i++) {
            space[i].insert(begin(space[i]) + *it, "*");
        }
    }

    map<int, pair<int,int>> galaxyPos;

    for (int i{}; i < galaxyCount; i++) {
        for (int y{}; y < space.size(); y++) {

            for (int x{}; x < space[y].size(); x++) {
                if (space[y][x] != "." && space[y][x] != "*" && stoi(space[y][x]) == i) {
                    galaxyPos[i] = make_pair(y, x);
                }
            }
        }
    }

    // get distance between all galaxies
    long long total{};
    for (int i{}; i < galaxyCount; i++) {
        for (int u{i+1}; u < galaxyCount; u++) {
            long long diffY = abs(galaxyPos[i].first - galaxyPos[u].first);
            long long diffX = abs(galaxyPos[i].second - galaxyPos[u].second);

            int lowestY = min(galaxyPos[i].first, galaxyPos[u].first);
            int highestY = max(galaxyPos[i].first, galaxyPos[u].first);
            int lowestX = min(galaxyPos[i].second, galaxyPos[u].second);
            int highestX = max(galaxyPos[i].second, galaxyPos[u].second);

            for (int i{lowestY}; i < highestY; i++) {
                if (space[i][lowestX] == "*") {
                    diffY += 1000000 - 2;
                }
            }

            for (int i{lowestX}; i < highestX; i++) {
                if (space[lowestY][i] == "*") {
                    diffX += 1000000 - 2;
                }
            }

            total += diffY + diffX;
        }
    }

    cout << "Sum of lengths: " << total << endl;
}