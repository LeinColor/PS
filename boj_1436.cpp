#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int count = 0;
    int M = 666;

    while (count < N) {
        string s = std::to_string(M);
        if (s.find("666") != -1)
            count++;
        if (count == N) {
            cout << M;
            return 0;
        }
        M++;
    }
    return 0;
}