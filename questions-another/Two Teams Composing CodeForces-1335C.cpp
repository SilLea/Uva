#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 200010;
int a[maxn], pick[maxn];
int main()
{
    int T, n, num;
    cin >> T;
    while (T--)
    {
        memset(a, 0, sizeof(a));
        int cnt = 0;
        cin >> n;
        int _max = 0, distinct = 0;//相同数最多的个数，一共有多少个数
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            a[num]++;
            if (a[num] == 1) distinct++;
            pick[cnt++] = num;
        }
        for (int i = 0; i < cnt; i++)
            _max = max(_max, a[pick[i]]);
      //1 2 3 3 4 4 4
      //1 2 3 3 4 4 4 4 4
        int ans = max(min(distinct - 1, _max), min(distinct, _max - 1));//[1 2 3][4 4 4]或[1 2 3 4][4 4 4 4]
        cout << "" << ans << endl;
    }
    return 0;
}
