#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
    static const int N = 21;
    vector<int> graph[N];
    int vis[N];
    int n, k, kase, ans, a, b;
    int road[N];
    void init()
    {
        memset(vis, 0, sizeof(vis));
        ans = 0;
        for (int i = 1; i < 21; ++i)
            graph[i].clear();
    }
    void print(int len)
    {
        cout << 1;
        for (int i = 1; i < len; ++i) cout << " " << road[i];
        cout << endl;
    }
    bool bfs()
    {
        queue<int> q;
        int v;
        q.push(1), q.push(k);
        vis[1] = 1;
        vis[k] = 2;
        if (k == 1) return true;
        while (!q.empty())
        {
            v = q.front(), q.pop();
            for (int& e : graph[v])
            {
                if (!vis[e])
                    vis[e] = vis[v], q.push(e);
                else if (vis[e] + vis[v] == 3)
                    return true;
            }
        }
        return false;
    }
    void dfs(int cur, int step)
    {
        vis[cur] = 1;
        if (cur == k)
        {
            print(step);
            ++ans;
            return;
        }
        for (int& e : graph[cur])
        {
            if (!vis[e])
            {
                road[step] = e;
                dfs(e, step + 1);
                vis[e] = 0;
            }
        }
    }
public:
    Solution() : kase(0), road{1} { }
    bool solve()
    {
        if (cin >> k)
        {
            init();
            while (cin >> a >> b && a)
            {
                graph[a].push_back(b), graph[b].push_back(a);
                n = max(n, max(a, b));
            }
            for (int i = 1; i <= n; ++i) sort(graph[i].begin(), graph[i].end());
            
            bool ok = bfs();
            memset(vis, 0, sizeof(vis));

            cout << "CASE " << ++kase << ":\n";
            if (ok) dfs(1, 1);
            else ans = 0;
            cout << "There are " << ans << " routes from the firestation to streetcorner " << k << ".\n";
            return true;
        }
        else
            return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution* solution = new Solution;
    while (solution->solve());
    delete solution;
    return 0;
}
