#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> origin;
vector<int> compressed;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		origin.push_back(x);
		compressed.push_back(x);
	}
	sort(compressed.begin(), compressed.end());
	compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());
	for (int i = 0; i < origin.size(); i++) {
		cout << lower_bound(compressed.begin(), compressed.end(), origin[i]) - compressed.begin() << ' ';
	}
	return 0;
}