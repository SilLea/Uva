/*
    Young Explorers CodeForces - 1355B

    by - SilLea  2021/4/15
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(n) for (int i = 0; i < (n); i++)
using namespace std;
const int maxn = 300000 + 10;
typedef unsigned long long ULL;
int n;
int ee[maxn];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        rep(n)
        {
            cin >>ee[i];
        }
        sort(ee, ee + n);//
        int ans = 0, cnt = 0;
        rep(n)
        {
            cnt++;
            if (cnt >= ee[i])
                ans++, cnt = 0;
        }
        cout << ans << endl;
    }
    return 0;
}
//Now Russell needs to figure out how many groups he can organize
//print the maximum number
//can only join the group of e or more people
