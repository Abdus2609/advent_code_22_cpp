#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int main() {

    fstream file;
    file.open("input2.txt", ios::in);

    map<char, int> scores_1;
    scores_1['X'] = 1;
    scores_1['Y'] = 2;
    scores_1['Z'] = 3;

    map<char, char> strategy_1;
    strategy_1['A'] = 'Y';
    strategy_1['B'] = 'Z';
    strategy_1['C'] = 'X';

    map<char, char> mapping;
    mapping['A'] = 'X';
    mapping['B'] = 'Y';
    mapping['C'] = 'Z';


    if (file.is_open()) {
        string line;
        int result_1 = 0;
        int result_2 = 0;
        while (getline(file, line)) {
            if (line.empty()) {
                break;
            }

            char their_move = line[0];
            char my_move = line[2];
            
            // part 1
            result_1 += scores_1[my_move];
            result_1 += my_move == strategy_1[their_move] ? 6 
                : my_move == mapping[their_move] ? 3 : 0;
            
            // part 2
            if (my_move == 'X') {
                int move_score = scores_1[mapping[their_move]] - 1;
                move_score = move_score == 0 ? 3 : move_score;
                result_2 += move_score;
            } else if (my_move == 'Y') {
                int move_score = scores_1[mapping[their_move]];
                result_2 += move_score + 3;
            } else {
                int move_score = scores_1[mapping[their_move]] + 1;
                move_score = move_score == 4 ? 1 : move_score;
                result_2 += move_score + 6;
            }
        }

        cout << result_1 << endl;
        cout << result_2 << endl;
    }


    return 0;
}