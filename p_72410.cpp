#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

const string acceptableTable = "abcdefghijklmnopqrstuvwxyz0123456789-_.";
char upperToLower(char alphabet)
{
    return alphabet - 'A' + 'a';
}
string solution(string new_id) {
    unordered_map<char, int> um;

    int begin_pos = -1;
    int end_pos = -1;

    for (int i = 0; i < acceptableTable.size(); i++)
        um[acceptableTable[i]] = 1;

    for (int i = 0; i < new_id.size(); i++) {
        if (isalpha(new_id[i]) && isupper(new_id[i]))
            new_id[i] = upperToLower(new_id[i]);
    }

    for (int i = 0; i < new_id.size(); i++) {
        if (um.count(new_id[i]) == 0) {
            new_id.erase(new_id.begin() + i);
            i--;
        }
    }

    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] == '.') {
            if (begin_pos == -1) begin_pos = i;
            end_pos = i;
        }

        if (new_id[i] != '.' || (new_id[i] == '.' && i == new_id.size() - 1)) {
            if (begin_pos != -1 && begin_pos != end_pos) {
                new_id.erase(new_id.begin() + begin_pos, new_id.begin() + end_pos);
                i -= (end_pos - begin_pos);
            }
            begin_pos = end_pos = -1;
        }
    }

    if (!new_id.empty() && new_id[0] == '.')
        new_id.erase(new_id.begin());
    if (!new_id.empty() && new_id[new_id.size() - 1] == '.')
        new_id.erase(new_id.end() - 1);

    if (new_id.empty())
        new_id = "a";

    if (new_id.size() >= 16) {
        new_id.erase(new_id.begin() + 15, new_id.end());
        if (new_id[new_id.size() - 1] == '.')
            new_id.pop_back();
    }

    while (new_id.size() <= 2)
        new_id.push_back(new_id[new_id.size() - 1]);

    return new_id;
}

int main()
{
    solution(".a..b....c....d..");
    return 0;
}