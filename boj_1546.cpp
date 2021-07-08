#include <iostream>
#include <algorithm>
using namespace std;

double arr[1001];
int main()
{
	int N;
	double M = 0, answer = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		M = max(M, arr[i]);
	}
	for (int i = 0; i < N; i++) {
		answer += arr[i] / M * 100;
	}
	cout << answer / N;
	return 0;
}