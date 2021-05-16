#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<iomanip>

//#include "another.cpp"
//#include "function.cpp"
using namespace std;
class Uva11212
{
    static const int N = 12;
    int kase, n;
    int arr[N];
    int getH()
    {
        int cnt = 0;
        for (int i = 1; i < n; i++)
            if (arr[i] + 1 != arr[i + 1])
                cnt++;
        if (arr[n] != n) cnt++;
        return cnt;
    }
    bool dfs(int d, int maxd)
    {
        if (3 * d + getH() > 3 * maxd) return false;//IDA* 估价函数
        if (is_sorted(arr + 1, arr + 1 + n)) return true;

        int oldarr[N], b[N];
        memcpy(oldarr + 1, arr + 1, sizeof(int) * n);//保存原数组

        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++)
                {
                    //将[i, j]之间的元素截切下来
                    int cnt1 = 1;
                    for (int k = 1; k <= n; k++) if (k < i || k > j) b[cnt1++] = oldarr[k];
                    //将[i, j]之间的元素枚举插入到剩余元素之间
                    for (int k = 0; k < cnt1; k++)
                    {
                        int cnt2 = 1;
                        for (int p = 1; p <= k; p++) arr[cnt2++] = b[p];
                        for (int p = i; p <= j; p++) arr[cnt2++] = oldarr[p];
                        for (int p = k + 1; p < cnt1; p++) arr[cnt2++] = b[p];
                        if (dfs(d + 1, maxd)) return true;
                    }
                }
        return false;
    }
public:
    Uva11212():kase(0) {}
    bool getInput()
    {
        cin >> n;
        if (!n) return false;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        arr[n + 1] = n + 1;
        int maxd;
        if (is_sorted(arr + 1, arr + 1 + n))
            maxd = 0;
        else
            for (maxd = 1; maxd < 5; maxd++)
                if (dfs(0, maxd))
                    break;
        cout << "Case " << ++kase << ": " << maxd << endl;
        return true;
    }
};
Uva11212 uva11212;
int main()
{
    //freopen("data.in", "r", stdin);
    while (uva11212.getInput());
    return 0;
}
