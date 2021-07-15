#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int answer = 1;
	int bound = 1;
	int factor = 6;

	while (bound < N) {
		bound += factor;
		factor += 6;
		answer++;
	}
	cout << answer;
	return 0;
}