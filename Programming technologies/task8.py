# 1
n = int(input())
a = [['.'] * n for i in range(n)]
for i in range(n):
    a[i][n // 2] = '*'
    a[n // 2][i] = '*'
    a[i][i] = '*'
    a[i][n - i - 1] = '*'
for row in a:
    print(' '.join(elem for elem in row))

# Tkinter2
n = int(input())
a = [[0] * n for i in range(n)]
for i in range(n):
    for j in range(n):
        a[i][j] = abs(i - j)
for row in a:
    print(' '.join(str(elem) for elem in row))

# 3
n = int(input())
a = []
for i in range(n):
    a.append(input())
for i in a:
    if ''.join('x' for j in range(n)) in i:
        print('x')
        break
    if ''.join('o' for j in range(n)) in i:
        print('o')
        break
else:
    for i in range(n):
        s = ''
        for k in range(n):
            s += a[k][i]
        if ''.join('x' for j in range(n)) in s:
            print('x')
            break
        if ''.join('o' for j in range(n)) in s:
            print('o')
            break
    else:
        print('.')

