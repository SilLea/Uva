/*
    Sequence with Digits CodeForces - 1355A

    by - SilLea  2021/4/15
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#define sc(i, j) scanf("%i", &j)
#define rep(n) for (int i = 0; i < (n); i++)
using namespace std;
const int maxn = 1000000 + 10;
typedef unsigned long long ULL;
ULL n, a, k;
void get_max_min(ULL a, ULL & mi, ULL &ma)
{
    ULL mii = 9, maa = 0;
    while (a)
    {
        ULL t = a % 10;
        a /= 10;
        mii = min(mii, t);
        maa = max(maa, t);
    }
    mi = mii, ma = maa;
}
int main()
{
    cin >> n;
    rep(n)
    {
        cin >> a >> k;
        ULL ans = 0;
        if (k == 1)
            cout << a << endl;
        else
        {
            ULL mi, ma;
            --k;
            while (k--)
            {
                get_max_min(a, mi, ma);
                a = a + mi * ma;
                if (!mi)
                    break;
            }
            cout << a << endl;
        }
    }
    return 0;
}
