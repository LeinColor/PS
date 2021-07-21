#include <iostream>
using namespace std;

struct Person {
	int x, y;
};
Person p[51];
int ranks[51];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i].x >> p[i].y;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (p[i].x < p[j].x && p[i].y < p[j].y) {
				ranks[i]++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << ranks[i] + 1 << ' ';
	}
	return 0;
}