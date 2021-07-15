#include <iostream>
using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	if (C - B > 0)
		cout << A / (C - B) + 1;
	else
		cout << "-1";
	return 0;
}