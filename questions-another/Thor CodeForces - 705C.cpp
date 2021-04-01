/*
    Codeforces 705C Thor(模拟)

    by - SilLea   2021/4/1
*/
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 300000 + 5;
int num[maxn];//存第i个app未读的消息个数
int n, q, cnt = 0, last = 0;
queue<int>pos[maxn];//存每个app的未读消息的位置(mass)
int mess[maxn], vis[maxn];//mass存每个消息的位置对应的app编号, vis存某位置的信息是否已读
int main()
{
    memset(num, 0, sizeof(num));
    memset(vis, 0, sizeof(vis));
    cin >> n >> q;
    int unread = 0;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 3)
        {
            for(int i = last; i < b; i++)
            {
                if (vis[i]) continue;//已读
                int temp = mess[i];
                pos[temp].pop();//未读消息减一
                num[temp]--;
                unread--;
                vis[i] = 1;
            }
            last = max(b, last);//优化时间
        }
        else
        {
            if (a == 1)
            {
                unread++;
                num[b]++;
                mess[cnt++] = b;//存第cnt个信息属于哪个app
                pos[b].push(cnt - 1);//未读消息入app队列
            }
            else if (a == 2)
            {
                unread -= num[b];
                num[b] = 0;
                while (!pos[b].empty())//清楚未读消息队列
                {
                    int poss = pos[b].front();
                    pos[b].pop();
                    vis[poss] = 1;
                }
            }
        }
        cout << unread << endl;
    }
    return 0;
}
