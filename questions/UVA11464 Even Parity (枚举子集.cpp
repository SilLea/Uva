/*
    UVA11464 Even Parity
    题目描述:
        给你一个 n*n, n*n 的 01 矩阵（就是每个元素只可能为0和1）
        你的任务是把尽量少的 0 变成 1 ,使得每个元素的上，下，左，右的元素（存在的情况下）之和均为偶数。

    思路：枚举第一行的所有情况（因为只看上下左右，所以第一行确定后，就可以确定剩余行的情况了

    by - SilLea   2021/3/15
*/
#include<iostream>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 15 + 1;
const int inf = 0x7fffffff;
const int NX[3] = {0, 0, -1};
const int NY[3] = {-1, 1, 0};
bool board[maxn][maxn], boarded[maxn][maxn];
int n, ans;
int trans(const int &sub)
{
    int change = 0;
    for (int i = 0; i < n; i++)//表示出第一排
    {
        boarded[0][i] = sub & (1 << i);
        if (!boarded[0][i] && board[0][i])
                return inf;
        change += boarded[0][i] && !board[0][i];
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int dir = 0; dir < 3; dir++)//分别对应左右上三个方向
            {
                int nx = i + NX[dir];
                int ny = j + NY[dir];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                    sum += boarded[nx][ny];//三个方向的和
            }
            //cout << "i:" << i << " j:" << j << "--" << sum << endl;
            if ((sum & 1) == 0 && boarded[i + 1][j])
                    return inf;//和是偶数, 但下方数为1
            if ((sum & 1) == 1 && !boarded[i + 1][j])//和是奇数, 且下方数为0
            {
                change++;
                boarded[i + 1][j] = 1;
            }
        }
    return change;
}
int main()
{
    freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
    int Kase;
    cin >> Kase;
    for (int kase = 1; kase <= Kase; kase++)
    {
        cin >> n;
        ans = inf;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> board[i][j];
        for (int sub = 0; sub < (n << n); sub++)//用二进制枚举第一排
        {
            for (int i = 1; i < n; i++)
                for (int j = 0; j < n; j++)
                {
                    boarded[i][j] = board[i][j];//复制除了第一排的所有排
                }
            ans = min(ans, trans(sub));//更新答案
        }
        cout << "Case " << kase << ": " << (ans == inf ? -1 : ans) << endl;
    }
    return 0;
}
