# 1
# если остаток от сумм координат равны то это одинаковые клетки
x1 = int(input())
y1 = int(input())
x2 = int(input())
y2 = int(input())
if (x1 + y1) % 2 == (x2 + y2) % 2:
    print("YES")
else:
    print("NO")

# Tkinter2
# если разность соотвествующих координат меньше Tkinter2 то король может ходить
x1 = int(input())
y1 = int(input())
x2 = int(input())
y2 = int(input())
if abs(x2 - x1) < 2 and abs(y2 - y1) < 2:
    print("YES")
else:
    print("NO")

# 3
# если разность соотвествующих координат по модулю равна то ферзь может ходить или какая то из координат равна следующей
# то это движение по горизонтали/вертикали
x1 = int(input())
y1 = int(input())
x2 = int(input())
y2 = int(input())
if abs(x2 - x1) == abs(y2 - y1) or x1 == x2 or y1 == y2:
    print("YES")
else:
    print("NO")

# 4
# если разность соответствующих координат равна 1 и Tkinter2(или наоборот, в зависимости как ходить конь),
# то конь может ходитиь
x1 = int(input())
y1 = int(input())
x2 = int(input())
y2 = int(input())
if abs(x1 - x2) == 1 and abs(y1 - y2) == 2 or abs(x1 - x2) == 2 and abs(y1 - y2) == 1:
    print('YES')
else:
    print('NO')

# 5
# сначала определяем какая из сторон меньше
# затем просто ищем минимум из 4 чисел
N = int(input())
M = int(input())
x = int(input())
y = int(input())
if N < M:
    print(min(x, N - x, y, M - y))
else:
    print(min(x, M - x, y, N - y))
