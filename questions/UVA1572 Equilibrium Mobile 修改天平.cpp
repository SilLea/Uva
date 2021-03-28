/*
    UVA 1572 Equilibrium Mobile 修改天平

        必须改变的砝码数量 = 总砝码数量 - 不变的砝码数量
        当整个天平的结构不变时，平衡的天平和它的总重量又是一一对应的，恰好等于   砝码重量*(2^砝码深度)。
    by - SilLea   2021/3/28
*/
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<long long> v;
long long read_num(const string &str, int &pos)
{
    long long sum = 0;
    for (pos; pos < str.length(); pos++)
    {
        if (str[pos] <= '9' && str[pos] >= '0')
        {
            sum *= 10;
            sum += str[pos] - '0';
            if ((pos + 1 < str.length()) && (str[pos + 1] > '9' || str[pos + 1] < '0'))
                return sum;
        }
    }
    return sum;
}
void calculate(const string &str)
{
    int depth = 0, i = 0;
    v.clear();
    for (i; i < str.length(); i++)
    {
        if (str[i] == '[')
            depth++;
        else if (str[i] == ']')
            depth--;
        else if (str[i] == ',')
            continue;
        else
        {
            long long num = read_num(str, i);
            v.push_back((num << depth));
        }
    }
    sort(v.begin(), v.end());
    int cnt, sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (!i || v[i] != v[i - 1])
            cnt = 1;
        else cnt++;
        sum = max(sum, cnt);
    }
    cout << v.size() - sum << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string input;
        cin >> input;
        calculate(input);
    }
    return 0;
}
