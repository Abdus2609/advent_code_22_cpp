#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    fstream file;
    file.open("input1.txt", ios::in);
    
    if (file.is_open()) {
        string line;
        int curr_sum = 0;
        vector<int> sums;
        while (getline(file, line)) {
            if (line.empty()) {
                sums.push_back(curr_sum);
                curr_sum = 0;
            } else {
                curr_sum += stoll(line);
            }

        }

        // part 1
        cout << *max_element(sums.begin(), sums.end()) << "\n";

        //part 2
        sort(sums.begin(), sums.end());
        reverse(sums.begin(), sums.end());
        cout << sums[0] + sums[1] + sums[2] << "\n";

        file.close();   
    }

    return 0;
}