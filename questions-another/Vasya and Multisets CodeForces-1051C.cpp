#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<cstring>
using namespace std;
class C
{
public:
    C() : len(0), len2(0) { }
    void start()
    {
        memset(arr, 0, sizeof(arr));
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (!cnt[arr[i]]) pick[len++] = arr[i];
            cnt[arr[i]]++;
        }
        int beauty = 0;
        for (int i = 0; i < len; i++)
            if (cnt[pick[i]] == 1)
                ++beauty, bea[len2++] = pick[i];
        if (beauty & 1)
        {
            int to_be_part = -1;
            for (int i = 0; i < len; i++)
                if (cnt[pick[i]] > 2)
                {
                    to_be_part = pick[i];
                    break;
                }
            if (to_be_part == -1)
            {
                puts("NO");
                return;
            }
            beauty++;
            puts("YES");
            int f = 0, x = 0;
            for (int i = 0; i < n; i++)
            {
                if (!f && arr[i] == to_be_part)
                {
                    putchar('B');
                    f = 1;
                }
                else if (cnt[arr[i]] > 1) putchar('A');
                else
                {
                    if (x < (beauty >> 1))
                    {
                        putchar('A');
                        x++;
                    }
                    else
                    {
                        putchar('B');
                    }
                }
            }
        }
        else
        {
            puts("YES");
            int x = 0;
            for (int i = 0; i < n; i++)
            {
                if (cnt[arr[i]] > 1) putchar('A');
                else
                {
                    if (x < (beauty >> 1))
                    {
                        putchar('A');
                        x++;
                    }
                    else
                    {
                        putchar('B');
                    }
                }
            }
        }
    }
private:
    static const int N = 105;
    int n, len, len2;
    int arr[N], cnt[N], pick[N], bea[N];
}hhh;
int main()
{
    hhh.start();
    return 0;
}
