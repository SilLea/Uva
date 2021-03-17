/*
    LA 2995
        输入一个数字n, 以下n行分别为"前左后右顶底"视图(空格隔开), (顶视图的起点是前视图的末尾)
        每个方块六个面均被染成一种颜色, 你的任务是计算出该方块最多能含有的方块数
        '.'表示可以被看穿
    思路在注释中
    by - SilLea   2021/3/17
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
const int maxn = 20;
int n, x, y, z;
//view存各种视图, cube是立方体
char view[6][maxn][maxn], cube[maxn][maxn][maxn];
//读取字符, 忽略space符
char read_char()
{
    char ch;
    for (;;)
    {
        ch = getchar();
        if ((ch >= 'A' && ch <= 'Z') || ch == '.')
            return ch;
    }
}
//前 左 后 右 顶 底
//将视图中i j deep(深度), 转化为原方块中的坐标,即 x y z
//这可能是最关键的一步了, 务必多想
void get_xyz(int k, int i, int j, int deep, int &x, int &y, int &z)
{
    if (k == 0)
    {
        x = deep, y = j, z = i;
    }
    else if (k == 1)
    {
        x = n - 1 - j, y = deep, z = i;
    }
    else if (k == 2)
    {
        x = n - 1 - deep, y = n - 1 - j, z = i;
    }
    else if (k == 3)
    {
        x = j, y = n - 1 - deep, z = i;
    }
    else if (k == 4)
    {
        x = n - 1 - i, y = j, z = deep;
    }
    else if (k == 5)
    {
        x = i, y = j, z = n - 1 - deep;
    }
}
//读取输入数据, 并稍做处理(将可以看穿的行列删除)
void read_input()
{
    memset(cube, '#', sizeof(cube));
    REP(i, n) REP(k, 6) REP(j, n)
        view[k][i][j] = read_char();
    REP (k, 6) REP (i, n) REP(j, n) if (view[k][i][j] == '.')//删除一整行或列
    {
        REP (dp, n)
        {
            get_xyz(k, i, j, dp, x, y, z);
            cube[x][y][z] = '.';
        }
    }
}
//主操作
//将所有矛盾的点删除, 留下没有矛盾的点, 用于计数
void delete_block()
{
    while (true)
    {
        bool done = true;//如果done为true, 表示没有可以删除的方块了, 退出循环
        REP(k, 6) REP(i, n) REP(j, n) if (view[k][i][j] != '.')//遍历视图
        {
            REP(dp, n)//遍历深度
            {
                get_xyz(k, i, j, dp, x, y, z);//得到坐标
                if (cube[x][y][z] == '.') continue;//如果已经被删除, 深度增加
                if (cube[x][y][z] == '#')//如果未被染色, 染色
                {
                    cube[x][y][z] = view[k][i][j];
                    break;
                }
                if (cube[x][y][z] == view[k][i][j])//如果视图和方块没有矛盾, 退出
                    break;
                cube[x][y][z] = '.';//有矛盾, 删除该方块, 深度增加
                done = false;
            }
        }
        if (done)
            break;
    }
}
int count_num()
{
    int cnt = 0;//计数
    REP (i, n) REP (j, n) REP (k, n)
        if (cube[i][j][k] != '.')
            cnt++;
    return cnt;
}
int main()
{
    while (cin >> n && n)
    {
        read_input();
        delete_block();
        cout << "Maximum weight: " << count_num() << " gram(s)" << endl;
    }
    return 0;
}
