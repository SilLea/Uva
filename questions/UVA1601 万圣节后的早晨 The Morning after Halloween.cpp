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
const int N = 200;
//前提:每个(x, y)都有一个id 最多有 16*16*0.75 < 200 个id
int to[N][5], dis[N][N][N], num[N];
//to:一个格子所有可以走的节点
//num:一个格子可以走的点的个数, 和to配合着用
//dis:三个鬼的状态下走的步数
int w, h, n, gole[3], start[3];
//gole终点, start起点
int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, -1, 1 };
//行进方向
char s[20][20];//图
inline void initial()
{
    CLEAR(dis, -1);
}
inline int code(int a, int b, int c)//将三个鬼的状态编码成一个int
{
    return (a << 16) | (b << 8) | c;
}
inline bool conflict(int a, int b, int a2, int b2)//处理冲突(交换位置或者走到同一位置)
{
    return ((a2 == b2) || (a == b2 && b == a2));
}
int bfs()
{
    queue<int> q;
    q.push(code(start[0], start[1], start[2]));
    dis[start[0]][start[1]][start[2]] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        int a = (u >> 16) & 0xff, b = (u >> 8) & 0xff, c = u & 0xff;
        //0xff为8个1, 解码小鬼的位置
        if (a == gole[0] && b == gole[1] && c == gole[2]) return dis[a][b][c];//到达终点
        for (int i = 0; i < num[a]; i++)
        {
            for (int j = 0; j < num[b]; j++)
            {
                if (conflict(a, b, to[a][i], to[b][j])) continue;
                for (int k = 0; k < num[c]; k++)//枚举三个小鬼的行进方向
                {
                    if (conflict(a, c, to[a][i], to[c][k]) || conflict(b, c, to[b][j], to[c][k])) continue;
                    if (dis[to[a][i]][to[b][j]][to[c][k]] == -1)
                    {
                        dis[to[a][i]][to[b][j]][to[c][k]] = dis[a][b][c] + 1;
                        q.push(code(to[a][i], to[b][j], to[c][k]));
                    }
                }
            }
        }
    }
    return -1;
}
int main()
{
    while (cin >> w >> h >> n && w)
    {
        initial();
        cin.get();
        for (int i = 0; i < h; i++)
            gets(s[i]);
        int cnt = 0, x[N], y[N], id[20][20];
        //x为格子的x坐标, y同理, id为(x, y)这个格子的id
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
            {
                if (s[i][j] != '#')
                {
                    x[cnt] = i, y[cnt] = j, id[i][j] = cnt;
                    if (isupper(s[i][j]))//终点
                        gole[s[i][j] - 'A'] = cnt;
                    else if (islower(s[i][j]))//起点
                        start[s[i][j] - 'a'] = cnt;
                    cnt++;
                }
            }
        for (int i = 0; i < cnt; i++)//处理一个格子可以走的所有可能
        {
            num[i] = 0;
            for (int j = 0; j < 5; j++)
            {
                int nx = x[i] + dx[j], ny = y[i] + dy[j];
                if (s[nx][ny] != '#')
                    to[i][num[i]++] = id[nx][ny];
            }
        }
        for (int i = n; i < 3; i++)//如果小鬼的数量小于3, 将其增至3, 且终点和起点相同, 位于一个非空格的格子
        {
            num[cnt] = 1;
            to[cnt][0] = cnt;
            start[i] = gole[i] = cnt++;
        }
        int ans = bfs();
        cout << ans << endl;
    }
    return 0;
}
