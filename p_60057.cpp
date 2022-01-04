#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = s.size();

    for (int i = 1; i <= s.size() / 2; i++) {
        string dst, tmp;

        int cnt = 1;
        tmp = s.substr(0, i);

        for (int j = i; j < s.size(); j += i) {
            if (tmp == s.substr(j, i)) cnt++;
            else {
                if (cnt > 1) dst += to_string(cnt);
                dst += tmp;
                tmp = s.substr(j, i);
                cnt = 1;
            }
        }

        if (cnt > 1) dst += to_string(cnt);

        dst += tmp;
        answer = min(answer, (int)dst.size());
    }
    return answer;
}

int main()
{
    return 0;
}