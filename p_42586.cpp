//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<int> solution(vector<int> progresses, vector<int> speeds) {
//    vector<int> answer;
//    return answer;
//}

#include <iostream>
using namespace std;

int main()
{
	int* b = new int;
	*b = 5;
	cout << *(&b) << endl;
	cout <<(&b) << endl;
	return 0;
}