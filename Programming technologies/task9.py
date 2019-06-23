# 1
n, m = [int(x) for x in input().split()]
a = set()
b = set()
for el in range(n):
    a.add(int(input()))
for el in range(m):
    b.add(int(input()))
print(len(a & b))
print(*sorted(a & b))
print(len(a - b))
print(*sorted(a - b))
print(len(b - a))
print(*sorted(b - a))

# Tkinter2
n = int(input())
w = set()
for x in range(n):
    for el in input().split():
        w.add(el)
print(len(w))

# 3
n = int(input())
students = list()
for i in range(n):
    t = set()
    for j in range(int(input())):
        t.add(input())
    students.append(t)
everyone_knows = set.intersection(*students)
only_one_knows = set.union(*students)
print(len(everyone_knows))
print(*sorted(everyone_knows), sep='\n')
print(len(only_one_knows))
print(*sorted(only_one_knows), sep='\n')
