#include<bits/stdc++.h>
using namespace std;
int N, Q;
struct Point
{
    int x, y;
};
int dist[5000+10][5000+10];
int dx[] = {-1, -1, -1, 1, 1, 1, 0, 0};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};
queue<Point> q;
void bfs()
{
    while(!q.empty())
    {
        Point u = q.front();
        q.pop();
        for(int i = 0; i < 8; i++)
        {
            int nx = u.x + dx[i], ny = u.y + dy[i];
            if(nx < 0 || nx > 5000 || ny < 0 || ny > 5000)
                continue;
            if(dist[nx][ny] == -1)
            {
                Point tmp = u;
                tmp.x = nx, tmp.y = ny;
                dist[nx][ny] = dist[u.x][u.y] + 1;
                q.push(tmp);
            }
        }
    }
}
int main()
{
    scanf("%d%d", &N, &Q);
    memset(dist, -1, sizeof(dist));
    while(!q.empty())
        q.pop();
    for(int i = 0; i < N; i++)
    {
        Point guard;
        scanf("%d%d", &guard.x, &guard.y);
        dist[guard.x][guard.y] = 0;
        q.push(guard);
    }
    bfs();
    for(int i = 0; i < Q; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", dist[a][b]);
    }
}
