#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define fir(x) x.first
#define sec(x) x.second
#define Testcase int T; cin >> T; for (int t = 1; t <= T; ++t)

class Solution
{
    static const int MOD = 1e9 + 7;
    static const int N = 4e5 + 5;
    typedef long long ll;
    typedef pair<int, int> pii;
    vector<int> pick;
    pii num[N];
    int arr[N], n, p, q, table[N];
public:
    Solution() { }
    void solve()
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> arr[i], pick.push_back(arr[i]);

        //去重
        sort(pick.begin(), pick.end());
        pick.erase(unique(pick.begin(), pick.end()), pick.end());

        //离散化
        for (int i = 1; i <= n; i++)
            arr[i] = lower_bound(pick.begin(), pick.end(), arr[i]) - pick.begin() + 1;

        //统计数量并排序
        for (int i = 1; i <= n; i++)
            num[i].second = i;
        for (int i = 1; i <= n; i++)
            num[arr[i]].first++;
        sort(num + 1, num + n + 1);

        //枚举最大r
        int l = 1, cnt = 0, ans = 0, maxr = 1, maxc;
        for (int i = 1; i <= n; i++)
        {
            while (l <= n && num[l].first < i)
            {
                l++;
            }
            cnt += n - l + 1;
            if (cnt / i < i)
                break;
            int cur = cnt / i * i;
            if (cur > ans)
            {
                ans = cur;
                maxr = i;
            }
        }
        maxc = ans / maxr;
        cout << ans << endl << maxr << " " << maxc << endl;
        l = 1;
        while (l <= n && num[l].first < 1)
        {
            l++;
        }
        int has = 0, x = 0, y = 0;
        for (int i = n; i >= l; --i)
        {
            cnt = min(num[i].first, maxr);
            for (int j = 1; j <= cnt && has < ans; ++j, ++has)
            {
                table[x * maxc + (x + y) % maxc] = pick[num[i].second - 1];
                x++;
                if (x == maxr)
                {
                    y++, x = 0;
                }
            }
        }

        for (int i = 0; i < ans; i++)
            printf("%d%c", table[i], " \n"[(i + 1) % maxc == 0]);
        
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    Solution* solution = new Solution;

    solution->solve();

    delete solution;
    return 0;
}
