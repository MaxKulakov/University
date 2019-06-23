# 1
a = int(input())
b = int(input())
c = int(input())
print(a + b + c)

# Tkinter2
b = int(input())
h = int(input())
print(b * h / 2)

# 3
n = int(input())
k = int(input())
print(k // n)
print(k % n)

# 4
# делением на 60 узнаем количество часов для n минут.
# делением с остатком на 24 узнаем количество часов с начала новых суток
n = int(input())
print(n // 60 % 24, n % 60)


# 5
n = input()
print("Hello, " + n + "!")

# 6
n = int(input())
print("The next number for the number " + str(n) + " is " + str(n + 1) + ".")
print("The previous number for the number " + str(n) + " is " + str(n - 1) + ".")

# 7
# прибавил + 1 к каждому классу
a = int(input())
b = int(input())
c = int(input())
print((a + 1) // 2 + (b + 1) // 2 + (c + 1) // 2)

# 8
# посчитал количество отрезков на картинке
a = int(input())
b = int(input())
l = int(input())
N = int(input())
print((l + N * a + (N - 1) * b) * 2 - a)