/*
    UVA 246

    by - SilLea  2021/4/19
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef vector<deque<int>> state;
deque<int> hand;//手牌
deque<int> pile[7];//牌堆
map<state, bool> ex;//用来判重
int times, pos;
bool is_win()//如果已经赢了
{
    for (int i = 0; i < 7; i++)
        if (!pile[i].empty())
            return false;
    return true;
}
int record()
{
    state temp;
    temp.push_back(hand);
    for (int i = 0; i < 7; i++)
        temp.push_back(pile[i]);
    if (!ex[temp])//该状态不存在
    {
        ex[temp] = 1;
        return 1;
    }
    return 0;//存在该状态
}
int check(deque<int>& dq)//处理放牌后的牌堆
{
    //front是排顶
    //back 是排尾
    if (dq.size() < 3)
        return 0;
    int tp = dq.back(), bt = dq.front();
    dq.pop_back();
    dq.pop_front();
    if (tp + bt + dq.front() == 10 || tp + bt + dq.front() == 20 || tp + bt + dq.front() == 30)
    {
        //最上面两张和最下面一张
        hand.push_back(bt);
        hand.push_back(dq.front());
        hand.push_back(tp);
        dq.pop_front();
        return 1;
    }
    if (tp + bt + dq.back() == 10 || tp + bt + dq.back() == 20 || tp + bt + dq.back() == 30)
    {
        //最下面两张和最上面一张
        hand.push_back(bt);
        hand.push_back(dq.back());
        hand.push_back(tp);
        dq.pop_back();
        return 1;
    }
    dq.push_front(bt);
    bt = dq.back();
    dq.pop_back();
    if (tp + bt + dq.back() == 10 || tp + bt + dq.back() == 20 || tp + bt + dq.back() == 30)
    {
        hand.push_back(dq.back());
        hand.push_back(bt);
        hand.push_back(tp);
        dq.pop_back();
        return 1;
    }
    dq.push_back(bt);
    dq.push_back(tp);
    return 0;//不可继续处理
}
void put_card(int& pos)
{
    while (pile[pos].empty())
        pos = (pos + 1) % 7;
    pile[pos].push_back(hand.front());
    hand.pop_front();
}
int main()
{
    //freopen("text.in", "r", stdin);
    //freopen("text.out", "w", stdout);
    int card;
    while (cin >> card && card)
    {
        hand.push_back(card);
        for (int i = 1; i < 52; i++)
        {
            cin >> card;
            hand.push_back(card);
        }
        for (int i = 0; i < 7; i++)//先每堆放个牌
        {
            pile[i].push_back(hand.front());
            hand.pop_front();
        }
        record();
        times = 7, pos = 0;
        while (true)
        {
            if (is_win())
            {
                cout << "Win : " << times << endl;
                break;
            }
            put_card(pos);//放牌
            if (!record())
            {
                cout << "Draw: " << times << endl;
                break;
            }
            while (check(pile[pos]));//检查牌状态, 进行循环处理
            if (hand.empty())
            {
                times++;//下一盘才会知道它没牌了, 这里是提前预判, 所以＋1
                cout << "Loss: " << times << endl;
                break;
            }
            times++;
            pos = (pos + 1) % 7;
        }
        //不要忘了清空!!!!
        hand.clear();
        for (int i = 0; i < 7; i++)
            pile[i].clear();
        ex.clear();
    }
    return 0;
}
//依次查看是否满足情况，（可能多次查看）
/*
2 6 5 10 10 4 10 10 10 4 5 10 4 5 10 9 7 6 1 7 6 9 5 3 10 10 4 10 9 2 1
10 1 10 10 10 3 10 9 8 10 8 7 1 2 8 6 7 3 3 8 2
4 3 2 10 8 10 6 8 9 5 8 10 5 3 5 4 6 9 9 1 7 6 3 5 10 10 8 10 9 10 10 7
2 6 10 10 4 10 1 3 10 1 1 10 2 2 10 4 10 7 7 10
10 5 4 3 5 7 10 8 2 3 9 10 8 4 5 1 7 6 7 2 6 9 10 2 3 10 3 4 4 9 10 1 1
10 5 10 10 1 8 10 7 8 10 6 10 10 10 9 6 2 10 10
0
*/
