#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Pos {
    int x;
    int y;
};
int get_distance(Pos& hand_pos, Pos& num_pos) {
    return abs(hand_pos.x - num_pos.x) + abs(hand_pos.y - num_pos.y);
}
void move_hand(Pos& hand_pos, Pos& num_pos) {
    hand_pos.x = num_pos.x;
    hand_pos.y = num_pos.y;
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    Pos l{ 3,0 };
    Pos r{ 3,2 };
    Pos num_pos[10];
    num_pos[0] = { 3,1 };
    for (int i = 1; i <= 9; i++) {
        num_pos[i].x = (i - 1) / 3;
        num_pos[i].y = (i - 1) % 3;
    }
    for (int i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        if (num == 1 || num == 4 || num == 7) {
            answer += "L";
            move_hand(l, num_pos[num]);
        }
        else if (num == 3 || num == 6 || num == 9) {
            answer += "R";
            move_hand(r, num_pos[num]);
        }
        else {
            int dist_l = get_distance(l, num_pos[num]);
            int dist_r = get_distance(r, num_pos[num]);
            if (dist_l < dist_r) {
                answer += "L";
                move_hand(l, num_pos[num]);
            }
            else if (dist_l > dist_r) {
                answer += "R";
                move_hand(r, num_pos[num]);
            }
            else {
                if (hand == "left") {
                    answer += "L";
                    move_hand(l, num_pos[num]);
                }
                else {
                    answer += "R";
                    move_hand(r, num_pos[num]);
                }
            }
        }
    }
    return answer;
}