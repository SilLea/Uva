#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
const int N = 1e5 + 5;
inline bool read(int &);
int num[N], P[N];
int main()
{
    int n, m, ok = 0;
    long long sum = 0;
    read(n), read(m);
    for (int i = 1; i <= m; i++)
    {
        P[i] = i;
        read(num[i]);
        sum += num[i];
        if (i > n - num[i] + 1)
        {
            puts("-1");
            return 0;
        }
    }
    if (sum < n)
    {
        puts("-1");
        return 0;
    }
    P[m + 1] = n + 1;
    n -= m;
    for (int i = m; i >= 1; i--)
    {
        if (num[i] > n) break;
        n -= (num[i] - 1), P[i] = P[i + 1] - num[i];
    }
    for (int i = 1; i < m; i++) printf("%d ", P[i]);
    printf("%d\n", P[m]);
    return 0;
}
inline bool read(int &x)
{
    x = 0;
    int f = 1;
    char ch = getchar();
    while(ch < '0'|| ch > '9')
    {
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    x *= f;
    return true;
}
