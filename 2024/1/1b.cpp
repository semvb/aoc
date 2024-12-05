#include <fstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    vector<int> a, b;
    string line;
    ifstream filePath("input.txt");

    if (filePath.is_open()) {
        int x, y;
        while (filePath >> x >> y) {
            a.push_back(x);
            b.push_back(y);
        }
    }

    map<int, int> freq;
    for (int x : a) { freq[x]++; }

    int sum = 0;
    for (int x : b) { sum += x * freq[x]; }

    cout << sum << "\n";
}
