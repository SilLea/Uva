/*
    UVA120 煎饼 Stacks of Flapjacks
    用两个数组分别存排序后数组和将要操作的数组
    然后两个数组一一对拍
    by - SilLea   2021/3/13
*/
#include<iostream>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 30 + 5;
int flap[maxn], cnt, after[maxn];
int find_max(int * a, int n)
{
    int pos = n;
    for (int i = n; i >= 0; i--)
    {
        if (a[pos] < a[i])
            pos = i;
    }
    return pos;
}
void solve(const string &line)
{
    int cur = cnt - 1;
    vector<int> ans;
    while (cur)
    {
        if (flap[cur] == after[cur])
            cur--;
        else
        {
            int cut = find_max(after, cur);
            if (cut != 0)
            {
                reverse(after, after + cut + 1);//将最大的那个放到数组最左边
                ans.push_back(cnt - cut);//cnt -> 1
            }
            ans.push_back(cnt - cur);
            reverse(after, after + cur + 1);
            cur--;
        }
    }
    cout << line << endl;
    auto it = ans.begin();
    while (it != ans.end())
    {

        cout << *it << ' ';
        it++;
    }
    cout << 0 << endl;
}
int main()
{
//    freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
    string line;
    while (getline(cin, line))
    {
        istringstream ss(line);
        cnt = 0;
        while (ss >> flap[cnt++]);cnt--;
        memcpy(after, flap, sizeof(int) * cnt);
        sort(flap, flap + cnt);
        solve(line);
    }
    return 0;
}
