#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAXV = 1000000000;

enum CMD_TYPE { NUM, POP, INV, DUP, SWP, ADD, SUB, MUL, DIV, MOD };

struct Op
{
	int instruction, num;
};

int cmdToInt(const string& cmd)
{
	const string CMD_TABLE[10] = { "NUM","POP","INV","DUP","SWP","ADD","SUB","MUL","DIV","MOD" };
	for (int i = 0; i < 10; i++)
		if (cmd == CMD_TABLE[i])
			return i;
	return -1;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (true) {
		vector<Op> vCmd;

		while (true) {
			string cmd; cin >> cmd;

			int X = 0;
			if (cmd == "QUIT") return 0;
			else if (cmd == "END") break;
			else if (cmd == "NUM") {
				cin >> X;
			}

			Op op{ cmdToInt(cmd), X };
			vCmd.push_back(op);
		}

		int N; cin >> N;
		
		while (N--) {
			int V; cin >> V;

			stack<int> st;
			st.push(V);

			bool isError = false;
			for (Op op : vCmd) {
				if (isError) break;

				switch (op.instruction) {
					case NUM:
						st.push(op.num);
						break;
					case POP:
						if (st.empty()) isError = true;
						else st.pop();
						break;
					case INV:
						if (st.empty()) isError = true;
						else {
							V = st.top();
							st.pop();
							st.push(-V);
						}
						break;
					case DUP:
						if (st.empty()) isError = true;
						else st.push(st.top());
						break;
					case SWP:
						if (st.size() < 2) isError = true;
						else {
							long a = st.top(); st.pop();
							long b = st.top(); st.pop();
							st.push(a);
							st.push(b);
						}
						break;
					case ADD:
						if (st.size() < 2) isError = true;
						else {
							long a = st.top(); st.pop();
							long b = st.top(); st.pop();
							if (abs(a + b) > MAXV) isError = true;
							else st.push(a + b);
						}
						break;
					case SUB:
						if (st.size() < 2) isError = true;
						else {
							long a = st.top(); st.pop();
							long b = st.top(); st.pop();
							if (abs(b - a) > MAXV) isError = true;
							else st.push(b - a);
						}
						break;
					case MUL:
						if (st.size() < 2) isError = true;
						else {
							long a = st.top(); st.pop();
							long b = st.top(); st.pop();
							if (abs(a * b) > MAXV) isError = true;
							else st.push(a * b);
						}
						break;
					case DIV:
						if (st.size() < 2) isError = true;
						else {
							long a = st.top(); st.pop();
							long b = st.top(); st.pop();
							if (a == 0) isError = true;
							else {
								int minusCnt = (a < 0) + (b < 0);
								st.push(abs(b) / abs(a) * (minusCnt == 1 ? -1 : 1));
							}
						}
						break;
					case MOD:
						if (st.size() < 2) isError = true;
						else {
							long a = st.top(); st.pop();
							long b = st.top(); st.pop();
							if (a == 0) isError = true;
							else st.push(b % a);
						}
						break;
				}
			}

			if (isError || st.size() != 1) cout << "ERROR\n";
			else cout << st.top() << '\n';
		}
		cout << '\n';
	}
	return 0;
}