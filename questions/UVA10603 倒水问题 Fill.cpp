/*
	Uva10603 倒水问题
	priority_queue的使用,bfs的又一变种优化vis数组,通过其中两个可以求出第三个,故用二元组
	2021/2/16 By-SilLea
*/
#include<cstring>
#include<set>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
#define rec(start,end,mod) for (int mod = (start); (mod) < (end); (mod++))
struct Cup
{
	int v[3], dist;
	Cup(int a = 0, int b = 0, int c = 0, int d = 0) {
		v[0] = a; v[1] = b; v[2] = c; dist = d;
	}
	bool operator < (const Cup& b)const
	{
		return dist > b.dist;
	}
};
const int maxn = 200 + 5;
bool vis[maxn][maxn];
int ans[maxn], cup[3];
void upgrade_ans(const Cup& u)
{
	rec(0, 3, i)
	{
		int d = u.v[i];
		if (ans[d] < 0 || ans[d] > u.dist)ans[d] = u.dist;//更新某杯子d水量下的倒水量
	}
}
void solve(int a, int b, int c, int d)
{
	cup[0] = a; cup[1] = b; cup[2] = c;//cup[3] 用来存储三个杯子的最大容量
	Cup start(0, 0, c, 0);//初始状态
	priority_queue<Cup> q;//根据题目要求,创建优先队列,倒水量少的优先
	q.push(start);
	while (!q.empty())
	{
		Cup u = q.top(); q.pop();
		upgrade_ans(u);
		if (ans[d] > 0)break;
		rec(0,3,i)
			rec(0, 3, j)//i杯子给j杯子倒水
		{
			if (i == j || u.v[i] == 0 || u.v[j] == cup[j])//i杯子为空 or j杯子已满
				continue;
			int amount = min(cup[j], u.v[i] + u.v[j]) - u.v[j];
			Cup u2;
			memcpy(&u2, &u, sizeof(u));
			u2.v[i] -= amount; 
			u2.v[j] += amount;
			u2.dist += amount;
			if (!vis[u2.v[0]][u2.v[1]])
			{
				vis[u2.v[0]][u2.v[1]] = true;
				q.push(u2);
			}
		}
	}
	//打印答案
	while (true)
	{
		if (ans[d] >= 0)//打印水量为d时的倒水量
		{
			cout << ans[d] << " " << d << endl;
			return;
		}
		d--;//如果没有d,则输出较小的,尽量接近d的d'倒水量
	}
}
void init()
{
	memset(vis, 0, sizeof(vis));
	memset(ans, -1, sizeof(ans));
}
int main()
{
	ios::sync_with_stdio(false);//与stdio取消绑定,提高iostream的速度
	int t, a, b, c, d; cin >> t;
	while (t--)
	{
		cin >> a >> b >> c >> d;
		init();
		solve(a, b, c, d);
	}
	return 0;
}
