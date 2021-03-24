/*
    uva1598 交易所

    by - SilLea   2021/3/24
*/
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<queue>
#include<map>
using namespace std;
const int maxn = 10000 + 5;
struct Node
{
    int cost, num, id;
    string op;
    Node () {}
    Node (int _id, int _num, int _cost, string _op):
        id(_id), num(_num), cost(_cost), op(_op) {}
    bool operator < (const Node& that) const        //cost小的优先级高, id小的优先级高
    {
        if (cost != that.cost) return that.cost > cost;
        return that.id < id ;
    }
    bool operator > (const Node& that) const
    {
        if (cost != that.cost) return that.cost < cost;
        return that.id < id;
    }
};
int n;
Node IN[maxn];//输入订单
bool vis[maxn];//指令是否被取消
priority_queue<Node> buy;//买列表
priority_queue<Node, vector<Node>, greater<Node> > sell;//卖列表
map<int, int> _buy;//买的价格对应数量
map<int, int> _sell;//卖价格对应数量
void init()
{
    memset(vis, 0, sizeof(vis));
    _buy.clear(); _sell.clear();
    while (!buy.empty()) buy.pop();
    while (!sell.empty()) sell.pop();
    _buy[0] = 0; _sell[99999] = 0;
    buy.push(Node(maxn, 0, 0, ""));//买默认是0个, 0元
    sell.push(Node(maxn, 0, 99999, ""));//卖默认是0个, 99999元
}
void work(string str)
{
    while (sell.top().cost <= buy.top().cost)//可以交易
    {
        if (buy.size() == 1 || sell.size() == 1) break;
        if (vis[buy.top().id]) { buy.pop(); continue; }//被取消
        if (vis[sell.top().id]) { sell.pop(); continue; }//被标记
        Node s = sell.top(), b = buy.top();
        sell.pop(); buy.pop();
        int num = min(s.num, b.num);//订单的最小个数成交
        b.num -= num; s.num -= num;
        IN[b.id].num -= num; IN[s.id].num -= num;//订单数减少
        _buy[b.cost] -= num; _sell[s.cost] -= num;
        if (s.num) sell.push(s);//还有剩余
        if (b.num) buy.push(b);
        //区分buy和sell时, 交易的价格
        if (str == "BUY") printf("TRADE %d %d\n", num, s.cost);//买的话, 输出卖价(卖价)
        if (str == "SELL") printf("TRADE %d %d\n", num, b.cost);//卖的话, 输出买价(收价)
    }
    while (sell.size() > 1 && vis[sell.top().id]) sell.pop();//如果队首是被取消的订单
    while (buy.size() > 1 && vis[buy.top().id]) buy.pop();//如果队首是被取消的订单
    //剩一个, 表示初始状态, 所以要>1
}
int main()
{
    bool has_out = false;
    while (~scanf("%d", &n))
    {
        init();
        if (has_out) printf("\n");
        else has_out = true;
        for (int i = 1; i <= n; i++)
        {
            string str; cin >> str;
            if (str[0] == 'B')
            {
                int p, q; scanf("%d%d", &p, &q);
                IN[i] = Node(i, p, q, str);//保存输入信息
                _buy[q] += p;
                buy.push(Node(i, p, q, str));//插入优先队列
            }
            if(str[0] == 'S')
            {
                int p, q; scanf("%d%d", &p, &q);
                IN[i] = Node(i, p, q, str);//保存输入信息
                _sell[q] += p;
                sell.push(Node(i, p, q, str));//插入优先队列
            }
            if (str[0] == 'C')
            {
                int id; scanf("%d", &id);
                //没有被取消
                if (IN[id].op == "BUY" && !vis[id]) _buy[IN[id].cost] -= IN[id].num;
                if (IN[id].op == "SELL" && !vis[id]) _sell[IN[id].cost] -= IN[id].num;
                vis[id] = true;//标记为取消
            }
            work(str);
            printf ("QUOTE %d %d - %d %d\n", _buy[buy.top().cost], buy.top().cost, _sell[sell.top().cost], sell.top().cost);
        }
    }
    return 0;
}
