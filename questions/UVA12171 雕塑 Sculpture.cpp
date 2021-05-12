#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;
int dx[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };
const int maxn = 110;
int cube[maxn][maxn][maxn];
int x[maxn], y[maxn], z[maxn];
int xs[maxn], ys[maxn], zs[maxn];
class Solve
{
    int t, n, N;
    int xm, ym, zm;
public:
    Solve() { get_ans(); }
    void get_ans()
    {
        cin >> t;
        while (t--)
        {
            memset(cube, 0, sizeof(cube));
            cin >> n;
            N = 2 * n;
            for (int i = 0; i < n; i++)
                cin >> x[i * 2] >> y[i * 2] >> z[i * 2] >> x[i * 2 + 1] >> y[i * 2 + 1] >> z[i * 2 + 1],
                x[i * 2 + 1] += x[i * 2], y[i * 2 + 1] += y[i * 2], z[i * 2 + 1] += z[i * 2];
            dispersed(x, xs, xm);
            dispersed(y, ys, ym);
            dispersed(z, zs, zm);
            for (int i = 0; i < n; i++)
                for (int _x = x[2 * i]; _x < x[2 * i + 1]; _x++)
                    for (int _y = y[2 * i]; _y < y[2 * i + 1]; _y++)
                        for (int _z = z[2 * i]; _z < z[2 * i + 1]; _z++)
                            cube[_x][_y][_z] = 1;
            bfs();
        }
    }
    void bfs()
    {
        long long area = 0, vol = 0;
        queue<int> q;
        q.push(0);
        cube[0][0][0] = 2;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            int x = u & 0xff, y = (u >> 8) & 0xff, z = (u >> 16) & 0xff;
            //cout << "x: " << x << " y: " << y << " " << vol << endl;
            vol += (xs[x + 1] - xs[x]) * (ys[y + 1] - ys[y]) * (zs[z + 1] - zs[z]);
            for (int i = 0; i < 6; i++)
            {
                int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
                if (nx >= 0 && ny >= 0 && nz >= 0 && nx < xm - 1 && ny < ym - 1 && nz < zm - 1)
                {
                    if (cube[nx][ny][nz] == 1)
                    {
                         get_area(i, area, x, y, z);
                    }
                    else if (cube[nx][ny][nz] != 2)
                    {
                        cube[nx][ny][nz] = 2;
                        q.push(nx | (ny << 8) | (nz << 16));
                    }
                }
            }
        }
        cout << "" << area << " " << 1001 * 1001 * 1001 - vol << endl;
    }
    void get_area(int i, long long &area, int x, int y, int z)
    {
        if (dx[i]) area += (ys[y + 1] - ys[y]) * (zs[z + 1] - zs[z]);
        else if (dy[i]) area += (xs[x + 1] - xs[x]) * (zs[z + 1] - zs[z]);
        else if (dz[i]) area += (xs[x + 1] - xs[x]) * (ys[y + 1] - ys[y]);
    }
    void dispersed(int a[], int b[], int& m)
    {
        memcpy(b + 2, a, sizeof(int) * N);
        *b = 0, *(b + 1) = 1001;
        sort(b, b + N + 2);
        m = unique(b, b + N + 2) - b;
        for (int i = 0; i < N; i++)
            a[i] = get_id(b, m, a[i]);
    }
    inline int get_id(int a[], int& m, int& val)
    {
        return lower_bound(a, a + m, val) - a;
    }
};
int main()
{
    //freopen("text.out", "w", stdout);
    Solve solve;
    return 0;
}
/*
2
2
1 2 3 3 4 5
6 2 3 3 4 5
7
1 1 1 5 5 1
1 1 10 5 5 1
1 1 2 1 4 8
2 1 2 4 1 8
5 2 2 1 4 8
1 5 2 4 1 8
3 3 4 1 1 1
*/
