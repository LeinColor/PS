#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 101;
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
bool visited[MAX_SIZE][MAX_SIZE];
struct Pos {
    int x;
    int y;
};
int bfs(int x, int y, int m, int n, int start_value, vector<vector<int>>& picture) {
    queue<Pos> q;
    int ret = 1;
    int size = picture.size();

    visited[x][y] = true;
    q.push({ x,y });

    while (!q.empty()) {
        Pos& pos = q.front();
        q.pop();

        int curr_x = pos.x;
        int curr_y = pos.y;

        for (int i = 0; i < 4; i++) {
            int next_x = curr_x + dx[i];
            int next_y = curr_y + dy[i];

            if (next_x < 0 || next_y < 0 || next_x >= m || next_y >= n)
                continue;

            if (!visited[next_x][next_y] && picture[next_x][next_y] == start_value) {
                visited[next_x][next_y] = true;
                ret++;
                q.push({ next_x,next_y});
            }
        }
    }
    return ret;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    for (int i = 0; i < MAX_SIZE; i++)
        for (int j = 0; j < MAX_SIZE; j++)
            visited[i][j] = false;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && picture[i][j] != 0) {
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, bfs(i, j, m, n, picture[i][j], picture));
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main()
{
    vector<vector<int>> a{ {1,1,1,0},{1,2,2,0},{1,0,0,1},{0,0,0,1},{0,0,0,3},{0,0,0,3} };
    vector<int> ans = solution(6, 4, a);
    return 0;
}