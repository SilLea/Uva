/*
    CF782B The Meeting Place Cannot Be Changed

        二分题, 最短时间0, 最长时间10^9
        一开始取中间时间, 计算所有人在这个时间内可以走到的区间, 然后区间取交集
        如果所有人在这个时间内可以到达一个小区域, 代表时间长了
        如果所有人在这个时间内不可以相遇(没有交集, l > r), 时间短了
        依此进行二分
    by - SilLea   2021/4/6
*/
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 60000 + 5;
const double inf = 2147483647.0;
int x[maxn], v[maxn];
int n;
int main()
{
 //   ios::sync_with_stdio(false);
    while (cin >> n && n)
    {
        double ans(inf);
        for (int i = 0; i < n; i++)
            cin >> x[i];
        for (int i = 0; i < n; i++)
            cin >> v[i];
        double lt = 0.0, rt = 1e9, mid;
        while (rt - lt > 1e-7)
        {
            mid = (lt + rt) / 2.0;

            double l = x[0] - mid * v[0], r = x[0] + mid * v[0];
            for (int i = 1; i < n; i++)
            {
                l = max(l, x[i] - mid * v[i]);
                r = min(r, x[i] + mid * v[i]);
            }
            if (l < r)
            {
                rt = mid;
                ans = mid;
            }
            else
                lt = mid;
        }
        printf("%.12lf\n", (ans == inf ? 0.0 : ans));
    }
    return 0;
}
