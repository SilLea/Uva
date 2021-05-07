#include<iostream>
using namespace std;
const int maxn = 2010;
int save[maxn];
int main()
{
    int t, n, a, b;
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (i < a)
            {
                putchar('a' + cnt);
                save[i] = cnt;
                if (cnt != b - 1) cnt++;
            }
            else
            {
                putchar('a' + save[i - a]);
                save[i] = save[i - a];
            }
        }
        cout << endl;
    }
    return 0;
}
