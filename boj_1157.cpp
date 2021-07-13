#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[26], mx = -1, idx = -1;
int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			arr[s[i] - 'A']++;
		else if (s[i] >= 'a' && s[i] <= 'z')
			arr[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (mx < arr[i]) {
			mx = arr[i];
			idx = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (mx == arr[i] && idx != i) {
			cout << '?';
			return 0;
		}
	}
	cout << (char)(idx + 'A');
	return 0;
}