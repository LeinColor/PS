#include <iostream>
#include <string>
using namespace std;

int pos[26];
int main()
{
	fill_n(pos, sizeof(pos) / sizeof(int), -1);
	
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (pos[s[i] - 'a'] == -1)
			pos[s[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++) {
		cout << pos[i] << ' ';
	}
	return 0;
}