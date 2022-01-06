#include <iostream>
using namespace std;

struct Node {
	int left = -1;
	int right = -1;
};

Node node[27];
void pre_order(int n)
{
	Node& curr_node = node[n];

	cout << (char)('A' + n - 1);
	if (curr_node.left != -1) pre_order(curr_node.left);
	if (curr_node.right != -1) pre_order(curr_node.right);
}
void in_order(int n)
{
	Node& curr_node = node[n];

	if (curr_node.left != -1) in_order(curr_node.left);
	cout << (char)('A' + n - 1);
	if (curr_node.right != -1) in_order(curr_node.right);
}
void post_order(int n)
{
	Node& curr_node = node[n];

	if (curr_node.left != -1) post_order(curr_node.left);
	if (curr_node.right != -1) post_order(curr_node.right);
	cout << (char)('A' + n - 1);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	while (N--) {
		char A, B, C;
		cin >> A >> B >> C;
		
		int num;
		num = A - 'A' + 1;
		if (B != '.') node[num].left = B - 'A' + 1;
		if (C != '.') node[num].right = C - 'A' + 1;
	}
	pre_order(1);
	cout << '\n';
	in_order(1);
	cout << '\n';
	post_order(1);
	return 0;
}