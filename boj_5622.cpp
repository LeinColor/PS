#include <iostream>
#include <string>
using namespace std;

int dial[] = { 2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9 };
int main()
{
	string s;
	cin >> s;

	int answer = 0;
	for (int i = 0; i < s.length(); i++) {
		answer += dial[s[i] - 'A'] + 1;
	}
	cout << answer;
	return 0;
}