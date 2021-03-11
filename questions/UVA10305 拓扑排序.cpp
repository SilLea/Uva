/*
    (lrj代码):
    如果存在环路，那么拓扑排序就无法进行
    用一个vis数组记录每个点的访问状况，值为-1时表示正在访问，如果递归时重复的遇到这个状态就说明存在环路，为0时表示还没有访问，为1时表示已经访问过了
    用一个ans数组记录答案，记录答案时要从后往前，想一想为什么(提示：递归)

    by - SilLea   2021/3/11
*/
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 100 + 5;
bool quest[maxn][maxn];
int vis[maxn], ans[maxn];
int n, m, t;
void init()
{
    memset(quest, 0, sizeof(quest));
    memset(vis, 0, sizeof(vis));
    memset(ans, 0, sizeof(ans));
    t = n;
}
bool dfs(int u)
{
    vis[u] = -1;//访问标志
    for (int v = 0; v <= n; v++) if (quest[u][v])
    {
        if (vis[v] == -1)return false;//存在有向环，失败退出
        else if (!vis[v] && !dfs(v))return false;
    }
    vis[u] = 1;
    ans[--t] = u;
    return true;
}
bool toposort()
{
    for (int u = 1; u < n; u++)if (!vis[u])
    {
        if (!dfs(u)) return false;
    }
    return true;
}
int main()
{
    int u, v;
    while (cin >> n >> m && n)
    {
        init();
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            quest[u - 1][v - 1] = 1;//构建无向图
        }
        bool is_ileagle = toposort();
        for (int i = 0; i < n; i++)
        {
            if (i) cout << ' ';
            cout << ans[i] + 1;
        }
        cout << endl;
    }
    return 0;
}
