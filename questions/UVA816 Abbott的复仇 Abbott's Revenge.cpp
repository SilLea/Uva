/*
	这份代码基本上全是照着别人的代码写的
	题目细节很多,以后抽空自己重新做一遍
	bfs求最短路径题,利用四元组can_to[r][c][dir][turn]来记录在r,c位置朝向为dir,是否可以向turn方向行走
	walk函数真的是太妙了,不得不再次佩服刘汝佳大牛
	自己写这个walk可能又要一万个if else
	输出格式的控制也非常的细节,值得借鉴
	利用NODE p[r][c][dir] 来存取父节点是我没有接触过的操作,学习了.

	2021/2/13 by-SilLea
*/
#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct NODE
{
	int r, c, dir;
	NODE(int r = 0, int c = 0, int dir = 0) : r(r), c(c), dir(dir) {}
};
const char* dirs = "NESW";  const char *turns = "FLR";
int dir_id(char c) { return (strchr(dirs, c) - dirs); }
int turn_id(char c) { return (strchr(turns, c) - turns); }
const int dr[] = { -1,0,1,0 };
const int dc[] = { 0,1,0,-1 };
const int R = 9 + 2, C = 9 + 2, DIR = 4, Turn = 4;
int step[R][C][DIR];
NODE p[R][C][DIR];
bool can_to[R][C][DIR][Turn];
string name, turn;
int ex, ey, r1, c1, dir, r0, c0;
bool inside(const int& r, const int& c)
{
	return r >= 1 && r <= 9 && c >= 1 && c <= 9;
}
NODE walk(const NODE& u, int turn)
{
	int dir = u.dir;
	if (turn == 1) dir = (dir + 3) % 4;
	if (turn == 2) dir = (dir + 1) % 4;
	return NODE(u.r + dr[dir], u.c + dc[dir], dir);
}
void print_ans(NODE u)
{
	vector<NODE>ans;
	while (true)
	{
		ans.push_back(u);
		if (step[u.r][u.c][u.dir] == 0)break;
		u = p[u.r][u.c][u.dir];
	}
	ans.push_back(NODE(r0, c0, dir));
	int cnt = 0;
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		if (cnt % 10 == 0)printf(" ");
		printf(" (%d,%d)", ans[i].r, ans[i].c);
		if (++cnt % 10 == 0)puts("");
	}
	if (ans.size() % 10 != 0)puts("");
}
void solve()
{
	queue<NODE>bfs;
	memset(step, -1, sizeof(step));
	NODE u(r1, c1, dir);
	step[r1][c1][dir] = 0;
	bfs.push(u);
	while (!bfs.empty())
	{
		u = bfs.front(); bfs.pop();
		if (u.r == ex && u.c == ey)
		{
			print_ans(u); return;
		}
		for (int i = 0; i < 3; i++)
		{
			NODE v = walk(u, i);
			if (can_to[u.r][u.c][u.dir][i] && inside(v.r, v.c) && step[v.r][v.c][v.dir] < 0)
			{
				step[v.r][v.c][v.dir] = step[u.r][u.c][u.dir] + 1;
				p[v.r][v.c][v.dir] = u;
				bfs.push(v);
			}
		}
	}
	puts("  No Solution Possible");
}
bool read_input()
{
	memset(can_to, 0, sizeof(can_to));
	cin >> name;
	if (name == "END")return false;
	int r, c;
	cin >> r0 >> c0 >> turn >> ex >> ey;
	dir = dir_id(turn[0]);
	r1 = r0 + dr[dir]; c1 = c0 + dc[dir];
	while (cin >> r && r)
	{
		cin >> c;
		while (cin >> turn && turn[0] != '*')		
			for (int i = 1; i < turn.length(); i++)			
				can_to[r][c][dir_id(turn[0])][turn_id(turn[i])] = true;		
	}
	return true;
}
int main()
{
	while (read_input())
	{
		cout << name << endl;
		solve();
	}
	return 0;
}