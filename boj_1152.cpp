#include <iostream>
#include <string.h>
using namespace std;

char s[1000001];
int main()
{
	cin.getline(s, 1000000);
	int len = strlen(s);
	int answer = 0;
	bool isSpace = false;
	if (s[0] != ' ')
		answer++;
	for (int i = 0; i < len; i++) {
		if (s[i] == ' ')
			isSpace = true;
		else if (isSpace && s[i] != ' ' && s[i] != '\0') {
			isSpace = false;
			answer++;
		}
	}
	cout << answer;
	return 0;
}