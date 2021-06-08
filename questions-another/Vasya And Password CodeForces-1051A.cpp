#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
char s[3] = {'A', 'a', '1'};
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string str;
        //大写 小写 数字
        stack<int> arr[3];
        cin >> str;
        for (int i = 0; i < str.length(); i++)
        {
            if (isupper(str[i]))
                arr[0].push(i);
            else if (islower(str[i]))
                arr[1].push(i);
            else if (isdigit(str[i]))
                arr[2].push(i);
        }
        for (int i = 0; i < 3; i++)
        {
            if (arr[i].empty())
            {
                for (int j = 0; j < 3; j++)
                {
                    if (j != i && arr[j].size() > 1)
                    {
                        int pos = arr[j].top();
                        arr[j].pop();
                        str[pos] = s[i];
                        arr[i].push(pos);
                        break;
                    }
                }
            }
        }
        cout << str << endl;
    }
    return 0;
}
