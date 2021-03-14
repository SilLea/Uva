/*
    UVA10881 Piotr's Ants
    题目描述:
    一根长度为LL厘米的木棍上有nn只蚂蚁，每只蚂蚁要么向左爬，要么向右爬，速度为11厘米/秒。当两只蚂蚁相遇时，它们同时掉头（时间忽略不计）。给出每只蚂蚁的初始位置和朝向，请计算TT秒后每只蚂蚁的位置。
    输入格式:
    输入第一行为测试数据组数NN，接下来一共NN组数据，每组数据的第一行为33个整数L,T,n(0<=n<=10000)L,T,n(0<=n<=10000),以下nn行每行描述了一只蚂蚁的初始位置。其中，整数xx为它距离木棍左端的距离(单位：厘米).字母表示初始朝向(LL表示朝左，RR表示向右)
    输出格式:
    对于每组数据，输出nn行，按输入顺序给出每只蚂蚁的位置和朝向(TurningTurning 表示正在碰撞)，在第TT秒之前已经掉下的蚂蚁(正好爬到木棍边缘的不算)输出Fell off.


    用两个数组分别存排序后数组和将要操作的数组
    然后两个数组一一对拍
    by - SilLea   2021/3/13
*/
#include<iostream>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 10000 + 5;
int L, T, n;
struct node
{
    int p, direction, id;
    bool operator < (node& another)const
    {
        return p < another.p;
    }
    node(int a = 0, int b = 0, int c = 0)
    {
        p = a;
        direction = b;
        id = c;
    }
};
node ants[maxn], aft[maxn];
int main()
{
//    freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
    int kase;
    cin >> kase;
    for (int ka = 1; ka <= kase; ka++)
    {
        cin >> L >> T >> n;
        char dir;
        for (int i = 0; i < n; i++)
        {
            cin >> ants[i].p >> dir;
            aft[i].direction = ants[i].direction = (dir == 'L' ? -1 : 1);
            ants[i].id = i;
            aft[i].p = ants[i].p + ants[i].direction * T;
        }
        sort(ants, ants + n);
        sort(aft, aft + n);
        cout << "Case #" << ka << ":" << endl;
        vector<int> ans_pos(n);
        for (int i = 0; i < n; i++)
        {
           ans_pos[ants[i].id] = i;
           if ((i >= 1 && aft[i].p == aft[i - 1].p) || (i < n - 1 && aft[i].p == aft[i + 1].p))
                aft[i].id = 2;
           else
                aft[i].id = 1;
        }
        for (int i = 0; i < n; i++)
        {
            if (aft[ans_pos[i]].p < 0 || aft[ans_pos[i]].p > L)
                cout << "Fell off" << endl;
            else
            {
                cout << aft[ans_pos[i]].p << ' ' << (aft[ans_pos[i]].id == 1 ? (aft[ans_pos[i]].direction == 1 ? "R" : "L") : "Turning") << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
