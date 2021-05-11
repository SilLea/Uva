#include <iostream>
#include <iomanip>
using namespace std;
long long read(long long &num)
{
    num = 0;
    long long s = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') s = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') num = num * 10 + ch - '0', ch = getchar();
    return num *= s;
}
int main()
{
    int t;
    long long aa, bb, cc, dd;
    long long x, y, x1, y1, x2, y2;
    cin >> t;
    while (t--)
    {
        read(aa), read(bb), read(cc), read(dd);
        //向左走a步，向右走b步，向下走c步，向上走d步
        read(x), read(y), read(x1), read(y1), read(x2), read(y2);
        if ((x1 == x2 && (aa || bb)) || (y1 == y2 && (cc || dd)))
        {
            cout << "No\n";
        }
        else
        {
            aa = bb - aa;
            cc = dd - cc;
            if (x + aa < x1 || x + aa > x2 || y + cc < y1 || y + cc > y2)
                cout << "No\n";
            else
                cout << "Yes\n";
        }
    }
}
