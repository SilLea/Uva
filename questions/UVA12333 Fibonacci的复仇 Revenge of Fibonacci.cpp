/*
    UVA 12333

<<<<<<< HEAD
    by - SilLea  2021/4/16
=======
    by - SilLea  2021/4/17
>>>>>>> 192255d499290c92562a39f0bc57a2e5e26fb721
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int limit = 40;
int ID[256], F[2][22000], cnt, present[42];
typedef struct node1
{
    int    id;
    int    flag;
    node1* v[10];
} tnode;
<<<<<<< HEAD
tnode  dict[4000004];
tnode* root;
tnode* newnode()
=======
tnode  dict[4000004];//全部节点
tnode* root;//根
tnode* newnode()//创造节点
>>>>>>> 192255d499290c92562a39f0bc57a2e5e26fb721
{
    return &dict[cnt++];
}
void TreeInsert(int* A, int len, int id)
{
    tnode* u = root;
    for (int i = 0; i < len; i++)
    {
<<<<<<< HEAD
        if (!u->v[A[i]])
            u->v[A[i]] = newnode();
        if (!u->id && !u->flag)
            u->id = id;
        u = u->v[A[i]];
=======
        if (!u->v[A[i]])//如果没有子节点, 就创造新节点
            u->v[A[i]] = newnode();
        if (!u->id && !u->flag)//如果该节点未被赋值, 赋值
            u->id = id;
        u = u->v[A[i]];//下一个节点
>>>>>>> 192255d499290c92562a39f0bc57a2e5e26fb721
    }
    if (!u->flag)
    {
        u->flag = 1;
        u->id = id;
    }
}
void initial()
{
    for (int i = 0; i < 10; i++)
        ID[i + '0'] = i;
    memset(F, 0, sizeof(F));
    int s = 0, l = 1, r, cont, p, q;
    F[0][0] = F[1][0] = 1;
    root = newnode();
    TreeInsert(F[0], 1, 0);
    for (int i = 2; i < 100000; i++)
    {
        p = i & 1, q = (i + 1) & 1;
        for (int j = s; j < l; j++)
        {
<<<<<<< HEAD
            F[p][j] = F[p][j] + F[q][j];
        }
        for (int j = s; j < l; j++)
        {
            if (F[p][j] >= 10)
=======
            F[p][j] = F[p][j] + F[q][j];//大数相加(最右边是第一位)
        }
        for (int j = s; j < l; j++)
        {
            if (F[p][j] >= 10)//进位
>>>>>>> 192255d499290c92562a39f0bc57a2e5e26fb721
            {
                F[p][j + 1] += 1;
                F[p][j] -= 10;
            }
        }
<<<<<<< HEAD
        if (F[p][l])l++;
        if (l - s > 51)s++;
        r = l - 1, cont = 0;
        while (cont < 40 && r >= 0)
=======
        if (F[p][l])l++;//长度增加
        if (l - s > 51)s++;//只取前52位相加, 优化速度且保证答案正确
        r = l - 1, cont = 0;
        while (cont < 40 && r >= 0)//将数正过来, 插入字典树
>>>>>>> 192255d499290c92562a39f0bc57a2e5e26fb721
            present[cont++] = F[p][r--];
        TreeInsert(present, cont, i);
    }
}
int SearchTree(string& str)
{
    tnode* start = root;
    for (int i = 0; i < str.length(); i++)
    {
        if (!start->v[ID[str[i]]])
            return -1;
<<<<<<< HEAD
        else
            start = start->v[ID[str[i]]];
=======
        start = start->v[ID[str[i]]];
>>>>>>> 192255d499290c92562a39f0bc57a2e5e26fb721
    }
    return start->id;
}
int main()
{
    initial();
    int t;
    string frt;
    cin >> t;
    for (int kase = 1; kase <= t; kase++)
    {
        cin >> frt;
<<<<<<< HEAD
        cout << "Case #" << kase << ": " <<SearchTree(frt) << endl;
=======
        cout << "Case #" << kase << ": " << SearchTree(frt) << endl;
>>>>>>> 192255d499290c92562a39f0bc57a2e5e26fb721
    }
    return 0;
}
