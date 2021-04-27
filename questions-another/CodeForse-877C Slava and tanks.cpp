#include<iostream>
#include<string>
using namespace std;
const int maxn = 110;
string s;
string frd[] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 2 << endl << "1 1";
        return 0;
    }
    if (n & 1)
        cout << (n + 1) / 2 + (n / 2) * 2 << endl;
    else
        cout << (n / 2) * 3 << endl;
    bool first = true;

    for (int i = 2; i <= n; i += 2)
        cout << (first ? "" : " ") << i, first = false;

    for (int i = 1; i <= n; i += 2)
        cout << (first ? "" : " ") << i;

    for (int i = 2; i <= n; i += 2)
        cout << (first ? "" : " ") << i;

    return 0;
}
