/*
    B - Testing Robots CodeForces - 606B

    小算法:
        求最长升序字串的长度(不必连续)
        例如 1 4 6 5 9 8 7 3 2 10
        有   1-2 4-5 6-7 5 9-10 8 7 3 2 10
        最长的为2
        故该题答案为10 - 2
    by - SilLea  2021/4/12
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#define sc(i, j) scanf("%d", &j)
using namespace std;
const int maxn = 1e5 + 5;
int n, t;
int num[maxn];
int main()
{
    memset(num, 0, sizeof(num));
    sc(d, n);
    for (int i = 1; i <= n; i++)
    {
        sc(d, t);
        num[t] = num[t - 1] + 1;//最关键的地方
    }
    sort(num + 1, num + n + 1);//排序, 找到最大的那个
    cout << n - num[n];
    return 0;
}
