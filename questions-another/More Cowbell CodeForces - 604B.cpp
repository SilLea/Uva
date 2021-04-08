/*
    More Cowbell CodeForces - 604B

    by - SilLea   2021/4/8
*/
#include<algorithm>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 1e5 + 5;
int n, k;
int s[maxn];
int main()
{
    while (cin >> n >> k && n)
    {
        memset(s, 0, sizeof(s));
        int sum = 0;
        for (int i = 0; i < n; i++)
            cin >> s[i];
        if (n <= k)
        {
            cout << s[n - 1] << endl;
            continue;
        }
        int left = n - k;
        for (int i = left; i < n && left * 2 - 1 - i >= 0; i++)
        {
            sum = max(sum, s[i] + s[left * 2 - 1 - i]);
        }
        cout << max(sum, s[n - 1]) << endl;
    }
    return 0;
}
