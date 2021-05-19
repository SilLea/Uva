#include<iostream>
#include<algorithm>
using namespace std;
void get_max(int *a, int &mm)
{
    for (int i = 0; i < 26; i++)
        if (mm < a[i])
            mm = a[i];
}
int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        string line;
        cin >> n >> k >> line;
        int sep = n / k;
        int ans = 0;
        int mid = (k >> 1) + (k & 1);
        for (int j = 0; j < mid; j++)
        {
            //first   :j
            //opposite:k - j - 1
            int cnt[26] = { 0 };
            int mmax = 0;
            for (int i = 0; i < sep; i++)
            {
                char &a = line[i * k + j], &b = line[i * k + k - j - 1];
                //cout << i * k + j << "--" << i * k + k - j - 1 << endl;
                cnt[a - 'a']++, cnt[b - 'a']++;
            }
            get_max(cnt, mmax);
            ans += (sep * 2 - mmax) / (j == k / 2 ? 2 : 1);
            //cout << "======\n";
        }
        cout << ans << endl;
    }
    return 0;
}
/*
4
6 2
abaaba
6 3
abaaba
36 9
hippopotomonstrosesquippedaliophobia
21 7
wudixiaoxingxingheclp
*/
