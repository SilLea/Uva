/*
    uva 506
    DEPEND INSTALL REMOVE LIST END
        depend存item1所依赖的组件
        is_depended 存 item被什么组件所依赖
        安装和删除都在递归中进行
        将item名映射成一个id
        注意学习erase+remove删除某元素的用法
    by - SilLea   2021/3/26
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;
const int maxn = 10000 + 5;
string Item_list[maxn];
map<string, int>_id;
vector<int>depend[maxn], is_depended[maxn], installed;
int state[maxn];
int cnt = 0;
int ID(string &a)
{
    if (_id.count(a))
        return _id[a];
    Item_list[cnt] = a;
    _id[a] = cnt;
    return cnt++;
}
void install(int item, bool toplevel)
{
    if (!state[item])
    {
        for (int i = 0; i < depend[item].size(); i++)
            install(depend[item][i], false);
        state[item] = (toplevel ? 1 : 2);
        cout << "   Installing " << Item_list[item] << endl;
        installed.push_back(item);
    }
}
bool is_needed(int item)
{
    for (int i = 0; i < is_depended[item].size(); i++)
        if (state[is_depended[item][i]])
            return true;
    return false;
}
void remove_item(int item, bool toplevel)
{
    if ((toplevel || state[item] == 2) && !is_needed(item))
    {
        state[item] = 0;
        installed.erase(remove(installed.begin(), installed.end(), item), installed.end());
        cout << "   Removing " << Item_list[item] << endl;
        for (int i = 0; i < depend[item].size(); i++)
            remove_item(depend[item][i], false);
    }
}
int main()
{
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    memset(state, 0, sizeof(state));
    string cmd;
    while (getline(cin, cmd) && cmd[0] != 'E')
    {
        cout << cmd << endl;
        stringstream ss(cmd);
        string item1, item2;
        char is_end;
        if (cmd[0] == 'D')
        {
            ss >> item1 >> item1;
            int id1 = ID(item1);
            while (ss >> item2)
            {
                int id2 = ID(item2);
                depend[id1].push_back(id2);
                is_depended[id2].push_back(id1);
            }
        }
        else if (cmd[0] == 'I')
        {
            ss >> item1 >> item1;
            int id = ID(item1);
            if (state[id])
            {
                cout << "   " << Item_list[id] << " is already installed." << endl;
                continue;
            }
            install(id, true);
        }
        else if (cmd[0] == 'R')
        {
            ss >> item1 >> item1;
            int id = ID(item1);
            if (is_needed(id))
            {
                cout << "   " << Item_list[id] << " is still needed." << endl;
                continue;
            }
            if (!state[id])
            {
                cout << "   " << Item_list[id] << " is not installed." << endl;
                continue;
            }
            remove_item(id, true);
        }
        else if (cmd[0] == 'L')
            for (int i = 0; i < installed.size(); i++)
                cout << "   " << Item_list[installed[i]] << endl;
    }
    cout << "END" << endl;
    return 0;
}
