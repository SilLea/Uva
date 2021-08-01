#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    static const int N = 2e5 + 10;
    int T, n, a, b, tail, head;
    vector<int> graph[N];
    int deg[N], num[N], pre[N], queue[N];
    void init()
    {
        for (int i = 0; i <= n; ++i)
        {
            graph[i].clear();
            deg[i] = 0, num[i] = 1, pre[i] = i;
        }
        tail = 0;
        head = 1;
    }
    int Find(int x)
    {
        if (x == pre[x]) return x;
        return pre[x] = Find(pre[x]);
    }
    void Union(int u, int v)
    {
        int rootu = Find(u);
        int rootv = Find(v);
        if (rootu == rootv) return;
        
        //merge u to v
        num[rootv] += num[rootu];
        pre[rootu] = rootv;
    }
    void bfs(int cur)
    {
        queue[++tail] = cur, deg[cur] = 0;
        for (head; head <= tail; ++head)
        {
            int u = queue[head];
            for (int& v : graph[u]) if (deg[v])
            {
                --deg[v];
                Union(u, v);
                if (deg[v] == 1) queue[++tail] = v, deg[v] = 0;
            }
        }
    }
public:
    Solution() { }
    void solve()
    {
        cin >> T;
        while (T--)
        {
            cin >> n;
            init();
            for (int i = 0; i < n; ++i)
            {
                cin >> a >> b;
                ++deg[a], ++deg[b];
                graph[a].push_back(b);
                graph[b].push_back(a);
            }

            for (int i = 1; i <= n; ++i)
                if (deg[i] == 1)
                    bfs(i);

            long long ans = n * (n - 1LL);
            for (int i = 1; i <= n; ++i)
                if (pre[i] == i)
                    ans -= (num[i] - 1LL) * num[i] / 2;
            cout << ans << endl;
        }
        
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution* solution = new Solution;

    solution->solve();

    delete solution;
    return 0;
}
