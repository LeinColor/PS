#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    unordered_map<int, int> um;
    for (int i = 0; i < win_nums.size(); i++) {
        int win_num = win_nums[i];
        um[win_num] = 1;
    }

    int min_rank = 0;
    int max_rank = 0;
    for (int i = 0; i < lottos.size(); i++) {
        int lotto = lottos[i];
        if (lotto != 0) {
            if (um[lotto] == 1) {
                min_rank++;
                max_rank++;
            }
        }
        else {
            max_rank++;
        }
    }
    min_rank = min(6, 7 - min_rank);
    max_rank = min(6, 7 - max_rank);
    answer.push_back(max_rank);
    answer.push_back(min_rank);
    return answer;
}