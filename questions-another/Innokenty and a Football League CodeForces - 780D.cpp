/*
    Innokenty and a Football League CodeForces - 780D

    by - SilLea   2021/4/8
*/
#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
const int maxn = 1e3 + 5;
int n;
map<string, int>id_ache;
map<int, int>id_cnt;
int used[maxn * 2];
string lis[maxn * 2];
int id = 0;
int a[maxn], b[maxn], have_ans[maxn];
int creat_id(string str)
{
    int _id = id_ache[str];
    if (_id)
        return _id;
    return id_ache[str] = ++id;
}
void is_eagle(int b)
{
    if (used[b])
    {
        cout << "NO" << endl;
        exit(0);
    }
}
int main()
{
    cin >> n;
    string team_name, home_name;
    for (int i = 0; i < n; i++)
    {
        cin >> team_name >> home_name;
        string aa = team_name.substr(0, 3);
        string bb = team_name.substr(0, 2) + home_name[0];
        a[i] = creat_id(aa);
        b[i] = creat_id(bb);
        lis[a[i]] = aa;lis[b[i]] = bb;
        id_cnt[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (id_cnt[a[i]] > 1)
        {
            is_eagle(b[i]);
            have_ans[i] = b[i];
            used[b[i]] = 1;
        }
    }
    for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++)
            if (!have_ans[i] && used[a[i]])
            {
                is_eagle(b[i]);
                have_ans[i] = b[i];
                used[b[i]] = 1;
                used[a[i]] = 0;
            }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        if (have_ans[i])
            cout << lis[have_ans[i]] << endl;
        else
            cout << lis[a[i]] << endl;
    }
    return 0;
}
