#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll INF = 1000000001;
int main()
{
	ll X, Y, Z;
	cin >> X >> Y;
	Z = (Y / (long double)X) * 100;

	ll lo = 0, hi = INF, mid = 0, nZ;
	while (lo + 1 < hi) {
		mid = (lo + hi) / 2;
		nZ = (Y + mid) / (long double)(X + mid) * 100;
		if (nZ == Z)
			lo = mid;
		else
			hi = mid;
	}
	if (hi == INF)
		cout << "-1";
	else
		cout << hi;
	return 0;
}