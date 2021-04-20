/*
    UVA 10410

    by - SilLea  2021/4/20
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;
const int N = 1e3 + 5;
int pos[N];
vector<int> ans[N];
int main()
{
    int n;
    while (cin >> n)
    {
        int t;
        stack<int> s;
        for (int i = 1; i <= n; i++)
            cin >> t, pos[t] = i, ans[i].clear();
        cin >> t;
        int root = t;
        s.push(root);
        for (int i = 1; i < n; i++)
        {
            cin >> t;
            while (true)
            {
                int u = s.top();
                if (u == root || pos[u] + 1 < pos[t])
                {
                    ans[u].push_back(t);
                    s.push(t);
                    break;
                }
                s.pop();
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << i <<":";
            for (auto& e : ans[i])
                cout << " " << e;
            cout << endl;
        }
    }
    return 0;
}
