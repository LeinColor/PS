#include <iostream>
#include <string>
using namespace std;

int arr[26];
int main()
{
	int N;
	cin >> N;

	int answer = 0;
	while (N--) {
		string s;
		cin >> s;

		int prev = 0;
		bool flag = true;
		fill_n(arr, 26, -1);
		for (int i = 0; i < s.length(); i++) {
			if (prev != s[i]) {
				prev = s[i];
				if (arr[s[i] - 'a'] == -1) {
					arr[s[i] - 'a'] = i;
				}
				else {
					flag = false;
					break;
				}
			}
		}
		if (flag)
			answer++;
	}
	cout << answer;
	return 0;
}