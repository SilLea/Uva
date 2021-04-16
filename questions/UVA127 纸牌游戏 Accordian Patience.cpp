/*
    UVA 127

    by - SilLea  2021/4/16
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
#include<sstream>
#define rep(n) for (int i = 0; i < (n); i++)
using namespace std;
const int maxn = 52;
int main()
{
    while (true)
    {
        char corlor, num;
        int cnt = 52, _end = 52;
        stack<pair<char, char>>card[maxn];
        cin >> num;
        if (num == '#')
            return 0;
        cin >> corlor;
        card[0].push(make_pair(num, corlor));
        for (int i = 1; i < 52; i++)
        {
            cin >> num >> corlor;
            card[i].push(make_pair(num, corlor));
        }
        int ok = 1, p1, p2;
        while (ok)
        {
            ok = 0;
            for (int i = 0; i < _end && !ok; i++)
            {
                p1 = i > 0 ? i - 1 : -1;
                p2 = i > 2 ? i - 3 : -1;
                if (p2 != -1 && (card[p2].top().first == card[i].top().first || card[p2].top().second == card[i].top().second))
                {
                    card[p2].push(card[i].top());
                    card[i].pop();
                    ok = 1;
                }
                else if (p1 != -1 && (card[p1].top().first == card[i].top().first || card[p1].top().second == card[i].top().second))
                {
                    card[p1].push(card[i].top());
                    card[i].pop();
                    ok = 1;
                }
                if (card[i].empty())
                {
                    for (int j = i; j < _end - 1; j++)
                        card[j] = card[j + 1];
                    _end--;
                }
            }
        }
        cout << _end << (_end == 1 ? " pile":" piles") << " remaining:";
        for (int i = 0; i < _end; i++)
            cout << ' ' << card[i].size();
        cout << endl;
    }
    return 0;
}
