/*
    UVA 810

    by - SilLea  2021/4/21
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#define CLEAR(name, x) memset(name, x, sizeof(name))
using namespace std;
struct node
{
    int x, y, u, f, p;
} q[100000];
const int maxn = 12;
int dice[maxn][maxn];
int the_left[7][7];
bool vis[maxn][maxn][7][7];
int r, c, sx, sy, su, sf;
vector<int> ans;
void initial()
{
    ans.clear();
    CLEAR(vis, false);
    CLEAR(dice, 0);
}
void print_ans(int _end)
{
    while (~_end)
    {
        ans.push_back(_end);
        _end = q[_end].p;
    }
    int cnt = 0;
    for (int i = ans.size() - 1; i > 0; i--)
    {
        cnt++;
        cout << '(' << q[ans[i]].x << ',' << q[ans[i]].y << "),";
        if (cnt % 9 == 0)
            cout << endl << "  ";
    }
    cout << '(' << q[ans[0]].x << ',' << q[ans[0]].y << ")";
    cout << endl;
}
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };
void get_next_uf(int u, int f, int& nu, int& nf, int mod)
{
    if (mod == 0) nu = f, nf = 7 - u;//上
    if (mod == 1) nf = u, nu = 7 - f;//下
    if (mod == 3) nf = f, nu = 7 - the_left[u][f];//左
    if (mod == 2) nf = f, nu = the_left[u][f];//右
}
void bfs()
{
    int head = 0, rear = 0;
    q[rear].x = sx, q[rear].y = sy, q[rear].u = su, q[rear].f = sf, q[rear].p = -1;
    rear++;
    while (head < rear)
    {
        node &t = q[head];
        for (int i = 0; i < 4; i++)
        {
            int nx = t.x + dx[i], ny = t.y + dy[i];
            if (~dice[nx][ny] && t.u != dice[nx][ny]) continue;//不符合条件(包含了越界诊断)
            if (nx == sx && ny == sy)//返回了起点
            {
                q[rear].x = nx;
                q[rear].y = ny;
                q[rear].p = head;
                print_ans(rear);
                return;
            }
            int nu, nf;
            get_next_uf(t.u, t.f, nu, nf, i);
            if (vis[nx][ny][nu][nf]) continue;
            vis[nx][ny][nu][nf] = true;
//            printf("(%d %d) ", nx, ny);
            q[rear].u = nu, q[rear].f = nf, q[rear].x = nx, q[rear].y = ny, q[rear].p = head;
            rear++;
        }
        head++;
    }
    cout << "No Solution Possible" << endl;
}
int main()
{
    the_left[1][2] = 3, the_left[1][3] = 5, the_left[1][5] = 4, the_left[1][4] = 2;
    the_left[2][1] = 4, the_left[2][3] = 1, the_left[2][4] = 6, the_left[2][6] = 3;
    the_left[3][6] = 5, the_left[3][5] = 1, the_left[3][1] = 2, the_left[3][2] = 6;
    the_left[4][6] = 2, the_left[4][2] = 1, the_left[4][1] = 5, the_left[4][5] = 6;
    the_left[5][6] = 4, the_left[5][4] = 1, the_left[5][1] = 3, the_left[5][3] = 6;
    the_left[6][4] = 5, the_left[6][5] = 3, the_left[6][3] = 2, the_left[6][2] = 4;
    string name;
    while (cin >> name && name != "END")
    {
        initial();
        cout << name << endl << "  ";
        cin >> r >> c >> sx >> sy >> su >> sf;
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                cin >> dice[i][j];
        bfs();
    }
    return 0;
}
