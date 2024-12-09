#include <bits/stdc++.h>
using namespace std;

#define XMAS "XMAS"

int findTopXmases(const vector<vector<char>> &array, size_t x, size_t y) {
    if (y < 3) { return 0; }

    int occurences = 0;

    // Cross left
    if (x >= 3) {
        for (int i = 0; i < 4; i++) {
            if (array[y - i][x - i] != XMAS[i]) { break; }

            if (i == 3) { occurences += 1; }
        }
    }

    // Top
    for (int i = 0; i < 4; i++) {
        if (array[y - i][x] != XMAS[i]) { break; }

        if (i == 3) { occurences += 1; }
    }

    // Cross right
    if (x < array[y].size() - 3) {
        for (int i = 0; i < 4; i++) {
            if (array[y - i][x + i] != XMAS[i]) { break; }

            if (i == 3) { occurences += 1; }
        }
    }

    return occurences;
}

int findHorizontalXmases(const vector<vector<char>> &array, size_t x, size_t y) {
    int occurences = 0;

    // Left
    if (x >= 3) {
        for (int i = 0; i < 4; i++) {
            if (array[y][x - i] != XMAS[i]) { break; }

            if (i == 3) { occurences += 1; }
        }
    }

    // Right
    if (x < array[y].size() - 3) {
        for (int i = 0; i < 4; i++) {
            if (array[y][x + i] != XMAS[i]) { break; }

            if (i == 3) { occurences += 1; }
        }
    }

    return occurences;
}

int findBottomXmases(const vector<vector<char>> &array, size_t x, size_t y) {
    if (y > array.size() - 4) { return 0; }

    int occurences = 0;

    // Cross bottom left
    if (x >= 3) {
        for (int i = 0; i < 4; i++) {
            if (array[y + i][x - i] != XMAS[i]) { break; }

            if (i == 3) { occurences += 1; }
        }
    }

    // Bottom
    for (int i = 0; i < 4; i++) {
        if (array[y + i][x] != XMAS[i]) { break; }

        if (i == 3) { occurences += 1; }
    }

    // Cross bottom right
    if (x < array[y].size() - 3) {
        for (int i = 0; i < 4; i++) {
            if (array[y + i][x + i] != XMAS[i]) { break; }

            if (i == 3) { occurences += 1; }
        }
    }

    return occurences;
}

int findXmas(const vector<vector<char>> &array, size_t x, size_t y) {
    int occurences = 0;

    occurences += findTopXmases(array, x, y);
    occurences += findHorizontalXmases(array, x, y);
    occurences += findBottomXmases(array, x, y);

    return occurences;
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

    int totalOccurences = 0;

    for (size_t y = 0; y < height; y++) {
        for (size_t x = 0; x < width; x++) {
            if (array[y][x] == 'X') {
                totalOccurences += findXmas(array, x, y);
            }
        }
    }

    cout << totalOccurences << endl;
}
