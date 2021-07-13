#include <iostream>
#include <math.h>
using namespace std;

int reverse(int n)
{
	int tmp = n;
	int digit_count = 0;
	while (tmp > 0) {
		tmp /= 10;
		digit_count++;
	}

	int ret = 0;
	while (digit_count > 0) {
		ret += (n % 10) * pow(10, digit_count - 1);
		digit_count--;
		n /= 10;
	}
	return ret;
}
int main()
{
	int A, B;
	cin >> A >> B;
	cout << max(reverse(A), reverse(B));
	return 0;
}