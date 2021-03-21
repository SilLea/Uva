/*
    UVa814 邮件传输代理的交互

    by - SilLea   2021/3/17
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
void split(const string& s, string& user, string& mta)
{
    int k=s.find('@');
    user=s.substr(0,k);
    mta=s.substr(k+1);
}
int main()
{
    int k;
    string s, t, user1, mta1 ,user2, mta2;
    set<string> addr;
    while(cin >> s && s != "*")
    {
        cin >> s >> k;
        while(k--)
        {
            cin >> t;
            addr.insert(t + "@" + s);//转化为邮箱地址并存储
        }
    }
    while(cin >> s && s != "*")
    {
        split(s, user1, mta1);  //处理发件人地址
        vector<string> mta;  //所有需要连接的mta，按照输入顺序
        map<string, vector<string>> dest; //每个MTA需要发送的用户
        set<string> vis;
        while(cin >> t && t != "*")
        {
            split(t, user2, mta2); //处理收件人地址
            if(vis.count(t)) continue; //重复的收件人
            vis.insert(t);
            if(!dest.count(mta2))
            {
                mta.push_back(mta2);
                dest[mta2]=vector<string>();
            }
            dest[mta2].push_back(t);
        }
        getline(cin, t); //把“*”这一行的回车吃掉

        string text; //输入邮件正文
        while(getline(cin, t) && t[0] != '*') text += "     " + t + "\n";
        for(int i = 0; i < mta.size(); i++)
        {
            string mta2 = mta[i];
            vector<string> users = dest[mta2];
            cout << "Connection between " << mta1 << " and " << mta2 <<endl;
            cout << "     HELO " << mta1 << "\n";
            cout << "     250\n";
            cout << "     MAIL FROM:<" << s << ">\n";
            cout << "     250\n";
            bool ok = false;
            for(int i=0; i < users.size(); i++)
            {
                cout<<"     RCPT TO:<" << users[i] << ">\n";
                if(addr.count(users[i]))
                {
                    ok = true;
                    cout << "     250\n";
                }
                else cout<<"     550\n";
            }
            if(ok)
            {
                cout << "     DATA\n";
                cout << "     354\n";
                cout << text;
                cout << "     .\n";
                cout << "     250\n";
            }
            cout << "     QUIT\n";
            cout << "     221\n";
        }
    }
    return 0;
}
