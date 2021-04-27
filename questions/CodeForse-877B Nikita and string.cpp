#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#define cl(name, mod) memset(name, mod, sizeof(name))
using namespace std;
int a[5010], b[5010];
string s;
int main()
{
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        a[i] += a[i - 1] + (s[i] == 'a');
        b[i] += b[i - 1] + (s[i] == 'b');
    }
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
        for (int j = i; j < s.length(); j++)
        {
            ans = max(ans, a[i] + a[s.length() - 1] - a[j] + b[j] - b[i - 1]);
        }
    cout << ans;
    return 0;
}
