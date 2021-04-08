/*
    More Cowbell CodeForces - 604B

    by - SilLea   2021/4/8
*/
#include<algorithm>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 1e5 + 5;
int n;
string str;
int main()
{
    while (cin >> n && n)
    {
        cin >> str;
        int dif = 1;
        for (int i = 0; i < n; i++)
        {
            dif += str[i] != str[n - i - 1];
        }
        cout << min(dif + 2, n) << endl;
    }
    return 0;
}
