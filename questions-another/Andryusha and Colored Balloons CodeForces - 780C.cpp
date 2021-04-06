/*
    CF - 782C. Andryusha and Colored Balloons - DFS染色问题

        相邻三个城市, 颜色不能相同
    by - SilLea   2021/4/6
*/
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 100000 + 5;
vector<int> path[maxn * 2];
int color[maxn * 2];
int n, x, y, ans = 0;
void init()
{
    memset(color, 0, sizeof(color));
    for (int i = 0; i <= n; i++)
        path[i].clear();
    ans = 0;
}
void dfs(int cur, int fa)//目前节点和父节点
{
    int cnt = 1;//初始化颜色
    vector<int> &u = path[cur];//简化代码
    for (int i = 0; i < u.size(); i++) if (u[i] != fa)//防止走回去(
        {
            while (cnt == color[cur] || cnt == color[fa])//如果和父亲和爷爷颜色相同, 就自增直到不同
                cnt++;
            color[u[i]] = cnt++;//染色
            ans = max(color[u[i]], ans);
        }
    //↑↑↑, 先将所有子节点染完色后再dfs
    for (int i = 0; i < u.size(); i++) if (u[i] != fa)
            dfs(u[i], cur);
}
int main()
{
    while (cin >> n && n)
    {
        init();
        for (int i = 0; i < n - 1; i++)
        {
            cin >> x >> y;
            path[x].push_back(y);
            path[y].push_back(x);
            //无向图
        }
        color[1] = 1;//第一个城市, 颜色为1
        dfs(1, 0);
        cout << ans << endl;
        for (int i = 1; i <= n; i++)
            cout << color[i] << (i == n ? '\n' : ' ');
    }
    return 0;
}
