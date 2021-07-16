#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string fill_with_zero(string& target, string& num)
{
	string ret = "";
	int cnt = num.length() - target.length();
	while (cnt--)
		ret.push_back('0');
	for (int i = 0; i < target.length(); i++)
		ret.push_back(target[i]);
	return ret;
}

string add(string& A, string& B)
{
	string ret = "";
	int carry = 0;
	for (int i = A.length() - 1; i >= 0; i--) {
		int sum = (A[i] - '0') + (B[i] - '0') + carry;
		carry = (sum > 9) ? 1 : 0;
		if (carry == 1) {
			ret.push_back((sum % 10 + '0'));
			if (i == 0)
				ret.push_back('1');
		}
		else {
			ret.push_back(sum % 10 + '0');
		}
	}
	std::reverse(ret.begin(), ret.end());
	return ret;
}

int main()
{
	string A, B;
	cin >> A >> B;
	
	if (A.length() > B.length())
		B = fill_with_zero(B, A);
	else
		A = fill_with_zero(A, B);

	cout << add(A, B);

	return 0;
}