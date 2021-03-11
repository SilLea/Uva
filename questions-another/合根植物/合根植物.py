"""
    dfs题, 用dict存节点, 构图

    by - SilLea  2021/3/10

"""
import sys
sys.setrecursionlimit(1000000) #修改递归深度
m, n = tuple(map(int, input().split()))
vis = [[0] * n for i in range(m)]
mp = {}#字典存节点
num = int(input())
for i in range(num):
    a, b = tuple(map(int, input().split()))
    if mp.get(a) == None:
        mp[a] = [b]
    else:
        mp[a].append(b)
    if mp.get(b) == None:
        mp[b] = [a]
    else:
        mp[b].append(a)


def dfs(vis, nod, cnt):
    if mp.get(nod) == None:
        vis[(nod - 1) // n][(nod - 1) % n] = cnt
        return
    stack = mp[nod]
    while len(stack):
        node = stack.pop()
        if not vis[(node - 1) // n][(node - 1) % n]:
            vis[(node - 1) // n][(node - 1) % n] = cnt
            dfs(vis, node, cnt)


cnt = 0
for i in range(m):
    for j in range(n):
        if not vis[i][j]:
            cnt += 1
            dfs(vis, i * n + 1 + j, cnt)
print(cnt)
