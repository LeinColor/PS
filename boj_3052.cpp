#include <iostream>
using namespace std;

bool arr[42];
int main()
{
	for (int i = 0; i < 10; i++) {
		int N;
		cin >> N;
		arr[N % 42] = true;
	}

	int answer = 0;
	for (int i = 0; i < 42; i++) {
		if (arr[i])
			answer++;
	}
	cout << answer;
	return 0;
}