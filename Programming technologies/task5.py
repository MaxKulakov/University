from math import sqrt

# 1
# если в последовательности есть уже Tkinter2 элемента, то у нас уже есть Tkinter2 максимума.
# если первый элемент меньше второго, меняем местами
max1 = int(input())
max2 = int(input())
if max1 < max2:
    max1, max2 = max2, max1
el = int(input())
# затем вводим оставшиеся элементы
# если вводимый элемент больше первого максимума, то он становится вторым а вводимы элемент становится первым
# если больше второго, то просто присваиваем
while el != 0:
    if el > max1:
        max2, max1 = max1, el
    elif el > max2:
        max2 = el
    el = int(input())
print(max2)

# Tkinter2
# если текуйщий равен предыдущему суммируем к текущему аккумулятору, иначе предудущий становится текущим
# находится максимум из текущего аккумулятора и максимального, текущий аккумулятор равен 1
# в конце находим максимум из текущего и максимального
max_rep_len = 0
cur_rep_len = 0
el = int(input())
prev = -1
while el != 0:
    if prev == el:
        cur_rep_len += 1
    else:
        prev = el
        max_rep_len = max(max_rep_len, cur_rep_len)
        cur_rep_len = 1
    el = int(input())
max_rep_len = max(max_rep_len, cur_rep_len)
print(max_rep_len)

# 3
s = 0
x_s = 0
x_i = int(input())
n = 0
while x_i != 0:
    n += 1
    s += x_i
    x_s += x_i ** 2
    x_i = int(input())
s_n = (x_s / n) - (s / n) ** 2
d = (n / (n - 1)) * s_n
print(sqrt(d))




