/*
    uva1599
	先反向bfs求出每个节点离终点的距离, 再根据距离正向bfs出最小的字典序
    by - SilLea   2021/3/25
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int n, m;
const int maxn = 100000 + 5;
struct Path
{
    int u, v, c;
    Path() {}
    Path(int _u, int _v, int _c)
    {
        u = _u, v = _v, c = _c;
    }
};
vector<int> graph[maxn];
vector<Path> path;
int d[maxn], vis[maxn];
void rbfs()//寻找出每个点到终点的距离
{
    memset(d, 0, sizeof(d));
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(n);
    vis[n] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int each : graph[u])
        {
            int v = (u == path[each].u ? path[each].v : path[each].u);//下一个节点
            if (!vis[v])
            {
                d[v] = d[u] + 1;
                q.push(v);
                vis[v] = 1;
            }
        }
    }
}
void bfs()
{
    memset(vis, 0, sizeof(vis));
    vector<int>ans;
    vector<int>next;
    next.push_back(1);vis[1] = 1;
    for (int i = 0; i < d[1]; i++)//根据层数(距离), 开始遍历
    {
        int min_colour = 2147483647;
        for (int u : next)//这几个循环用于搜出最小颜色
            for (int each : graph[u])
            {
                int v = (u == path[each].u ? path[each].v : path[each].u);//下一个节点
                if (d[u] == d[v] + 1 && path[each].c < min_colour)
                {
                    min_colour = path[each].c;
                }
            }
        ans.push_back(min_colour);
        vector<int>temp_next;
        //按照颜色去找路径, 将所有符合的走法保存到temp_next中
        for (int u : next)
            for (int each : graph[u])
            {
                int v = (u == path[each].u ? path[each].v : path[each].u);//下一个节点
                if (d[u] == d[v] + 1 && !vis[v] && path[each].c == min_colour)
                {
                    temp_next.push_back(v);
                    vis[v] = 1;
                }
            }
        next.swap(temp_next);
    }
    cout << d[1] << endl;
    auto it = ans.begin();
    while (it != ans.end())
    {
        cout << *it;
        it++;
        cout << (it == ans.end() ? '\n' : ' ');
    }

}
int main()
{
    while (cin >> n >> m)
    {
        fill(graph, graph + n + 1, vector<int>());
        path.clear();
        int u, v, c;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> c;
            if (u == v) continue;//处理自环(对解题无任何影响)
            graph[u].push_back(path.size());//建立
            graph[v].push_back(path.size());//邻接表
            path.push_back(Path(u, v, c));
        }
        rbfs();
        bfs();
    }
    return 0;
}
