#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<iomanip>

//#include "another.cpp"
using namespace std;
class uva1354
{
    static const int N = 6;
    int s;
    double r, w[N], sum[1 << N];
    bool vis[1 << N];
    struct Tree
    {
        double l = 0.0, r = 0.0;
        Tree() : l(0), r(0){}
    };
    vector<Tree> tree[1 << N];
    void dfs(int cur)
    {
        if (vis[cur]) return;//剪枝
        vis[cur] = true;
        if (((cur - 1) & cur) == 0) { tree[cur].push_back(Tree()); return; }//只剩一个元素,为叶子
        for (int subLeft = (cur - 1) & cur; subLeft > 0; subLeft = (subLeft - 1) & cur)//除去空集和全集
        {
            int subRight = subLeft ^ cur;//左集的补集,右集
            dfs(subLeft); dfs(subRight);//扩展左右子集
            double tl = sum[subRight] / sum[cur];//左枝离根的距离
            double tr = sum[subLeft] / sum[cur];//右枝离根的距离
            for (auto &a : tree[subLeft])
                for (auto &b : tree[subRight])//遍历左右子树的所有组合
                {
                    Tree t;
                    t.l = max(a.l + tl, b.l - tr);
                    t.r = max(b.r + tr, a.r - tl);
                    if (t.l + t.r < r)
                    {
                        tree[cur].push_back(t);
                        //cout << tl << " " << tr << " ";
                        //cout << t.l << "." << t.r << "." << cur <<endl;
                    }
                }
        }
    }
public:
    uva1354() {cout << setprecision(10) << setiosflags(ios::fixed); }
    void start()
    {
        int t;
        cin >> t;
        while (t--)
        {
            cin >> r >> s;
            for (int i = 0; i < s; i++) cin >> w[i];
            int all = (1 << s) - 1;//全集
            for (int i = 0; i <= all; i++)
            {
                sum[i] = 0.0, tree[i].clear();//初始化
                for (int j = 0; j < s; j++)
                    if (i & (1 << j))
                        sum[i] += w[j];//枚举子集并将所有子集加和
            }
            memset(vis, false, sizeof(vis));
            dfs(all);
            double ans(-1.0);
            for (auto &e : tree[all]) ans = max(ans, e.l + e.r);
            cout << ans << endl;
        }
    }
}solve;
int main()
{
    solve.start();
    return 0;
}
