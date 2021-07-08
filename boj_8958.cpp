#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		int total = 0;
		int bonus = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'O')
				bonus++;
			else if (s[i] == 'X')
				bonus = 0;
			total += bonus;
		}
		cout << total << '\n';
	}
	return 0;
}