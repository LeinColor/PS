#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool is_exp(char c) {
    if (c == '+' || c == '-' || c == '*')
        return true;
    return false;
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> num;
    vector<char> exp, loc;
    string str_n = "";
    for (int i = 0; i < expression.size(); i++) {
        char c = expression[i];
        if (is_exp(c)) {
            num.push_back(stoi(str_n));
            str_n = "";
            if (find(exp.begin(), exp.end(), c) == exp.end())
                exp.push_back(c);
            loc.push_back(c);
        }
        else
            str_n += c;
    }

    num.push_back(stoi(str_n));
    sort(exp.begin(), exp.end());

    do {
        vector<long long> tmp_num = num;
        vector<char> tmp_loc = loc;

        for (int i = 0; i < exp.size(); i++) {
            for (int j = 0; j < tmp_loc.size(); j++) {
                if (exp[i] == tmp_loc[j]) {
                    if (tmp_loc[j] == '+')
                        tmp_num[j] += tmp_num[j + 1];
                    else if (tmp_loc[j] == '-')
                        tmp_num[j] -= tmp_num[j + 1];
                    else if (tmp_loc[j] == '*')
                        tmp_num[j] *= tmp_num[j + 1];

                    tmp_num.erase(tmp_num.begin() + j + 1);
                    tmp_loc.erase(tmp_loc.begin() + j);
                    j--;
                }
            }
        }

        if (answer < abs(tmp_num[0]))
            answer = abs(tmp_num[0]);
    } while (next_permutation(exp.begin(), exp.end()));

    return answer;
}