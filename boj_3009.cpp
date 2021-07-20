#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vx, vy;
	for (int i = 0; i < 3; i++) {
		int x, y;
		cin >> x >> y;
		vx.push_back(x);
		vy.push_back(y);
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	if (vx[1] == vx[0]) cout << vx[2] << ' ';
	else cout << vx[0] << ' ';
	if (vy[1] == vy[0]) cout << vy[2];
	else cout << vy[0];
	return 0;
}