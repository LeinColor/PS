#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 52;
struct Node
{
    int x, y, l;
};

queue<Node> waterQ, beaverQ;
int R, C, ans;
char arr[MAXN][MAXN];
bool beaver_visit[MAXN][MAXN], water_visit[MAXN][MAXN];
bool beaverCanMove;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void waterBFS()
{
    int sz = waterQ.size();

    for (int i = 0; i < sz; i++)
    {
        int x = waterQ.front().x;
        int y = waterQ.front().y;
        waterQ.pop();

        water_visit[x][y] = true;

        for (int j = 0; j < 4; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                continue;

            if (!water_visit[nx][ny] && arr[nx][ny] == '.')
            {
                arr[nx][ny] = '*';
                waterQ.push(Node{nx, ny, 0});
            }
        }
    }
}
void beaverBFS()
{
    int sz = beaverQ.size();
    beaverCanMove = false;

    for (int i = 0; i < sz; i++)
    {
        int x = beaverQ.front().x;
        int y = beaverQ.front().y;
        int l = beaverQ.front().l;
        beaverQ.pop();

        if (arr[x][y] == 'S')
            ans = min(ans, l);

        beaver_visit[x][y] = true;

        for (int j = 0; j < 4; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                continue;

            if (!beaver_visit[nx][ny] && (arr[nx][ny] == '.' || arr[nx][ny] == 'S'))
            {
                beaverCanMove = true;
                arr[nx][ny] = '*';
                beaverQ.push(Node{nx, ny, l + 1});
            }
        }
    }
}
int main()
{
    scanf("%d%d", &R, &C);
    for (int i = 0; i < R; i++)
    {
        scanf("%s", &arr[i]);
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (arr[i][j] == 'D')
                beaverQ.push(Node{i, j, 1});
            else if (arr[i][j] == '*')
                waterQ.push(Node{i, j, 0});
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            waterBFS();
            beaverBFS();
            if (!beaverCanMove)
            {
                printf("KAKTUS");
                return 0;
            }
        }
    }
    printf("%d", ans);
    return 0;
}