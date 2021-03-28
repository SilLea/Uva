/*
    UVA 1572 Self-Assembly
    要求判定是否存在无限延展的图像

        将每个正方形的边当成顶点，将正方形作为沟通各个点的边（这里需要一点想象力，和直觉违背），若通过以上方式构建的图存在有向环（循环节），说明存在无限的可能。
        关键在于把边抽象成点，正方形抽象成边，枚举同一个正方形相互连接的每种组合。
        A+ A- 可以通过异或运算解决
    by - SilLea   2021/3/28
*/
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 40010;
int n;
int get_id(char &c1, char &c2)
{
    return (c1 - 'A') * 2 + (c2 == '+' ? 1 : 0);
}
int graph[52][52], vis[52];
char s[10];
void link(char &ch1, char &ch2, char &c1, char &c2)
{
    if (ch2 == '0' || c2 == '0') return;
    int id1 = get_id(ch1, ch2), id2 = get_id(c1, c2);
    graph[id1 ^ 1][id2] = 1;
}
bool topu(int u)
{
    vis[u] = -1;
    for (int i = 0; i < 52; i++) if (graph[u][i])
    {
        if (vis[i] < 0) return false;
        if (vis[i] == 0 && !topu(i)) return false;
    }
    vis[u] = 1;
    return true;
}
bool topusort()
{
    for (int i = 0; i < 52; i++)
        if (vis[i] == 0 && !topu(i)) return false;
    return true;
}
int main()
{
    while (cin >> n)
    {
        memset(graph, 0, sizeof(graph));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++) if (j != k)
                    link(s[j * 2], s[j * 2 + 1], s[k * 2], s[k * 2 + 1]);
        }
        bool ok = topusort();
        cout << (ok ? "" : "un") << "bounded" << endl;
    }
    return 0;
}
