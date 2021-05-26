#include<iostream>
#include<algorithm>
using namespace std;
class UVA1374//快速幂计算
{
	int n, cnt, maxd;
	int num[100];
	bool IDAstar(int cur)
	{
		if (num[cur] == n) return true;
		if (cur == maxd) return false;
		int _max = Get_Max(cur);
		if ((_max << (maxd - cur)) < n) return false;
		for (int i = 0; i <= cur; ++i)
		{
			num[cur + 1] = num[cur] + num[i];
			if (IDAstar(cur + 1)) return true;
			num[cur + 1] = num[cur] - num[i];
			if (IDAstar(cur + 1)) return true;
		}
		return false;
	}
	int Get_Max(int en)
	{
		int ret = 0;
		for (int i = 0; i <= en; i++)
			if (ret < num[i])
				ret = num[i];
		return ret;
	}
public:
	UVA1374() :n(0), cnt(0), maxd(0) {}
	void start()
	{
		while (cin >> n && n)
		{
			if (n == 1)
				cout << 0 << endl;
			else
			{
				num[0] = 1;
				for (maxd = 1; maxd < 13; ++maxd)
					if (IDAstar(0))
						break;
				cout << maxd << endl;
			}
		}
	}
} solve;
int main()
{
	solve.start();
}
