#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<list>
#include<queue>
#include<deque>
#include<set>
using namespace std;
class A_Coins
{
public:
//3 3 3 3 3
//0 0 1 1 1
//0 1 0 0 0
//1 0 0 0 0
public:
    void start()
    {
        cin >> n >> s;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (n == 1)
        {
            cout << 0;
            return;
        }
        sort(arr, arr + n);
        long long ans = arr[0] - 1;
        int height = 1;
        for (int i = 1; i < n - 1; i++)
        {
            if (arr[i] > height)
            {
                ans += arr[i] - 1;
                height++;
            }
            else
            {
                ans += height - 1;
            }
        }
        if (arr[n - 1] > height) ans += height;
        else ans += arr[n - 1] - 1;
        cout << ans << endl;
    }
private:
    static const int N = 100005;
    long long arr[N];
    int n, s;
}b;
int main()
{
    char END;
    b.start();
    while (cin >> END);
    return 0;
}
