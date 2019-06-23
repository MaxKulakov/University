# 1
n = int(input())
d = dict()
for s in range(n):
    for w in input().split():
        if w not in d:
            d[w] = 1
        else:
            d[w] += 1
sort = list()
for k, v in d.items():
    sort.append((-v, k))
output = list()
sort = sorted(sort)
for el in sort:
    print(el[1])

# Tkinter2
p = dict()
for _ in range(int(input()) - 1):
    k, v = input().split()
    p[k] = v

# совершаем своебразный обход дерева от потомка к родителю
for k, v in sorted(p.items()):
    print(k, end=' ')
    level = 0
    while k in p:
        level += 1
        k = p[k]
    print(level)

# 3
n = int(input())
classmates = dict()
for _ in range(n):
    name, day, month = input().split()
    classmates[name] = (day, month)
m = int(input())
months = list()
for _ in range(m):
    months.append(input())
ans = list()
for i in range(m):
    ans.append([])
for i in range(m):
    for key in classmates:
        if months[i] == classmates[key][1]:
            ans[i].append((classmates[key][0], key))
for el in ans:
    if el is not []:
        for sub in sorted(el):
            print(sub[1], sub[0], sep=' ')
    print()
