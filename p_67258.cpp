#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Car {
    int x, y, cost, dir;
};

int mx[] = { -1,1,0,0 };
int my[] = { 0,0,-1,1 };
int solution(vector<vector<int>> board) {
    int answer = 1e9;
    int N = board.size();
    Car c{ 0,0,0,-1 };

    queue<Car> q;
    q.push(c);
    board[0][0] = 1;

    while (!q.empty())
    {
        Car car = q.front();
        q.pop();

        if (car.x == N - 1 && car.y == N - 1)
        {
            if (answer > car.cost) answer = car.cost;
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = car.x + mx[i];
            int ny = car.y + my[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N || board[nx][ny] == 1)
                continue;

            int nc = 0;
            
            if (car.dir == -1 || car.dir == i)
                nc = car.cost + 100;
            else if (car.dir != i)
                nc = car.cost + 600;

            if (board[nx][ny] == 0 || board[nx][ny] >= nc) {
                board[nx][ny] = nc;
                Car next_car{ nx,ny,nc,i };
                q.push(next_car);
            }
        }
    }
    return answer;
}