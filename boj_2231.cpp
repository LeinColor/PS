#include <iostream>
using namespace std;

int cons(int N)
{
	int ret = N;
	while (N > 0) {
		ret += N % 10;
		N /= 10;
	}
	return ret;
}
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i < N; i++) {
		int res = cons(i);
		if (res == N) {
			cout << i;
			return 0;
		}
	}
	cout << "0";
	return 0;
}