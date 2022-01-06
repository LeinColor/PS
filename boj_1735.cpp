#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	int u = a * d + b * c;
	int l = b * d;

	int m = gcd(max(u, l), min(u, l));
	cout << u / m << " " << l / m;

	return 0;
}