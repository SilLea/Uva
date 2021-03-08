"""
    蓝桥杯历年真题中的一个
    本体主要难点在于随意2-36的进制转换, 这个进制转换是我从知乎大佬里拷贝的, 有空研究一下
    有几个注意点, 就是当result为''时, 需要特别注意一下(在这里卡了好久

    By - SilLea   2021/3/8
"""
n = int(input())
change = 10
str_36 = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
dict_36 = {}
for j in range(len(str_36)):
    dict_36[str_36[j]] = j


def converting(source_str, source_hex, target_hex):
    global dict_36
    str_b = str_36[:target_hex]
    result = ''
    decimal_num = 0
    for i in range(len(source_str)):
        decimal_num += dict_36[source_str[-i-1]] * (source_hex ** i)
    quotient_int = decimal_num
    while quotient_int:
        remainder = quotient_int % target_hex
        quotient_int = quotient_int // target_hex
        result = str_b[remainder] + result
        if quotient_int and quotient_int < target_hex:
            result = str_b[quotient_int] + result
            break
    return result


def operator(lis, op):
    a = lis.pop()
    b = lis.pop()
    if op[0] == 'A':
        lis.append(b + a)
    elif op[0] == 'S':
        lis.append(b - a)
    elif op[0] == 'D':
        lis.append(b // a)
    elif op[0] == 'M':
        if op[1] == 'U':
            lis.append(b * a)
        if op[1] == 'O':
            lis.append(b % a)
    return


ok, op = False, str
num = []
while n:
    cmd = input().split()
    if cmd[0] == 'CHANGE':
        change = int(cmd[1])
    elif cmd[0] == 'NUM':
        result = converting(cmd[1], change, 10)
        num.append(0 if result == '' else int(result))
        if ok:
            operator(num, op)
            ok, op = False, ''
    elif cmd[0] == 'EQUAL':
        answer = converting(str(num[0]), 10, change)
        print(0 if answer == '' else answer)
    elif cmd[0] == 'CLEAR':
        num = []
    else:
        op = cmd[0]
        ok = True
    n -= 1
