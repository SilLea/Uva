#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
void change(long long &a1, long long &b1, long long &a2, long long &b2)
{
    if (a1 > a2)
    {
        swap(a1, a2);
        swap(b1, b2);
    }
}
int main()
{
//    freopen("a.in", "r", stdin);
//    freopen("a.out", "w", stdout);
    long long t, n, s1, val1, s2, val2;
    int kase = 0;
    cin >> t;
    while (t--)
    {
        cin >> n >> s1 >> val1 >> s2 >> val2;
        change(s1, val1, s2, val2);//small:s1 large:s2
        long long ans = 0;
        if (n / s2 > 65536)
        {
            if (s2 * val1 >= s1 * val2)
                for (long long i = 0; i < s1; i++)
                    ans = max(ans, (n - i * s2) / s1 * val1 + i * val2);
            else
                for (long long i = 0; i < s2; i++)
                    ans = max(ans, i * val1 + (n - i * s1) / s2 * val2);
        }
        else
        {
            for (int i = 0; i * s2 <= n; i++)
                ans = max(ans, i * val2 + (n - i * s2) / s1 * val1);
        }
        cout << "Case #" << ++kase << ": " << ans << endl;
    }
    return 0;
}
