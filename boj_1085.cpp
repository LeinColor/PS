#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	
	int p = min(x, w - x);
	int q = min(y, h - y);
	cout << min(p, q);
	return 0;
}