# 1
# находим остаток от деления числа и если он не равен 1 то не выводим число
x = int(input())
y = int(input())
for i in range(x, y - 1, - 1):
    c = i % 2
    not c == 1 or print(i)

# Tkinter2
# в цикле проверяем равно ли число нулю и считаем их
n = int(input())
c = 0
for i in range(n):
    x = int(input())
    if x == 0:
        c += 1
print(c)

# 3
# сначал считаем сумму введеных карточек
# затем считаем сумму всех возможных карточек
# выводим разность
n = int(input())
rest = 0
for i in range(1, n):
    rest += int(input())
acc = 0
for i in range(n + 1):
    acc += i
print(acc - rest)
