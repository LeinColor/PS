#include <iostream>
using namespace std;

int F(int N)
{
	if (N == 0) return 0;
	else if (N == 1) return 1;
	return F(N - 1) + F(N - 2);
}
int main()
{
	int N;
	cin >> N;
	cout << F(N);
	return 0;
}