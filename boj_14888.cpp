#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, arr[101], op_cnt[4];
int mx = -1234567890, mn = 1234567890;
char c[] = { '+','-','*','/' }, op[101];
vector<char> tmp;
bool visited[101];
void backtrack(int current)
{
	if (current == N - 1) {
		int ret = arr[0];
		for (int i = 0; i < N - 1; i++) {
			switch (op[i]) {
			case '+':
				ret += arr[i + 1];
				break;
			case '-':
				ret -= arr[i + 1];
				break;
			case '*':
				ret *= arr[i + 1];
				break;
			case '/':
				ret /= arr[i + 1];
				break;
			default:
				break;
			}
		}
		mx = max(mx, ret);
		mn = min(mn, ret);
		return;
	}

	for (int i = 0; i < N - 1; i++) {
		if (!visited[i]) {
			visited[i] = true;
			op[current] = tmp[i];
			backtrack(current + 1);
			visited[i] = false;
		}
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> op_cnt[i];
	for (int i = 0; i < 4; i++) {
		while (op_cnt[i] > 0) {
			tmp.push_back(c[i]);
			op_cnt[i]--;
		}
	}
	backtrack(0);
	cout << mx << '\n' << mn;
	return 0;
}