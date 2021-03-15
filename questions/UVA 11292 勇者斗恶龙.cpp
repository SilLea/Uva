/*
    UVA11292 Dragon of Loowater
    题目描述:砍头
    输入包含多组数据。每组数据的第一行为正整数n和m（1<=n,m<=20000）；以下n行每行为一个整数，即恶龙每个头的直径；以下m行每行为一个整数，即每个骑士的能力。输入结束标志为n=m=0。
    输出格式
    对于每组数据，输出最小花费。如果无解，输出“Loowater is doomed!”。

    贪心硬干

    by - SilLea   2021/3/15
*/
#include<iostream>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 20000 + 5;
int n, m;
int heads[maxn], knights[maxn];
int main()
{
    freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
    while (cin >> n >> m && n)
    {
        for (int i = 0; i < n; i++)
            cin >> heads[i];
        for (int i = 0; i < m; i++)
            cin >> knights[i];
        sort(heads, heads + n, [](int &a, int &b){
             return a > b;
             });
        sort(knights, knights + m);
        int sum = 0;
        if (n > m)
            cout << "Loowater is doomed!" << endl;
        else
        {
            bool ok = true;
            for (int i = 0, j; ok && i < n; i++)
            {
                for (j = 0; ok && j < m; j++) if (knights[j] != -1)
                {
                    if (heads[i] <= knights[j])
                    {
                        sum += knights[j];
                        knights[j] = -1;
                        break;
                    }
                }
                ok = j == m ? false : true;
            }
            if (ok)
                cout << sum << endl;
            else
                cout << "Loowater is doomed!" << endl;
        }
    }
    return 0;
}
