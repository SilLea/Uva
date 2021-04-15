/*
    B - Young Explorers

    by - SilLea  2021/4/15
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(n) for (int i = 0; i < (n); i++)
using namespace std;
const int maxn = 1e6 + 10;
int n, s;
int main()
{
    //不能有0
    //array长度为n, 总和为s
    cin >> n >> s;
    if (s >= 2 * n)
    {
        cout << "YES" << endl;
        for (int i = 0; i < n - 1; i++)
            cout << "1 ";
        cout << s - n + 1 << endl;
        cout << n;
    }
    else
        cout << "NO";
    return 0;
}
//n - 1 个 1
//1 个 s - n + 1
//n到(s-n) 没有

//1 1 2 -> 1 2 3 4
//4 -> 4 no 1 2 3
//1 1 6 -> 1 2 6 7 8 no 3 4 5

//4 8
//1 1 1 5 -> 1 2 3  5 6 -> no 4 -> YES
