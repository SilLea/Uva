/*
    UVA 11853
        先用一次dfs(连通块)得出是否可以安全通过, 再去考虑位置问题
        问题2：如何找到左右边界的入出口？
        答案2：在所有从上边界开始的连通块中，取与左右边界交点最南的点
    by - SilLea   2021/3/27
*/
#include<bits/stdc++.h>
using namespace std;
#define SQU(x) ((x)*(x))
const int maxn = 1010;
int n, vis[maxn];
double x[maxn], y[maxn], r[maxn], ansr, ansl;
bool dis(int c1, int c2)
{
    return SQU(x[c1]-x[c2]) + SQU(y[c1]-y[c2]) < SQU(r[c1]+r[c2]);
}
void min_(double &ans, double &t)
{
    if (t < ans) ans = t;
}
void update_ans(int cur)
{
    if (x[cur] < r[cur])   // 与左边界相交
    {
        double t = y[cur] - sqrt(SQU(r[cur]) - SQU(x[cur]));
       min_(ansl, t);
    }
    if (x[cur] + r[cur] > 1000.0)   // 与右边界相交
    {
        double t = y[cur] - sqrt(SQU(r[cur]) - SQU(1000-x[cur]));
        min_(ansr, t);
    }
}
bool dfs(int cur)
{
    vis[cur] = 1; // 标记为已访问
    if (y[cur] < r[cur])
        return true;
    for (int i=0; i < n; i ++)
        if (vis[i]==0 && dis(cur,i) && dfs(i))
            return true; // 遍历连通块
    update_ans(cur); // 计算左右边界
    return false;
}

int main()
{
    while (cin >> n)
    {
        memset(vis, 0, sizeof(vis));
        ansl = ansr = 1000.0;
        for (int i = 0; i < n; i++)
            scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
        bool ok = true;
        for (int i=0; i < n && ok; i ++) // 遍历n个圆
            if (y[i] + r[i] > 1000.0 && dfs(i))   // 与上边界相交且能走到下边界
                ok = false;
        if (ok) printf("0.00 %.2lf 1000.00 %.2lf\n", ansl, ansr);
        else puts("IMPOSSIBLE");
    }
    return 0;
}
