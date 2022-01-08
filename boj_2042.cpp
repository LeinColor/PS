#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

using ll = long long;

int N, M, K;
vector<ll> segment_tree;
vector<ll> arr;
ll make_segment_tree(int node, int start, int end)
{
	if (start == end) return segment_tree[node] = arr[start];

	int mid = (start + end) / 2;
	ll left_result = make_segment_tree(node * 2, start, mid);
	ll right_result = make_segment_tree(node * 2 + 1, mid + 1, end);
	segment_tree[node] = left_result + right_result;

	return segment_tree[node];
}

ll sum(int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return segment_tree[node];

	int mid = (start + end) / 2;
	ll left_result = sum(node * 2, start, mid, left, right);
	ll right_result = sum(node * 2 + 1, mid + 1, end, left, right);
	return left_result + right_result;
}

void update_segment_tree(int node, int start, int end, int index, ll diff)
{
	if (index < start || index > end) return;
	segment_tree[node] = segment_tree[node] + diff;

	if (start != end)
	{
		int mid = (start + end) / 2;
		update_segment_tree(node * 2, start, mid, index, diff);
		update_segment_tree(node * 2 + 1, mid + 1, end, index, diff);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		arr.push_back(a);
	}

	int tree_height = (int)ceil(log2(N));
	int tree_size = (1 << (tree_height + 1));
	segment_tree.resize(tree_size);
	make_segment_tree(1, 0, N - 1);

	for (int i = 0; i < M + K; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		if (a == 1) {
			ll diff = c - arr[b - 1];
			arr[b - 1] = c;
			update_segment_tree(1, 0, N - 1, b - 1, diff);
		}
		else if (a == 2) {
			cout << sum(1, 0, N - 1, b - 1, c - 1) << '\n';
		}
	}

	return 0;
}