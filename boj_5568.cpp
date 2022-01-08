#include <iostream>
#include <set>
#include <string>
using namespace std;

const int MAX_N = 12;
int arr[MAX_N], n, k;
bool visited[MAX_N];
set<string> ss;
void backtrack(int depth, string str)
{
	if (depth == k) {
		ss.insert(str);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			backtrack(depth + 1, str + to_string(arr[i]));
			visited[i] = false;
		}
	}
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	backtrack(0, "");
	cout << ss.size();
	return 0;
}