#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

bool contains(int x1, int y1, int x2, int y2) {
    return x1 <= x2 and y1 >= y2;
}

bool overlaps(int x1, int y1, int x2, int y2) {
    return (x1 >= x2 && x1 <= y2) || (y1 >= x2 && y1 <= y2);
}

int main() {

    fstream file;
    file.open("input4.txt", ios::in);

    if (file.is_open()) {
        string line;
        vector<vector<string>> lines;
        while (getline(file, line)) {
            vector<string> halves;
            char* half = strtok(&line[0], ",");
            while (half != NULL) {
                halves.push_back(half);
                half = strtok(NULL, "");
            }

            lines.push_back(halves);
        }

        int result_1 = 0;
        int result_2 = 0;

        for (auto v : lines) {
            string l = v[0] + "-" + v[1];
            vector<int> nums;
            char* num = strtok(&l[0], "-");
            while (num != NULL) {
                nums.push_back(stoll(num));
                num = strtok(NULL, "-");
            }
            
            // part 1
            if (contains(nums[0], nums[1], nums[2], nums[3]) 
                || contains(nums[2], nums[3], nums[0], nums[1])) {
                    result_1++;
            }

            // part 2
            if (overlaps(nums[0], nums[1], nums[2], nums[3])
                || overlaps(nums[2], nums[3], nums[0], nums[1])) {
                    result_2++;
                }
        }

        cout << result_1 << endl;
        cout << result_2 << endl;
    }

    return 0;
}