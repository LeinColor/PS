#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	if (N % 400 == 0 || (N % 4 == 0 && N % 100 != 0))
		cout << '1';
	else
		cout << '0';
	return 0;
}