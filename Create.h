#pragma once
//求最大公约数
int gcd(int m, int n)
{
    if (m % n == 0)return n;
    return gcd(n, m % n);
}

//判断某数是否为素数(效率较低)
#include<math.h>
int isPrime(unsigned long long int m)
{
    if (m == 1)return 0;
    if (m == 2)return 1;
    if (m == 3)return 1;

    if (m % 6 != 1 && m % 6 != 5)return 0;//只要是素数对6取余一定等于1或5（这里指除2 3 之外的素数）
    else {
        unsigned long long int t = sqrt(m);
        for (int i = 5; i <= t; i += 6) {
            if (m % i == 0 || m % (i + 2) == 0)return 0;
        }
        return 1;
    }
}

//欧拉筛法筛选素数
#include<malloc.h>
#include<string.h>
#include<stdio.h>
int* prime;
int* isprime;
int cnt = 0;
void euler_prime(int n)
{
    prime = (int*)malloc((n + 1) * sizeof(int));
    isprime = (int*)malloc((n + 1) * sizeof(int));
    memset(isprime, 0, n * sizeof(int));
    for (int i = 2; i <= n; i++)
    {
        if (!isprime[i])
            prime[cnt++] = i;
        for (int j = 0; j < cnt; j++)
        {
            if (i * prime[j] > n)break;
            isprime[i * prime[j]] = 1;
            if (i % prime[j] == 0)break;
        }
    }
}
void fr_prime()
{
    free(prime);
    free(isprime);
}

//BigInteger
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
//现阶段只支持正整数相加
struct BigInteger
{
	static const int BASE = 100000000;
	static const int WIDTH = 8;
	vector<int>s;

	BigInteger(LL num = 0) { *this = num; };

	BigInteger operator = (LL);
	BigInteger operator = (const string&);
	const BigInteger operator + (const BigInteger&) const;
	friend ostream& operator << (ostream&, const BigInteger&);
	friend istream& operator >> (istream&, const BigInteger&);
};
//const: 
//第一个表示返回值为常量 
//第二个表示传入的参数为常量,扩大接收参数的范围 
//第三个使得该函数可以被 const 对象所调用
const BigInteger BigInteger::operator+(const BigInteger& b) const
{
	BigInteger c;
	c.s.clear();
	for (int i = 0, g = 0; ; i++)
	{
		if (g == 0 && i >= s.size() && i >= b.s.size())break;//i 为 biginteger 的段数,将所有段数相加 当i >= s.size() && i >= b.s.size()时,结束
		int x = g;
		if (i < s.size())x += s[i];
		if (i < b.s.size())x += b.s[i];
		c.s.push_back(x % BASE);
		g = x / BASE;
	}
	return c;
}
BigInteger BigInteger::operator=(LL num)
{
	s.clear();
	do {
		s.push_back(num % BASE);
		num /= BASE;
	} while (num);
	return *this;
}
BigInteger BigInteger::operator=(const string& str)
{
	s.clear();
	int x, len = (str.length() - 1) / WIDTH + 1;
	for (int i = 0; i < len; i++)
	{
		int end = str.length() - i * WIDTH;
		int start = (0 < end - WIDTH) ? (end - WIDTH) : 0;
		sscanf(str.substr(start, end - start).c_str(), "%d", &x);
		s.push_back(x);
	}
	return *this;
}
ostream& operator << (ostream& out, const BigInteger& bi)
{
	out << bi.s.back();
	char buf[10];
	for (int i = bi.s.size() - 2; i >= 0; i--)
	{
		sprintf(buf, "%08d", bi.s[i]);
		for (int j = 0; j < 8; j++)
			out << buf[j];
	}
	return out;
}
istream& operator >> (istream& in, BigInteger& bi)
{
	string temp;
	if (!(in >> temp))return in;//如果没有元素进入输入流
	bi = temp;
	return in;
}