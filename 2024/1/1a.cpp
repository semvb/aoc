#include <algorithm>
#include <fstream>
#include <iostream>
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

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long sum = 0;
    for (size_t i = 0; i < a.size(); i++) { sum += abs(a[i] - b[i]); }

    cout << sum << "\n";
}
