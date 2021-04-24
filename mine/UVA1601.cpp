/*
    UVA 1601

    by - SilLea  2021/4/23
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#define CLEAR(name, x) memset(name, x, sizeof(name))
using namespace std;
typedef pair<int, int> point;
const int maxh = 16;
char s[20][20];
int w, h, n;
int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, -1, 1 };
int dis[2][maxh][maxh][maxh][maxh][maxh][maxh];
int can_move[3];
struct node
{
    point p[3];
} start, gole;
inline void initial()
{
    CLEAR(dis, -1);
    CLEAR(can_move, 0);
}
inline bool conflict(point a, point b, point a2, point b2)//处理冲突(交换位置或者走到同一位置)
{
    return ((a2 == b2) || (a == b2 && b == a2));
}
int dbfs()
{
    queue<node> sq, eq;
    sq.push(start);
    eq.push(gole);
    dis[0][start.p[0].first][start.p[0].second][start.p[1].first][start.p[1].second][start.p[2].first][start.p[2].second] = 0;
    dis[1][gole.p[0].first][gole.p[0].second][gole.p[1].first][gole.p[1].second][gole.p[2].first][gole.p[2].second] = 0;
    while (!sq.empty() || !eq.empty())
    {
        queue<node>* q;
        int op, len;
        if (eq.empty() || sq.size() < eq.size())
        {
            op = 0;
            q = &sq;
            len = sq.size();
        }
        else
        {
            op = 1;
            q = &eq;
            len = eq.size();
        }
        for (int p = 0; p < len; p++)
        {
            node u = q->front();
            q->pop();
            point a = u.p[0], b = u.p[1], c = u.p[2];
            int& st1 = dis[op][a.first][a.second][b.first][b.second][c.first][c.second];
            int nx, ny;
            for (int i = 0; i < can_move[0]; i++)
            {
                nx = a.first + dx[i], ny = a.second + dy[i];
                if (s[nx][ny] == '#') continue;
                point a2 = make_pair(nx, ny);
                for (int j = 0; j < can_move[1]; j++)
                {
                    nx = b.first + dx[j], ny = b.second + dy[j];
                    if (s[nx][ny] == '#' && can_move[1] != 1) continue;
                    point b2 = make_pair(nx, ny);
                    if (conflict(a, b, a2, b2)) continue;
                    for (int k = 0; k < can_move[2]; k++)
                    {
                        nx = c.first + dx[k], ny = c.second + dy[k];
                        if (s[nx][ny] == '#' && can_move[2] != 1) continue;
                        point c2 = make_pair(nx, ny);
                        if (conflict(a, c, a2, c2) || conflict(b, c, b2, c2)) continue;
                        if (dis[op][a2.first][a2.second][b2.first][b2.second][c2.first][c2.second] == -1)
                        {
                            dis[op][a2.first][a2.second][b2.first][b2.second][c2.first][c2.second] = st1 + 1;
                            if (!op)
                                sq.push({ a2, b2, c2 });
                            else
                                eq.push({ a2, b2, c2 });
                        }
                        if (dis[!op][a2.first][a2.second][b2.first][b2.second][c2.first][c2.second] != -1)
                        {
                            return dis[!op][a2.first][a2.second][b2.first][b2.second][c2.first][c2.second] + dis[op][a2.first][a2.second][b2.first][b2.second][c2.first][c2.second];
                        }
                    }
                }
            }
        }
    }
    return -1;
}
int main()
{
    //freopen("text.in", "r", stdin);
    //freopen("text.out", "w", stdout);
    while (cin >> w >> h >> n && w)
    {
        initial();
        cin.get();
        for (int i = 0; i < h; i++)
            fgets(s[i], 20, stdin);
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
            {
                if (isupper(s[i][j]))
                    gole.p[s[i][j] - 'A'] = make_pair(i, j);
                if (islower(s[i][j]))
                    start.p[s[i][j] - 'a'] = make_pair(i, j);
            }
        for (int i = n; i < 3; i++)
            gole.p[i] = start.p[i] = make_pair(0, i - n), can_move[i] = 1;
        for (int i = 0; i < n; i++)
            can_move[i] = 5;
        int ans = dbfs();
        cout << ans << endl;
    }
    return 0;
}
