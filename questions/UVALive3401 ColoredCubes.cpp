/*
    LA 3401
    题目大意：
        有n个带颜色的立方体，每个面都涂有不同的颜色，要求图改尽量少的面，使得所有立方体完全相同，立方体可以旋转。

    第一个立方体作为参照，然后就是枚举每个立方体的状态，用递归实现即可，
    递归到最后一个立方体时，计算每个面需要涂改的面，得出每种状态需要涂改的面。找出所有情况的最小值即可。
    by - SilLea   2021/3/17
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
const int maxn = 4;
int n, cube[maxn][6], temp[maxn][6], r[maxn];//r旋转方式, temp存旋转后的方块, cube是读入的方块
int ans, cnt[maxn * 6];//ans最终答案, cnt存每个颜色的出现次数
int Vist[24][6] = { {1, 5, 2, 3, 0, 4},{5, 4, 2, 3, 1, 0},{4, 0, 2, 3, 5, 1},{0, 1, 2, 3, 4, 5},{1, 2, 0, 5, 3, 4},{2, 4, 0, 5, 1, 3},
    {4, 3, 0, 5, 2, 1},{3, 1, 0, 5, 4, 2},{1, 0, 3, 2, 5, 4},{0, 4, 3, 2, 1, 5},{4, 5, 3, 2, 0, 1},{5, 1, 3, 2, 4, 0},
    {1, 3, 5, 0, 2, 4},{3, 4, 5, 0, 1, 2},{4, 2, 5, 0, 3, 1},{2, 1, 5, 0, 4, 3},{3, 5, 1, 4, 0, 2},{5, 2, 1, 4, 3, 0},
    {2, 0, 1, 4, 5, 3},{0, 3, 1, 4, 2, 5},{2, 5, 4, 1, 0, 3},{5, 3, 4, 1, 2, 0},{3, 0, 4, 1, 5, 2},{0, 2, 4, 1, 3, 5}
};//常量表
vector<string>names;//存储已经出现过的id
int ID(const string & name)//对每个color取一个id, 方便后续操作
{
    for (auto it = names.begin(); it != names.end(); it++)
        if (*it == name)
            return it - names.begin();
    names.push_back(name);
    return names.size() - 1;
}
void repaint()
{

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 6; j++)
            temp[i][j] = cube[i][Vist[r[i]][j]];//将所有方块旋转
    int tot = 0;
    for (int j = 0; j < 6; j++)
    {
        memset(cnt, 0, sizeof(cnt));
        int max_ = 0;//相同的面数的最大值
        for (int i = 0; i < n; i++)
            max_ = max(max_, ++cnt[temp[i][j]]);
        tot += n - max_;
    }
    ans = min(ans, tot);//更新答案
}
void dfs(int cur)//用dfs枚举除第一个方块的剩余方块的旋转方式的排列
{
    if (cur == n)
        repaint();
    else for (int i = 0; i < 24; i++)
        {
            r[cur] = i;
            dfs(cur + 1);
        }
}
int main()
{
    ios::sync_with_stdio(false);//关闭与stdio的同步
    string name;
    r[0] = 0;
    while (cin >> n && n)
    {
        names.clear();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 6; j++)
            {
                cin >> name;
                cube[i][j] = ID(name);
            }
        ans = n * 6;//答案上界
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}
