/*
   UVA804 Petri网模拟 Petri Net Simulation

        理解题面后，解题十分容易，直接按照题意处理即可。
        循环遍历每个中转站，如果可以运转，则运转，即检查一个Trans的输入端的Place中的token数量是否满足要求，运转后并将运转次数++，
        然后把一个Trans输出端的Place相应增加一些token。如果所有中转站都无法运转，则运转结束。
    by - SilLea   2021/3/29
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int maxn = 100 + 5;
int p[maxn], tin[maxn][maxn], tout[maxn][maxn], tp[maxn], maxin[maxn], maxout[maxn];
int np, nt, cnt, n;
void init()
{
    memset(tin, 0, sizeof(tin));
    memset(tout, 0, sizeof(tout));
    memset(maxin, 0, sizeof(maxin));
    memset(maxout, 0, sizeof(maxout));
    cnt = 0;
}
bool solve()
{
    while (cnt < n)
    {
        bool flag = true;
        for (int t = 0; t < nt; t++)//从仓库开始遍历, 寻找可以运作的仓库
        {
            bool ok = true;
            vector<pair<int, int>> need;
            for (int ti = 1; ti <= maxin[t]; ti++)//遍历仓库需求
            {
                if (p[ti] >= tin[t][ti])
                    need.push_back(make_pair(ti, tin[t][ti]));
                else
                {
                    ok = false;
                    break;
                }
            }
            if (ok)//该仓库合法
            {
                for (int i = 0; i < need.size(); i++)
                    p[need[i].first] -= need[i].second;
                for (int i = 1; i <= maxout[t]; i++) if (tout[t][i])
                    p[i] += tout[t][i];
                cnt++;
                flag = false;
                break;
            }
        }
        if (flag) return false;
    }
    return true;
}
int main()
{
    int kase = 0;
    while (cin >> np && np)
    {
        init();
        for (int i = 1; i <= np; i++)
            cin >> p[i];
        cin >> nt;
        for (int i = 0; i < nt; i++)
        {
            int temp;
            while (cin >> temp && temp)
            {
                if (temp < 0) tin[i][-temp]++, maxin[i] = max(-temp, maxin[i]);
                else tout[i][temp]++, maxout[i] = max(temp, maxout[i]);
            }
        }
        cin >> n;
        bool ok = solve();
        cout << "Case " << ++kase << ": ";
        if (ok) cout << "still live after " << n << " transitions" << endl;
        else cout << "dead after " << cnt << " transitions" << endl;
        cout << "Places with tokens:";
        for (int i = 1; i <= np; i++) if (p[i])
            cout << " " << i << " (" << p[i] << ")";
        cout << endl << endl;
    }
    return 0;
}
/*
Case 1: still live after 100 transitions
Places with tokens: 1 (1)
Case 2: dead after 9 transitions
Places with tokens: 2 (1)
*/
