from math import *

# 1
# находим количество уроков + сумма перемен после четных уроков и нечетных уроков
a = int(input())
a = a * 45 + (a // 2) * 5 + ((a + 1) // 2 - 1) * 15
print(a // 60 + 9, a % 60)

# Tkinter2
# за час часовая стрелка двигается на 30 градусов, за минуту на 0.5 градусов, за секунду на 1 / 120 (источник - Гугл)
h = int(input())
m = int(input())
s = int(input())
summary = h * 30 + m * 0.5 + s / 120
print(summary)

# 3
#
alpha = float(input())
print((alpha * 12) % 360)

# 4
# переводим все в копейки, затем считаем ставку
p = int(input())
x = int(input())
y = int(input())
c = ((x * 100) + y) * ((p + 100) / 100)
print(c // 100)
print(floor(c % 100))
