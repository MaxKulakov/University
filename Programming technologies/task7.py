import re
from math import factorial

# 1
s = input()
a = list(s.split())
for i in range(len(a)):
    a[i] = int(a[i])
for i in range(len(a)):
    if a[i] % 2 == 0:
        print(a[i])
for i in range(len(a) - 1):
    if a[i] * a[i + 1] > 0:
        print(a[i])
        print(a[i + 1])
        break
minimum = min(a)
maximum = max(a)
print(a.index(minimum))
print(a.index(maximum))
a.sort()
cnt = 0
for i in range(len(a) - 1):
    if a[i] != a[i + 1]:
        cnt += 1
print(cnt)
# alternative solution
print(len(set(a)))

# Tkinter2
# проверяем пары ферзей на возможность пробития друг друга
# берем условие из задачи на условный оператор
n = 8
x = []
y = []
for i in range(n):
    new_x, new_y = [int(s) for s in input().split()]
    x.append(new_x)
    y.append(new_y)

correct = True
for i in range(n):
    for j in range(i + 1, n):
        if x[i] == x[j] or y[i] == y[j] or abs(x[i] - x[j]) == abs(y[i] - y[j]):
            correct = False
if correct:
    print('NO')
else:
    print('YES')

# 3
s = input()
a = list(s.split(','))
a.sort()
b = list()
for word in a:
    if re.findall(r'[\W]', word):
        b.append(word)
print(b)
max_length = 0
for word in b:
    if len(word) > max_length:
        max_length = len(word)
for word in b:
    print(' ' * (max_length - len(word)) + word)

# 4
s = input().split()

stack = list()
for i in s:
    if i == '+':
        a, b = stack.pop(), stack.pop()
        stack.append(a + b)
    elif i == '-':
        a, b = stack.pop(), stack.pop()
        stack.append(b - a)
    elif i == '*':
        a, b = stack.pop(), stack.pop()
        stack.append(b * a)
    elif i == '/':
        a, b = stack.pop(), stack.pop()
        stack.append(b // a)
    elif i == '~':
        a = stack.pop()
        stack.append(int(-a))
    elif i == '!':
        a = stack.pop()
        stack.append(factorial(a))
    elif i == '#':
        a = stack.pop()
        stack.append(a)
        stack.append(a)
    elif i == '@':
        a, b, c = stack.pop(), stack.pop(), stack.pop()
        stack.append(a)
        stack.append(b)
        stack.append(c)
    else:
        stack.append(int(i))
print(stack[0])




