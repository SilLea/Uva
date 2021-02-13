/*
	用程序解华容道问题

	2021/2/13 By-SilLea
*/
#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
typedef int state[9];
const int maxn = 1000000;
const int dr[] = { 0,1,0,-1 };
const int dc[] = { 1,0,-1,0 };
state st[maxn],gole;
int front, back, dis[maxn], f[maxn];
std::set<int> vis;
bool try_to_insert(int cur)
{
	int sum = 0;
	for (int i = 0; i < 9; i++)	
		sum = sum * 9 + st[cur][i];
	if (vis.count(sum))return false;
	vis.insert(sum);
	return true;
}
bool inside(int&r, int&c)
{
	return r < 0 || c < 0 || r > 2 || c > 2;
}
int solve()
{
	while (front < back)
	{
		state& t = st[front];
		if (memcmp(t, gole, sizeof(gole)) == 0)
			return front;
		int p;
		for (p = 0; p < 9; p++)if (!t[p])break;
		int x = p / 3, nx;
		int y = p % 3, ny;
		int nz;
		for (int i = 0; i < 4; i++)
		{
			nx = x + dc[i]; ny = y + dr[i];
			nz = nx * 3 + ny;
			if (!inside(nx, ny) && nz >= 0 && nz < 9)
			{
				state& s = st[back];
				memcpy(&s, &t, sizeof(t));
				s[p] = t[nz];
				s[nz] = t[p];
				dis[back] = dis[front] + 1;
				f[back] = front;
				if (try_to_insert(back))back++;			
			}
		}
		front++;
	}
	return false;
}
void init()
{
	vis.clear();
	front = 1;
	back = 2;
	memset(dis, -1, sizeof(dis));
	dis[front] = 0;
}
void print_ans(int cur)
{
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", st[cur][i]);
		if ((i + 1) % 3 == 0)puts("");
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		init();
		for (int i = 0; i < 9; i++)scanf("%d", &st[front][i]);
		for (int i = 0; i < 9; i++)scanf("%d", &gole[i]);
		int ok = solve();
		printf("move from start to gole at least need %d steps\n", dis[ok]);
		std::vector<int>ans;
		while (true)
		{
			ans.push_back(ok);
			if (dis[ok] == 0)break;
			ok = f[ok];
		}
		for (int i = ans.size() - 1; i >= 0; i--)
		{
			printf("Steo %d:\n", ans.size() - i - 1);
			print_ans(ans[i]);
			if (i)puts("");
		}
	}
	return 0;
}