#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int R;
		cin >> R;

		string s;
		cin >> s;

		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < R; j++) {
				cout << s[i];
			}
		}
		cout << '\n';
	}
	return 0;
}