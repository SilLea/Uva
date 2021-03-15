/*
    UVA11729 Commando War
    题目描述:
    有N个人, 吩咐该人的时间为B[i], 该人执行所需的时间为J[i]
    输出:最短时间
    贪心

    by - SilLea   2021/3/15
*/
#include<iostream>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1000 + 5;
int n;
struct per
{
    int b = 0, j = 0;
    bool operator < (const per& b)
    {
        return this->j > b.j;
    }
}each_one[maxn];
int main()
{
    int kase = 0;
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++)
            cin >> each_one[i].b >> each_one[i].j;
        sort(each_one, each_one + n);
        int T(0), start(0);
        for (int i = 0; i < n; i++)
        {
            start += each_one[i].b;
            T = max(T, start + each_one[i].j);
        }
        cout << "Case " << ++kase << ": " << T << endl;
    }
    return 0;
}
