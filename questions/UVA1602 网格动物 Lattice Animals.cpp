#include<iostream>
#include<algorithm>
#include<set>
#include<fstream>
using namespace std;
class UVA1602
{
public:
    //右下左上
    UVA1602() : dx{0, 1, 0, -1}, dy{1, 0, -1, 0} { }
private:
    struct Cell
    {
        int x, y;
        Cell(int a = 0, int b = 0) : x(a), y(b) { }
        bool operator<(const Cell& b) const
        {
            return x != b.x ? x < b.x : y < b.y;
        }
    };
    typedef set<Cell> poly;
    void normalize(poly& p)
    {
        int minx(p.begin()->x), miny(p.begin()->y);
        for (poly::iterator it = p.begin(); it != p.end(); it++)
            minx = min(minx, it->x), miny = min(miny, it->y);
        poly newp;
        for (poly::iterator it = p.begin(); it != p.end(); it++)
            newp.insert(Cell(it->x - minx, it->y - miny));
        p = newp;
    }
    void rotate(poly& p)
    {
        poly newp;
        for (poly::iterator it = p.begin(); it != p.end(); it++)
            newp.insert(Cell(it->y, -it->x));
        p = newp;
        normalize(p);
    }
    void flip(poly& p)
    {
        poly newp;
        for (poly::iterator it = p.begin(); it != p.end(); it++)
            newp.insert(Cell(it->x, -it->y));
        p = newp;
        normalize(p);
    }
    void tyr_to_insert(poly p, Cell& c)
    {
        p.insert(c);
        normalize(p);
        int num = p.size();
        for (int i = 0; i < 4; i++)
            if (set_poly[num].count(p)) return;
            else rotate(p);
        flip(p);
        for (int i = 0; i < 4; i++)
            if (set_poly[num].count(p)) return;
            else rotate(p);
        set_poly[num].insert(p);
    }
    void get_ans()
    {
        for (int i = 0; i < N; i++) set_poly[i] = set<poly>();
        poly p1;
        p1.insert(Cell(0, 0));
        set_poly[1].insert(p1);
        for (int i = 2; i < N; i++)
            for (set<poly>::iterator p = set_poly[i - 1].begin(); p != set_poly[i - 1].end(); p++)
                for (poly::iterator c = p->begin(); c != p->end(); c++)
                    for (int dir = 0; dir < 4; dir++)
                    {
                        Cell nc(c->x + dx[dir], c->y + dy[dir]);
                        if (!p->count(nc))
                        {
                            tyr_to_insert(*p, nc);
                            //cout << "tyr_to_insert" << endl;
                        }
                    }
        for (int i = 1; i < N; i++)
            for (int w = 1; w <= i; w++)
                for (int h = 1; h <= i; h++)
                {
                    int cnt = 0;
                    for (set<poly>::iterator it = set_poly[i].begin(); it != set_poly[i].end(); it++)
                    {
                        int xmax(0), ymax(0);
                        for (poly::iterator c = it->begin(); c != it->end(); c++)
                            xmax = max(xmax, c->x), ymax = max(ymax, c->y);
                        if (min(xmax, ymax) < min(w, h) && max(xmax, ymax) < max(w, h))//两种摆放方式
                            cnt++;
                    }
                    ans[i][w][h] = cnt;
                }
    }
public:
    void start()
    {
        get_ans();
        int n;
        while (cin >> n >> w >> h)
            cout << ans[n][w][h] << endl;
    }
private:
    static const int N = 11;
    set<poly> set_poly[N];
    int ans[N][N][N], dx[4], dy[4], h, w;
}hhhh;
int main()
{
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    hhhh.start();
    return 0;
}
