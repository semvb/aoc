#include <fstream>
#include <iostream>
#include <regex>
using namespace std;

int main() {
    ifstream filePath("input.txt");
    string input, line;

    if (filePath.is_open()) {
        while (getline(filePath, line)) { input += line; }
    }

    int total  = 0;
    bool doMul = true;

    smatch match;
    regex regexExpression(R"(mul\((\d+),(\d+)\)|do\(\)|don't\(\))");

    while (regex_search(input, match, regexExpression)) {
        if (match[0].str() == "do()") {
            doMul = true;
        } else if (match[0].str() == "don't()") {
            doMul = false;
        } else if (doMul) {
            int x = stoi(match[1].str());
            int y = stoi(match[2].str());

            total += x * y;
        }

        input = match.suffix().str();
    }

    cout << total << endl;
}
