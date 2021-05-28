#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
class A
{
public:
    A():n(0), arr{ 0 } {}
public:
    bool start()
    {
        if (!(cin >> n) || !n) return false;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        //arr[n + 1] = arr[n] + 1;
        arr[0] = 0;
        int cnt = 0, _max = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i == 1 && arr[i + 1] == 2)
                ++cnt;
            else if (i == n && arr[i - 1] == 999)
                ++cnt;
            else if (arr[i] + 1 == arr[i + 1] && arr[i] - 1 == arr[i - 1])
                ++cnt;
            else
                _max = max(_max, cnt), cnt = 0;
        }
        _max = max(_max, cnt);
        cout << _max << endl;
        return true;
    }
private:
    static const int N = 105;
    int n, arr[N];
};
class B
{
public:
    B(){}
public:
    void get_list(int &_max)
    {
        _max = 0;
        int temp = n;
        for (int i = 2; i <= temp; i++)
        {
            if (temp % i == 0)
                vec[cnt++] = i;
            while (temp % i == 0)
                ++arr[i], temp /= i;
            _max = max(_max, arr[i]);
            if (temp == 1) break;
        }
    }
    void init()
    {
        cnt = 0;
        memset(arr, 0, sizeof(arr));
    }
    bool start()
    {
        cin >> n;
        init();
        int _max;
        get_list(_max);
        int ans = 1, ans2 = 0, ans3 = 0;
        for (int i = 0; i < cnt; i++)
            ans *= vec[i], ans2 = max(ans2, _max - arr[vec[i]]);
        int temp = 1;
        while (temp < _max)
            (temp <<= 1), ++ans3;
        cout << ans << " " << ans3 + (_max && (ans2 || temp != _max) ? 1 : 0);
        return true;
    }
private:
    int n;
    static const int N = 1e6 + 5;
    int arr[N], vec[10005], cnt = 0;
}solve;
int main()
{
    return 0;
}
