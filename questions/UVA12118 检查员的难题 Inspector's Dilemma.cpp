#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define cl(name, mod) memset(name, mod, sizeof(name))
using namespace std;
const int maxn = 1000 + 5;
class Solution
{
    vector<int> G[maxn];
    int v, e, t, deg[maxn], odd, even, vis[maxn], part, kase;
public:
    Solution(){ kase = 0;};
    void dfs(int u)
    {
        vis[u] = 1;
        for (int i = 0; i < G[u].size(); i++)
            if (!vis[G[u][i]])
                dfs(G[u][i]);
    }
    void count_Euler()
    {
        for (int i = 1; i <= v; i++)
        {
            if (!vis[i] && deg[i])
            {
                dfs(i);
                part++;
            }
            if (deg[i] && deg[i] % 2)
                odd++;
            else if (deg[i] && !(deg[i] % 2))
                even++;
            if (!G[i].empty())
                G[i].clear();
        }
    }
    void cout_ans()
    {
        odd -= (part - 1) * 2;//将所有连通块链接起来
        int ans = e + part - 1;
        if (odd > 2)
            ans += (odd - 1) / 2;
        if (!e) ans = 0;
        cout << "Case " << ++kase << ": " << ans * t << endl;
    }
    int get_input1()
    {
        cin >> v >> e >> t;
        return v;
    }
    void clear()
    {
        cl(deg, 0);
        cl(vis, 0);
        part = odd = even = 0;
    }
    void get_connection()
    {
        int u, v;
        for (int i = 0; i < e; i++)
        {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
            deg[u]++, deg[v]++;
        }
    }
};
int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    Solution solution;
    while (solution.get_input1())
    {
        solution.clear();
        solution.get_connection();
        solution.count_Euler();
        solution.cout_ans();
    }
    return 0;
}
