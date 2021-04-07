/*
    Spatial Structures UVA - 806

    题目就是把[UVA297] 四分树正逆走一遍。（跟着紫书做过来的估计都做了
    那么思路就很简单了，正着来一个dfs，反着来一个dfs。
    这里的dfs1是由图到数列。直接暴力求得区域内1的个数即可，其他的看代码应该没问题。
    dfs2是由数列到图，对于每个数调用一遍dfs染色即可。
    进制之间的转换直接在递归时处理就可以。
    (上述题解来自洛谷大佬 ReModer)
    by - SilLea   2021/4/7
*/
#include<algorithm>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 65, pooww[] = {1, 5, 25, 125, 625, 3125, 15625, 78125, 390625};
char graph[maxn][maxn];
int int_graph[maxn];
int n, ans, cnt, kase = 0;
void init()
{
    ans = cnt = 0;
    memset(graph, '.', sizeof(graph));
    memset(int_graph, 0, sizeof(int_graph));
}
int get_num(int r, int c, int d)
{
    int p = 0, re = r + d, ce = c + d;
    for (int ri = r; ri < re; ri++)
        for (int ci = c; ci < ce; ci++)
            p += (graph[ri][ci] - '0');
    return p;
}
void read_input()
{
    if (n > 0)
        for (int i = 0; i < n; i++)
            cin >> graph[i];
    else
        while (cin >> int_graph[cnt++] && int_graph[cnt - 1] != -1);
}
void dfs1(int r, int c, int d, int p, int dep)
{
    int num = get_num(r, c, d);
    if (!num)//全白
        return;
    if (num == d * d)//全黑
    {
        int_graph[cnt++] = p;
        ans++;
        return;
    }
    //灰, 递归下一层
    d = d >> 1;
    dfs1(r, c, d, p + 1 * pooww[dep], dep + 1);//下三个同理, r c 是左上角格子的坐标, p为转化后十进制数
    dfs1(r, c + d, d, p + 2 * pooww[dep], dep + 1);
    dfs1(r + d, c, d, p + 3 * pooww[dep], dep + 1);
    dfs1(r + d, c + d, d, p + 4 * pooww[dep], dep + 1);
}
void dfs2(int r, int c, int d, int p)
{
    int where = p % 5;//十进制转化为五进制
    p /= 5;
    if (!where)//全黑
    {
        int re = r + d, ce = c + d;
        for (int i = r; i < re; i++)
            for (int j = c; j < ce; j++)
                graph[i][j] = '*';
    }
    d >>= 1;
    if (where == 1)dfs2(r, c, d, p);
    if (where == 2)dfs2(r, c + d, d, p);
    if (where == 3)dfs2(r + d, c, d, p);
    if (where == 4)dfs2(r + d, c + d, d, p);
}
//本题最恶心的地方, 按照要求的格式输出
void print_ans()
{
    if (kase) cout << endl;
    cout << "Image " << ++kase << endl;
    if (n > 0)
    {
        sort(int_graph, int_graph + cnt);
        int can_print_endl = 0;
        for (int i = 0; i < cnt; i++)
        {
            if (i % 12) printf(" ");
            cout << int_graph[i];
            if (++can_print_endl % 12 == 0) cout << endl;
        }
        if (ans && can_print_endl % 12) cout << endl;
        cout << "Total number of black nodes = " << ans <<endl;
    }
    else
    {
        for (int i = 0; i < -n; i++)
        {
            graph[i][-n] = '\0';
            cout << graph[i] << endl;
        }
    }
}
int main()
{
    while (cin >> n && n)
    {
        init();//初始化
        read_input();//读输入
        if (n > 0)
            dfs1(0, 0, n, 0, 0);
        else for (int i = 0; i < cnt; i++)
                dfs2(0, 0, -n, int_graph[i]);
        print_ans();
    }
    return 0;
}
