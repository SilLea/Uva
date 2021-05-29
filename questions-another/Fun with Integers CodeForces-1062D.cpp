#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

class EulerPrime
{
private:
    int n, * prime, cnt;
    bool* isprime;
    void askForMemory()
    {
        prime = new int[n + 1];
        isprime = new bool[n + 1];
        memset(isprime, false, n + 1);
    }
public:
    EulerPrime():n(0), prime(NULL), cnt(0), isprime(NULL){}
    ~EulerPrime() { delete[]prime; delete[]isprime; }
public:
    EulerPrime& setN(const int& N) { n = N; return *this; }
    const int& operator[] (const int& pos) { return prime[pos]; }
    const bool IsPrime(const int& pos) { return !isprime[pos]; }
    void print()
    {
        int prt = 0;
        for (int i = 0; i < cnt; i++)
            cout << prime[i] << (++prt % 20 ? " " : "\n");
        cout << endl;
    }
    EulerPrime& getPrime()
    {
        askForMemory();
        for (int i = 2; i <= n; i++)
        {
            if (!isprime[i]) prime[cnt++] = i;
            for (int j = 0; j < cnt && prime[j] * i <= n; j++)
            {
                isprime[prime[j] * i] = true;
                if (i % prime[j] == 0) break;
            }
        }
        return *this;
    }
    int getcnt() { return cnt; }
}ep;
long long solve(int i)
{
    //a * x = b
    long long sum(0), ed = sqrt(i);
    for (long long x = 2; x <= ed; x++)
    {
        if (i % x == 0)
        {
            sum += i / x;
            if (i / x != x)
                sum += x;
        }
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    ep.setN(n).getPrime();
    long long *dp = new long long[n + 2];
    dp[1] = 0;
    for (long long i = 2; i <= n; i++)
    {
        if (ep.IsPrime(i))//素数
            dp[i] = dp[i - 1];
        else//合数
            dp[i] = dp[i - 1] + solve(i);
    }
    cout << dp[n] * 4 << endl;
    delete[] dp;
    return 0;
}
