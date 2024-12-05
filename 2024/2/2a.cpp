#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string line;
    ifstream filePath("input.txt");

    int safe = 0;

    if (filePath.is_open()) {
        while (getline(filePath, line)) {
            stringstream s(line);
            vector<int> numbers;
            int num;

            while (s >> num) { numbers.push_back(num); }

            bool increasing = false;
            bool decreasing = false;
            bool correct    = true;

            if (numbers[0] < numbers[1]) { increasing = true; }
            if (numbers[0] > numbers[1]) { decreasing = true; }

            for (size_t i = 0; i < numbers.size() - 1; i++) {
                int difference = numbers[i] - numbers[i + 1];

                if (abs(difference) > 3 || difference == 0) {
                    correct = false;
                    break;
                }

                if (increasing && (numbers[i] > numbers[i + 1])) {
                    correct = false;
                    break;
                } else if (decreasing && (numbers[i] < numbers[i + 1])) {
                    correct = false;
                    break;
                }
            }

            if (correct) { safe++; }
        }
    }

    cout << safe << "\n";
}
