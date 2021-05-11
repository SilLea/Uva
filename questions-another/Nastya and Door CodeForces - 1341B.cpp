/*
    前缀和
    尺进法(参考ekatsim)
    
    by - SilLea 2021/5/3
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#define cl(i, j) memset(i, j, sizeof(i))

using namespace std;

const int maxn = 2 * 1e5 + 5;
int a[maxn];
bool peek[maxn];

int main()
{
    ios::sync_with_stdio(false);
    int t, k, n;
    cin >> t;
    while (t--)
    {
        cl(peek, 0);
        cin >> n >> k;
        k--;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        a[n + 1] = 2e9;
        int ans = 0, l = 1, cnt = 0, tl = 1, flg = 0;
        for (int i = 2; i <= n; i++)
        {
            if (flg) cnt++, flg = 0;
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
            {
                flg = 1;
                peek[i] = 1;
            }
            if (i - tl > k)
            {
                tl++;
                if (peek[tl]) cnt--;
            }
            if (ans < cnt) ans = cnt, l = tl;
        }
        cout << ans + 1 << ' ' << l << endl;
    }
    return 0;
}
