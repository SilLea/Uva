/*
    Chain Reaction CodeForces - 608C
        dp
    by - SilLea  2021/4/13
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#define sc(i, j) scanf("%i", &j)
#define rep(n) for (int i = 0; i < (n); i++)
using namespace std;
const int maxn = 1000000 + 10;
int n;
int b[maxn], _max = 0, ans = 0;
int rec[maxn];
int main()
{
    memset(b, 0, sizeof(b));
    memset(rec, 0, sizeof(rec));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        sc(d, a);
        sc(d, b[a]);
        _max = max(_max, a);
    }
    for (int i = 0; i <= _max; i++)
    {
        if (b[i] == 0 && i > 0)
            rec[i] = rec[i - 1];
        else if (b[i])
        {
            if (b[i] >= i)
                rec[i] = 1;
            else
                rec[i] = rec[i - b[i] - 1] + 1;
        }
        ans = max(ans, rec[i]);
    }
    cout << n - ans << endl;
    return 0;
}
