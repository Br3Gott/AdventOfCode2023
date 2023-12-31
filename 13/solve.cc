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

    vector<vector<string>> sets;

    string line;
    vector<string> temp;
    while (getline(fs, line)) {
        if (line == "") {
            sets.push_back(temp);
            temp.clear();
        } else {
            temp.push_back(line);
        }
    }
    sets.push_back(temp);

    cout << "total sets: " << sets.size() << endl;

    size_t total{0};
    size_t setCount{1};

    for (auto set : sets) {
        bool found{false};
        //check regular
        for (size_t i{}; i < set.size(); i++) {
            if (i != set.size() - 1) {
                if (set[i] == set[i + 1]) {
                    int left{static_cast<int>(i)};
                    size_t right{i + 1};
                    size_t mirrored{0};
                    while (set[left] == set[right]) {
                        left--;
                        right++;
                        mirrored++;
                        if (left < 0 || right > set.size() - 1) {
                            total += 100 * (i + 1);
                            cout << "set: " << setCount << " perfect hor: " << i << " with: " << mirrored << endl;
                            found = true;
                        }
                    }
                }
            }
        }
        //check vertical
        for (size_t i{}; i < set[0].size(); i++) {
            if (i != set[0].size() - 1) {
                string first{};
                string last{};
                for (size_t u{}; u < set.size(); u++) {
                    first += set[u][i];
                    last += set[u][i + 1];
                }
                if (first == last) {
                    int left{static_cast<int>(i)};
                    size_t right{i + 1};
                    string leftstr{"start"};
                    string rightstr{"start"};
                    size_t mirrored{0};
                    while (leftstr == rightstr) {
                        left--;
                        right++;
                        string templeft{};
                        string tempright{};
                        for (size_t u{}; u < set.size(); u++) {
                            templeft += set[u][left];
                            tempright += set[u][right];
                        }
                        if (templeft != "" && tempright != "") {
                            leftstr = templeft;
                            rightstr = tempright;
                        }
                        mirrored++;
                        if (left < 0 || right > set[0].size() - 1) {
                            total += i + 1;
                            cout << "set: " << setCount << " perfect ver: " << i << " with: " << mirrored << endl;
                            found = true;
                        }
                    }
                }
            }
        }
        
        if (!found) {
            cout << "error! " << setCount << endl; 
        }
        setCount++;
    }

    cout << "Total: " << total << endl;
}