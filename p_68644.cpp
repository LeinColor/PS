#include <string>
#include <vector>
using namespace std;

bool is_used[201];
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            is_used[numbers[i] + numbers[j]] = true;
        }
    }
    for (int i = 0; i < 200; i++)
        if (is_used[i]) answer.push_back(i);
    return answer;
}