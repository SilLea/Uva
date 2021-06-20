#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

//  不难发现竖着放的火柴每一列相邻两根编号相差 2 * n + 1。将其记为 d.
//  根据等差数列公式，横着放的第 x 排的第 l 根火柴编号为 (x - 1) * d + l.
//  竖着放的第 l 列的第 y 根火柴编号则为 n + (y − 1) * d + l.

class UVA1603
{
public:
    bool check(int pos, bool* a)
    {
        for (int& e : id[pos])
            if (a[e])
                return false;
        return true;
    }
    int h(void)
    {
        int sum = 0;
        memcpy(tmp, deleted, sizeof(deleted));
        for(int i = 1; i <= cnt; ++i)
        {
            if(check(i, tmp))
            {
                sum++;
                for(const int& e : id[i])
                    tmp[e] = 1;
            }
        }
        return sum;
    }
    bool IDAstar(int cur)
    {
        if (cur + h() > maxd) return false;
        for (int i = 1; i <= cnt; i++)
        {
            if (check(i, deleted))
            {
                for (int& e : id[i])
                {
                    deleted[e] = true;
                    if (IDAstar(cur + 1)) return true;
                    deleted[e] = false;
                }
                return false;
            }
        }
        return true;
    }
    void start()
    {
        int t;
        cin >> t;
        while (t--)
        {
            cin >> n >> k;

            d = (n << 1) + 1;
            cnt = 0;
            memset(deleted, false, sizeof(deleted));
            
            for (int l = 1; l <= n; ++l)
                //枚举左上角坐标为(x,y)且边长为l的正方形。
                for (int x = 1; x <= n - l + 1; ++x)
                    for (int y = 1; y <= n - l + 1; ++y)
                    {
                        id[++cnt].clear();
                        for (int i = 1; i <= l; ++i)
                        {
                            //上面那条横边
                            id[cnt].push_back((x - 1) * d + i + y - 1);
                            //下面那条横边
                            id[cnt].push_back((x + l - 1) * d + i + y - 1);
                            //左边那条竖边
                            id[cnt].push_back(n + (x + i - 2) * d + y);
                            //右边那条竖边
                            id[cnt].push_back(n + (x + i - 2) * d + y + l);
                        }
                    }
            
            int temp;
            while (k--)
                cin >> temp, deleted[temp] = true;
            
            for (maxd = h();;maxd++)
            {
                if (IDAstar(0))
                {
                    cout << maxd << endl;
                    break;
                }
            }
        }
    }
private:
    static const int N = 60;
    int n, k, d, cnt, maxd;
    vector<int> id[N];
    bool deleted[N], tmp[N];
};
UVA1603 thesolution;
int main()
{
    thesolution.start();
    return 0;
}
