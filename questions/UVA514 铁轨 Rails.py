"""
    再谈栈
    本题前前后后, 拖了2个月吧
    之前怎么看紫薯上的解析都看不懂, 最近回来一看, 豁然开朗
    正好最近在学习python, 便用python写了这几行代码
    ===========
    题解待补充
"""
while True:
    n = int(input())
    if not n:
        break
    while True:
        lis = [int(i) for i in input().split(' ')]
        if lis[0] == 0:
            break
        A, B, ok, stack = 1, 0, True, []
        while B < n:
            if A == lis[B]:
                A += 1
                B += 1
            elif len(stack) and stack[-1] == lis[B]:
                stack.pop()
                B += 1
            elif A <= n:
                stack.append(A)
                A += 1
            else:
                ok = False
                break
        print("Yes" if ok else "No")
    print()
