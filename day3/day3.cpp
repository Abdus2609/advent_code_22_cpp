#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int priority(char c) {
    if (c >= 'A' and c <= 'Z') {
        return (int) (c - 'A') + 26;
    }
    
    return (int) (c - 'a');
}

int main() {

    fstream file;
    file.open("input3.txt", ios::in);

    if (file.is_open()) {
        string line;
        vector<string> lines;
        while (getline(file, line)) {
            lines.push_back(line);
        }

        // part 1
        int result_1 = 0;
        for (string l : lines) {
            int mid = l.length() / 2;
            string left = l.substr(0, mid);
            string right = l.substr(mid, l.length());

            for (int i = 0; i < left.length(); i++) {
                if (right.find(left[i]) != string::npos) {
                    result_1 += priority(left[i]) + 1;
                    break;
                }
            }
        }

        cout << result_1 << endl;

        // part 2
        int result_2 = 0;
        for (int i = 0; i < lines.size(); i += 3) {
            string line = lines[i];
            for (int j = 0; j < line.size(); j++) {
                if (lines[i + 1].find(line[j]) != string::npos 
                    && lines[i + 2].find(line[j]) != string::npos) {
                        result_2 += priority(line[j]) + 1;
                        break;
                    }
            }
        }

        cout << result_2 << endl;
    }

    return 0;
}