#include <bits/stdc++.h>
using namespace std;


string findTopCharacter(const vector<vector<char>> &array, size_t x, size_t y) {
    if (x == 0 || x == array[y].size() - 1) { return ""; }
    if (y == 0) { return ""; }

    string result = "";

    result.push_back(array[y - 1][x - 1]);
    result.push_back(array[y - 1][x + 1]);

    return result;
}

string findBottomCharacters(const vector<vector<char>> &array, size_t x, size_t y) {
    if (x == 0 || x == array[y].size() - 1) { return ""; }
    if (y == array.size() - 1) { return ""; }

    string result = "";
    result.push_back(array[y + 1][x - 1]);
    result.push_back(array[y + 1][x + 1]);

    return result;
}

int findMas(const vector<vector<char>> &array, size_t x, size_t y) {
    string topResult    = findTopCharacter(array, x, y);
    string bottomResult = findBottomCharacters(array, x, y);

    if (topResult != "" && bottomResult != "") {
        if ((topResult == "MM" && bottomResult == "SS") ||
            (topResult == "MS" && bottomResult == "MS") ||
            (topResult == "SM" && bottomResult == "SM") ||
            (topResult == "SS" && bottomResult == "MM")) {
            return 1;
        }
    }

    return 0;
}

int main() {
    ifstream filePath("input.txt");

    vector<vector<char>> array;
    string line;

    if (filePath.is_open()) {
        while (getline(filePath, line)) {
            vector<char> row(line.begin(), line.end());
            array.push_back(row);
        }
    }

    size_t height = array.size();
    size_t width  = array[0].size();

    int total = 0;

    for (size_t y = 0; y < height; y++) {
        for (size_t x = 0; x < width; x++) {
            if (array[y][x] == 'A') { total += findMas(array, x, y); }
        }
    }

    cout << total << endl;
}
