#include <stdio.h>
#include <iostream>
using namespace std;

int arr[1001];
int main()
{
	int C;
	scanf("%d", &C);
	while (C--) {
		int N;
		scanf("%d", &N);

		double total = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
			total += arr[i];
		}
		double avr_score = total / (double)N;

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (avr_score < (double)arr[i])
				cnt++;
		}
		double avr_percent = (double)cnt / N * 100;
		printf("%.3lf%%\n", avr_percent);
	}
	return 0;
}