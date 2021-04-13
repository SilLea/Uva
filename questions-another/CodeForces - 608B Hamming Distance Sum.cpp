/*
    Hamming Distance Sum
	统计b中此位置0的个数和1的个数
	动态规划
    by - SilLea  2021/4/13
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#define sc(i, j) scanf("%i", &j)
#define rep(n) for (int i = 0; i < (n); i++)
using namespace std;
const int maxn = 200005;
int one[maxn], zro[maxn];
string a, b;
int main()
{
    cin >> a >> b;
    memset(one, 0, sizeof(one));
    memset(zro, 0, sizeof(zro));
    int la = a.length(), lb = b.length();
    if (a.length() == b.length())//长度相同
    {
        long long ans = 0;
        rep(la)
        {
            ans += (a[i] != b[i]);
        }
        cout << ans;
        return 0;
    }
    int l, r = lb - la + 1;
    long long ans = 0;
    if (b[0] == '1')
        one[0]++;
    else
        zro[0]++;
    for (int i = 1; i < lb; i++)
    {
        one[i] = one[i - 1];
        zro[i] = zro[i - 1];
        if (b[i] == '1')
            one[i]++;
        else
            zro[i]++;
    }
    rep(la)
    {
        if (a[i] == '1')
            ans += zro[i + lb - la] - zro[i - 1];
        else
            ans += one[i + lb - la] - one[i - 1];
    }
    cout << ans;
    return 0;
}
