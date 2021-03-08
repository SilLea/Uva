/*
    十六进制转换为八进制
    具体思路: 将十六进制转化为2进制, 4位对应一位
        然后将二进制补零后转化为八进制, 输出
    注意事项:一定要补零!!!!,每个十六进制数长度不超过100000

    by - SilLea    2021/3/8
*/
#include<iostream>
#include<string>
using namespace std;
char str_16_2[17][5] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
char index[200];
bool er[400005];
int oct_[4] = {1, 2, 4, 8};
int answer[400005];
char * converting(string source_str)
{
    int len = source_str.length();
    string mid = "", temp = "";
    for (int i = 0; i < len; i++)
    {
        mid += str_16_2[index[source_str[i]]];
    }
    len = (len * 4) % 3;
    for (int i = 3 - len; i > 0 && len; i--)
        temp += '0';
    mid = temp + mid;
    int cnt = 0;
    bool flag = true;
    for (int i = 0; i < mid.length(); i += 3)
    {
        int decimal = 0;
        decimal = 4*(mid[i]-'0')+2*(mid[i+1]-'0')+(mid[i+2]-'0');
        if (!decimal && !i)flag = false;
        if (flag)
        {
            cout << decimal;
        }
        else flag = true;
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    for (int i = 0; i < 10; i++)
        index['0' + i] = i;
    for (int i = 10; i < 36; i++)
        index['A' + i - 10] = i;
    int n;
    string str;
    cin >> n;
    while (n--)
    {
        cin >> str;
        converting(str);
    }
    return 0;
}
