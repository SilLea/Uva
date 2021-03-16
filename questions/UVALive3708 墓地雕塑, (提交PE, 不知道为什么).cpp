/*
    Graveyard UVALive - 3708
    题目描述:
        墓地本有n个墓碑(均匀分布), 后来加入m个墓碑, 你的任务是输出使得这m + n个墓碑重新均匀分布需要移动的距离

    思路：将圆等比例缩放, 设一个点为原点, 剩下的点选择最短距离移动

    by - SilLea   2021/3/16
*/
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const int maxn = 100 + 5;
int i, j, n, m;
int main()
{
	int n, m;
	while(~scanf("%d%d", &n, &m))
	{
		m += n;
		double l1 = 10000*1.0 / n;
		double l2 = 10000*1.0 / m;
		double ans = 0;
		double cur = 0;
		double sum = 0;
		while(cur < 10000)
		{
			int x = cur / l2;
			sum += min(fabs(cur - l2 * x), fabs(cur - l2 * (x+1)));
			cur += l1;
		}
		int x = (sum + 0.00005) * 10000;
		sum = x*1.0 / 10000;
		printf("%.4lf\n", sum);
	}
    return 0;
}
