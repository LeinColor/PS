#include <iostream>
using namespace std;

int arr[10];
int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	int mul = A * B * C;
	while (mul) {
		arr[mul % 10]++;
		mul /= 10;
	}
	for (int i = 0; i <= 9; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}