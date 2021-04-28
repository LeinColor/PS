#include <string>
#include <vector>
using namespace std;

bool arr[27];
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (int i = 0; i < skill.size(); i++)
        arr[i] = skill[i] - 'A';

    for (int i = 0; i < skill_trees.size(); i++) {
        string skill_tree = skill_trees[i];

        int index = 0;
        bool is_correct = true;
        for (int j = 0; j < skill_tree.size(); j++) {
            if (arr[skill_tree[j] - 'A']) {
                if (skill_tree[j] == skill[index]) {
                    index++;
                    continue;
                }
                else {
                    is_correct = false;
                    break;
                }
            }
        }
        if (is_correct) answer++;
    }
    return answer;
}