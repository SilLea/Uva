#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 2e5 + 5;
int a[N], vis[N], edge;
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        edge = -1;
        for (int i = 1; i <= n; i++) cin >> a[i], edge = max(edge, a[i]);
        vector<pair<int, int>> ans;
        bool ok = true;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= edge; i++) vis[a[i]] = 1;
        for (int i = 1; i <= edge; i++) if (!vis[i]){ ok = false;break; }
        if (ok)
        {
            memset(vis, 0, sizeof(vis));
            for (int i = edge + 1; i <= n; i++) vis[a[i]] = 1;
            for (int i = 1; i <= n - edge; i++)if (!vis[i]){ ok = false; break; }
            if (ok) ans.push_back({edge, n - edge});
        }
        if ((edge << 1) != n)
        {
            ok = true;
            memset(vis, 0, sizeof(vis));
            for (int i = 1; i <= n - edge; i++) vis[a[i]] = 1;
            for (int i = 1; i <= n - edge; i++) if (!vis[i]){ ok = false;break; }
            if (ok)
            {
                memset(vis, 0, sizeof(vis));
                for (int i = n - edge + 1; i <= n; i++) vis[a[i]] = 1;
                for (int i = 1; i <= edge; i++) if (!vis[i]){ ok = false;break; }
                if (ok) ans.push_back({n - edge, edge});
            }
        }
        cout << ans.size() << endl;
        for (auto e:ans)
            cout << e.first << " " << e.second << endl;
    }
    return 0;
}
