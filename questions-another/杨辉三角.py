def create_list_tri(lis: list, n: int):
    """
    创造一个list型的杨辉三角
    """
    for i in range(n):
        for j in range(i + 1):
            if j == 0 or j == i:
                lis[i][j] = 1
            else:
                lis[i][j] = lis[i - 1][j] + lis[i - 1][j - 1]


def print_list_tri(lis: list):
    for i in lis:
        print(i)


def print_normal_tri(lis):
    for i in range(len(lis)):
        for j in range(len(lis) - i):
            print('   ', end='')
        for each_val in range(len(lis[i]) - 1):
            print(f'{lis[i][each_val]:<3}   ', end='')
        print(lis[i][-1])


n = int(input())
lis = [[0] * (i + 1) for i in range(n)]
create_list_tri(lis, n)
for i in range(len(lis)):
    for each_val in range(len(lis[i]) - 1):
        print(f'{lis[i][each_val]} ', end='')
    print(lis[i][-1])