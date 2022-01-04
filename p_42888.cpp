#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

struct Info {
    string uid;
    string action;
};
vector<string> split(string& s)
{
    vector<string> ret;
    std::string::size_type offset_prev = 0, offset_curr = 0;
    
    do {
        offset_curr = s.find(' ', offset_prev);
        ret.push_back(s.substr(offset_prev, offset_curr - offset_prev));
        offset_prev = offset_curr + 1;
    } while (offset_curr != string::npos);
    return ret;
}
vector<string> solution(vector<string> record) {
    vector<string> result;
    vector<Info> log;
    unordered_map<string, string> user_map;
    for (int i = 0; i < record.size(); i++) {
        string cmd_group = record[i];
        vector<string> cmd_split = split(cmd_group);

        string cmd = cmd_split[0];
        string uid = cmd_split[1];
        Info info{ uid, cmd };
        log.push_back(info);

        if (cmd == "Enter" || cmd == "Change") {
            user_map[uid] = cmd_split[2];
        }
    }

    for (int i = 0; i < log.size(); i++) {
        string action = log[i].action;
        string uid = log[i].uid;
        string str = "";

        if (action == "Enter") {
            str = user_map[uid] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
            result.push_back(str);
        }
        else if (action == "Leave") {
            str = user_map[uid] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
            result.push_back(str);
        }
    }
    return result;
}
int main()
{
    string a = "Enter uid1234 Muzi";
    string b = "Enter uid4567 Prodo";
    string c = "Leave uid1234";
    vector<string> vs;
    vs.push_back(a);
    vs.push_back(b);
    vs.push_back(c);
    solution(vs);
    return 0;
}