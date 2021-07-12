#include <stdio.h>

int isProgression(int n)
{
	if (n < 100)
		return 1;

	int curr = n % 10;
	int next = (n / 10) % 10;
	int diff = next - curr;
	n /= 10;

	while (n >= 10) {
		curr = n % 10;
		next = (n / 10) % 10;
		if (next - curr != diff)
			return 0;
		n /= 10;
	}
	return 1;
}
int main()
{
	int N, answer = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		if (isProgression(i))
		answer += isProgression(i);
	}
	printf("%d", answer);
	return 0;
}